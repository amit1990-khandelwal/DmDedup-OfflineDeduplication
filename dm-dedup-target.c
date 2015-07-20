/*
 * Copyright (C) 2012-2014 Vasily Tarasov
 * Copyright (C) 2012-2014 Geoff Kuenning
 * Copyright (C) 2012-2014 Sonam Mandal
 * Copyright (C) 2012-2014 Karthikeyani Palanisami
 * Copyright (C) 2012-2014 Philip Shilane
 * Copyright (C) 2012-2014 Sagar Trehan
 * Copyright (C) 2012-2014 Erez Zadok
 *
 * This file is released under the GPL.
 */

#include <linux/vmalloc.h>

#include "dm-dedup-target.h"
#include "dm-dedup-rw.h"
#include "dm-dedup-hash.h"
#include "dm-dedup-backend.h"
#include "dm-dedup-ram.h"
#include "dm-dedup-cbt.h"
#include "dm-dedup-kvstore.h"
#include <linux/buffer_head.h>
#include <linux/kthread.h>
#include <linux/time.h>

#define MAX_DEV_NAME_LEN (64)

#define MIN_DATA_DEV_BLOCK_SIZE (4 * 1024)
#define MAX_DATA_DEV_BLOCK_SIZE (1024 * 1024)


struct on_disk_stats {
	uint64_t physical_block_counter;
	uint64_t logical_block_counter;
};

/*
 * All incoming requests are packed in the dedup_work structure
 * for further processing by the workqueue thread.
 */
struct dedup_work {
	struct work_struct worker;
	struct dedup_config *config;
	struct bio *bio;
};

enum backend {
	BKND_INRAM,
	BKND_COWBTREE
};

static void bio_zero_endio(struct bio *bio)
{
	zero_fill_bio(bio);
	bio_endio(bio, 0);
}

static uint64_t bio_lbn(struct dedup_config *dc, struct bio *bio)
{
	sector_t lbn = bio->bi_iter.bi_sector;

	sector_div(lbn, dc->sectors_per_block);

	return lbn;
}

static void do_io(struct dedup_config *dc, struct bio *bio, uint64_t pbn)
{
	int offset;

	offset = sector_div(bio->bi_iter.bi_sector, dc->sectors_per_block);
	bio->bi_iter.bi_sector = (sector_t)pbn * dc->sectors_per_block + offset;

	bio->bi_bdev = dc->data_dev->bdev;

	generic_make_request(bio);
}

static int handle_read(struct dedup_config *dc, struct bio *bio)
{
	uint64_t lbn;
	uint32_t vsize;
	struct lbn_pbn_value lbnpbn_value;
	int r;

	lbn = bio_lbn(dc, bio);

	r = dc->kvs_lbn_pbn->kvs_lookup(dc->kvs_lbn_pbn, (void *)&lbn,
			sizeof(lbn), (void *)&lbnpbn_value, &vsize);
	if (r == 0)
		bio_zero_endio(bio);
	else if (r == 1)
		do_io(dc, bio, lbnpbn_value.pbn);
	else
		return r;

	return 0;
}

static int allocate_block(struct dedup_config *dc, uint64_t *pbn_new)
{
	int r;

	r = dc->mdops->alloc_data_block(dc->bmd, pbn_new);

	if (!r) {
		dc->logical_block_counter++;
		dc->physical_block_counter++;
	}

	return r;
}

static int write_to_new_block(struct dedup_config *dc, uint64_t *pbn_new,
			      struct bio *bio, uint64_t lbn)
{
	int r = 0;
	struct lbn_pbn_value lbnpbn_value;
#ifdef OFFLINE_DEDUP_BITMAP
	uint64_t bmap_index;
	uint8_t indexed_bit;
#endif
	r = allocate_block(dc, pbn_new);
	if (r < 0) {
		r = -EIO;
		return r;
	}

	lbnpbn_value.pbn = *pbn_new;
	do_io(dc, bio, *pbn_new);

#ifdef OFFLINE_DEDUP_BITMAP
	bmap_index = lbn/8;
	indexed_bit = lbn%8;
	dc->bmap[bmap_index] |= 1<<indexed_bit;
#endif
	r = dc->kvs_lbn_pbn->kvs_insert(dc->kvs_lbn_pbn, (void *)&lbn,
		sizeof(lbn), (void *)&lbnpbn_value, sizeof(lbnpbn_value));
	if (r < 0)
		dc->mdops->dec_refcount(dc->bmd, *pbn_new);
	return r;
}

static int handle_write_nodedup(struct dedup_config *dc, struct bio *bio,
			     uint64_t lbn)
{
	int r, ret;
	uint32_t vsize;
	uint64_t pbn_new, pbn_old;
	struct lbn_pbn_value lbnpbn_value;

	r = dc->kvs_lbn_pbn->kvs_lookup(dc->kvs_lbn_pbn, (void *)&lbn, sizeof(lbn),
				(void *)&lbnpbn_value, &vsize);
	if (r == 0) {
		r = write_to_new_block(dc, &pbn_new, bio, lbn);
		goto out;
	} else if (r < 0)
		BUG();

	pbn_old = lbnpbn_value.pbn;

	r = write_to_new_block(dc, &pbn_new, bio, lbn);

	if (r < 0)
		goto out;
	ret = dc->mdops->dec_refcount(dc->bmd, pbn_old);
	if (ret < 0)
		BUG();

	dc->logical_block_counter--;

out:
	return r;
}

static int handle_write_no_hash(struct dedup_config *dc,
				struct bio *bio, uint64_t lbn, u8 *hash)
{
	int r;
	uint32_t vsize;
	uint64_t pbn_new, pbn_old;
	struct lbn_pbn_value lbnpbn_value;
	struct hash_pbn_value hashpbn_value;

	dc->uniqwrites++;

	r = dc->kvs_lbn_pbn->kvs_lookup(dc->kvs_lbn_pbn, (void *)&lbn,
			sizeof(lbn), (void *)&lbnpbn_value, &vsize);
	if (r == 0) {
		/* No LBN->PBN mapping entry */
		dc->newwrites++;
		r = write_to_new_block(dc, &pbn_new, bio, lbn);
		if (r < 0)
			goto out_write_new_block_1;

		hashpbn_value.pbn = pbn_new;

		r = dc->kvs_hash_pbn->kvs_insert(dc->kvs_hash_pbn, (void *)hash,
				dc->crypto_key_size, (void *)&hashpbn_value,
				sizeof(hashpbn_value));
		if (r < 0)
			goto out_kvs_insert_1;

		r = dc->mdops->inc_refcount(dc->bmd, pbn_new);
		if (r < 0)
			goto out_inc_refcount_1;

		goto out_1;

out_inc_refcount_1:
		dc->kvs_hash_pbn->kvs_delete(dc->kvs_hash_pbn,
				(void *)hash, dc->crypto_key_size);
out_kvs_insert_1:
		dc->kvs_lbn_pbn->kvs_delete(dc->kvs_lbn_pbn,
				(void *)&lbn, sizeof(lbn));
		dc->mdops->dec_refcount(dc->bmd, pbn_new);
out_write_new_block_1:
		dc->newwrites--;
out_1:
		if (r < 0)
			dc->uniqwrites--;
		return r;
	} else if (r < 0)
		goto out_2;

	/* LBN->PBN mappings exist */
	dc->overwrites++;
	r = write_to_new_block(dc, &pbn_new, bio, lbn);
	if (r < 0)
		goto out_write_new_block_2;

	pbn_old = lbnpbn_value.pbn;
	r = dc->mdops->dec_refcount(dc->bmd, pbn_old);
	if (r < 0)
		goto out_dec_refcount_2;

	dc->logical_block_counter--;

	hashpbn_value.pbn = pbn_new;

	r = dc->kvs_hash_pbn->kvs_insert(dc->kvs_hash_pbn, (void *)hash,
				dc->crypto_key_size, (void *)&hashpbn_value,
				sizeof(hashpbn_value));
	if (r < 0)
		goto out_kvs_insert_2;

	r = dc->mdops->inc_refcount(dc->bmd, pbn_new);
	if (r < 0)
		goto out_inc_refcount_2;

	goto out_2;

out_inc_refcount_2:
	dc->kvs_hash_pbn->kvs_delete(dc->kvs_hash_pbn,
			(void *)hash, dc->crypto_key_size);
out_kvs_insert_2:
	dc->logical_block_counter++;
	dc->mdops->inc_refcount(dc->bmd, pbn_old);
out_dec_refcount_2:
	dc->kvs_lbn_pbn->kvs_insert(dc->kvs_lbn_pbn, (void *)&lbn,
			sizeof(lbn), (void *)&lbnpbn_value,
			sizeof(lbnpbn_value));
	dc->mdops->dec_refcount(dc->bmd, pbn_new);
out_write_new_block_2:
	dc->overwrites--;
out_2:
	if (r < 0)
		dc->uniqwrites--;
	return r;
}

static int handle_write_with_hash(struct dedup_config *dc, struct bio *bio,
				  uint64_t lbn, u8 *final_hash,
				  struct hash_pbn_value hashpbn_value)
{
	int r;
	uint32_t vsize;
	uint64_t pbn_new, pbn_old;
	struct lbn_pbn_value lbnpbn_value;
	struct lbn_pbn_value new_lbnpbn_value;

	dc->dupwrites++;

	pbn_new = hashpbn_value.pbn;
	r = dc->kvs_lbn_pbn->kvs_lookup(dc->kvs_lbn_pbn, (void *)&lbn,
			sizeof(lbn), (void *)&lbnpbn_value, &vsize);
	if (r == 0) {
		/* No LBN->PBN mapping entry */
		dc->newwrites++;

		r = dc->mdops->inc_refcount(dc->bmd, pbn_new);
		if (r < 0)
			goto out_inc_refcount_1;

		lbnpbn_value.pbn = pbn_new;

		r = dc->kvs_lbn_pbn->kvs_insert(dc->kvs_lbn_pbn, (void *)&lbn,
				sizeof(lbn), (void *)&lbnpbn_value,
				sizeof(lbnpbn_value));
		if (r < 0)
			goto out_kvs_insert_1;

		dc->logical_block_counter++;

		goto out_1;

out_kvs_insert_1:
		dc->mdops->dec_refcount(dc->bmd, pbn_new);
out_inc_refcount_1:
		dc->newwrites--;
out_1:
		if (r >= 0)
			bio_endio(bio, 0);
		else
			dc->dupwrites--;
		return r;
	} else if (r < 0)
		goto out_2;

	/* LBN->PBN mapping entry exists */
	dc->overwrites++;
	pbn_old = lbnpbn_value.pbn;
	if (pbn_new != pbn_old) {
		r = dc->mdops->inc_refcount(dc->bmd, pbn_new);
		if (r < 0)
			goto out_inc_refcount_2;

		new_lbnpbn_value.pbn = pbn_new;

		r = dc->kvs_lbn_pbn->kvs_insert(dc->kvs_lbn_pbn, (void *)&lbn,
			sizeof(lbn), (void *)&new_lbnpbn_value,
			sizeof(new_lbnpbn_value));
		if (r < 0)
			goto out_kvs_insert_2;

		r = dc->mdops->dec_refcount(dc->bmd, pbn_old);
		if (r < 0)
			goto out_dec_refcount_2;
	}

	/* Nothing to do if writing same data to same LBN */
	goto out_2;

out_dec_refcount_2:
	dc->kvs_lbn_pbn->kvs_insert(dc->kvs_lbn_pbn, (void *)&lbn,
			sizeof(lbn), (void *)&lbnpbn_value,
			sizeof(lbnpbn_value));
out_kvs_insert_2:
	dc->mdops->dec_refcount(dc->bmd, pbn_new);
out_inc_refcount_2:
	dc->overwrites--;
out_2:
	if (r >= 0)
		bio_endio(bio, 0);
	else
		dc->dupwrites--;
	return r;
}

#ifdef OFFLINE_DEDUP_INCREMENTAL
static int handle_offline_dedup(struct dedup_config *dc, uint8_t is_full_dedup)
#else
static int handle_offline_dedup(struct dedup_config *dc)
#endif
{
	int r = 0;
	uint8_t hash[MAX_DIGEST_SIZE];
	uint32_t vsize;
	struct lbn_pbn_value lbnpbn_value;
	uint64_t lbn, pbn;
	struct hash_pbn_value curr_pbn, hash_pbn;
	struct buffer_head *bh;
	struct bio *bio;
#ifdef OFFLINE_DEDUP_INCREMENTAL
	uint64_t end_range;
#endif
#ifdef OFFLINE_DEDUP_BITMAP
	uint64_t bmap_index;
	uint8_t indexed_bit;
#endif

	dc->dedup_blocks = 0;

#ifdef OFFLINE_DEDUP_INCREMENTAL
	if (is_full_dedup) {
		dc->lbn_crawler = 0;
		end_range = dc->pblocks;
	} else {
		if (dc->lbn_crawler + (dc->pblocks / 10) > dc->pblocks)
			end_range = dc->pblocks;
		else
			end_range = dc->lbn_crawler + (dc->pblocks/10);
	}
#endif

#ifdef OFFLINE_DEDUP_INCREMENTAL
	for (; dc->lbn_crawler < end_range; dc->lbn_crawler++) {
		lbn = dc->lbn_crawler;
#else
	for (lbn = 0; lbn < dc->pblocks; lbn++) {
#endif

#ifdef OFFLINE_DEDUP_BITMAP
		bmap_index = lbn/8;
		indexed_bit = lbn%8;
		if (((dc->bmap[bmap_index]>>indexed_bit) & 1) == 0)
			continue;
#endif
		r = dc->kvs_lbn_pbn->kvs_lookup(dc->kvs_lbn_pbn, (void *)&lbn,
						sizeof(lbn), (void *)&lbnpbn_value, &vsize);
		if (r == 1) {
			pbn = lbnpbn_value.pbn;
			bh = __bread(dc->data_dev->bdev, pbn, dc->block_size);
			bio = bio_alloc(GFP_NOIO, 1);
			bio->bi_iter.bi_sector = lbn *  dc->sectors_per_block;
			bio->bi_bdev = bh->b_bdev;
			bio->bi_io_vec[0].bv_page = bh->b_page;
			bio->bi_io_vec[0].bv_len = bh->b_size;
			bio->bi_io_vec[0].bv_offset = bh_offset(bh);
			bio->bi_vcnt = 1;
			bio->bi_iter.bi_size = bh->b_size;
			bio->bi_rw = READ;
			bio->bi_private = bh;
			bio->bi_flags |= 0;
			bio_get(bio);
			do_io(dc, bio, pbn);
			r = compute_hash_bio(dc->desc_table, bio, hash);
			if (r)
					return r;

			bio_put(bio);

			r = dc->kvs_hash_pbn->kvs_lookup(dc->kvs_hash_pbn, hash,
				 dc->crypto_key_size, &hash_pbn, &vsize);
			curr_pbn.pbn = pbn;
			if (r == 0) {
				r = dc->kvs_hash_pbn->kvs_insert(dc->kvs_hash_pbn, (void *)hash,
					 dc->crypto_key_size, (void *)&curr_pbn,
					 sizeof(curr_pbn));
				if (r < 0)
					return r;
				r = dc->mdops->inc_refcount(dc->bmd, curr_pbn.pbn);
				if (r < 0) {
					dc->kvs_hash_pbn->kvs_delete(dc->kvs_hash_pbn,
						(void *)hash, dc->crypto_key_size);
					return r;
				}
			} else if (r > 0) {
				if (hash_pbn.pbn != curr_pbn.pbn) {
					r = dc->kvs_lbn_pbn->kvs_delete(dc->kvs_lbn_pbn,
						 (void *)&lbn, sizeof(lbn));
					if (r < 0)
						return r;
					r = dc->mdops->dec_refcount(dc->bmd, curr_pbn.pbn);
					r = dc->kvs_lbn_pbn->kvs_insert(dc->kvs_lbn_pbn, (void *)&lbn,
							sizeof(lbn), (void *)&hash_pbn,
							sizeof(hash_pbn));
					if (r < 0) {
						dc->mdops->inc_refcount(dc->bmd, curr_pbn.pbn);
						dc->kvs_lbn_pbn->kvs_insert(dc->kvs_lbn_pbn, (void *)&lbn,
													sizeof(lbn), (void *)&curr_pbn,
													sizeof(curr_pbn));
						return r;
					}
					r = dc->mdops->inc_refcount(dc->bmd, hash_pbn.pbn);
					if (r < 0) {
						
						dc->kvs_lbn_pbn->kvs_delete(dc->kvs_lbn_pbn,
												  (void *)&lbn, sizeof(lbn));
						dc->mdops->inc_refcount(dc->bmd, curr_pbn.pbn);
						dc->kvs_lbn_pbn->kvs_insert(dc->kvs_lbn_pbn, (void *)&lbn,
												   sizeof(lbn), (void *)&curr_pbn,
												   sizeof(curr_pbn));
						return r;
					}
					dc->dedup_blocks++;
					dc->total_dedup_blocks++;
				}
			} else if (r < 0)
				return r;
		} else if (r < 0)
			return r;
#ifdef OFFLINE_DEDUP_BITMAP
		dc->bmap[bmap_index] &= ~(1<<indexed_bit);
#endif
	}
#ifdef OFFLINE_DEDUP_INCREMENTAL
	dc->lbn_crawler = dc->lbn_crawler % dc->pblocks;
#endif
	dc->nodedup_writes = 0;
	return r;
}

static int offline_dedup_fn(void *arg)
{
	int r = 0;
	struct dedup_config *dc = (struct dedup_config *)arg;

	while (!kthread_should_stop()) {
		if (dc->nodedup_writes > MIN_DEDUP_WRITES_FOR_DEDUP)
#ifdef OFFLINE_DEDUP_INCREMENTAL
			r = handle_offline_dedup(dc, false);
#else
			r = handle_offline_dedup(dc);
#endif
			if (r < 0)
				BUG();
		if (kthread_should_stop())
			break;
		ssleep(900);
	}
	return 0;
}

static int handle_write(struct dedup_config *dc, struct bio *bio)
{
	uint64_t lbn;
	u8 hash[MAX_DIGEST_SIZE];
	struct hash_pbn_value hashpbn_value;
	uint32_t vsize;
	struct bio *new_bio = NULL;
	int r;

	dc->writes++;

	/* Read-on-write handling */
	if (bio->bi_iter.bi_size < dc->block_size) {
		dc->reads_on_writes++;
		new_bio = prepare_bio_on_write(dc, bio);
		if (!new_bio || IS_ERR(new_bio))
			return -ENOMEM;
		bio = new_bio;
	}

	lbn = bio_lbn(dc, bio);

	if (bio_flagged(bio, BIO_NO_DEDUP)) {
		dc->nodedup_writes++;
		(void)handle_write_nodedup(dc, bio, lbn);
		goto flush;
	}

	r = compute_hash_bio(dc->desc_table, bio, hash);
	if (r)
		return r;

	r = dc->kvs_hash_pbn->kvs_lookup(dc->kvs_hash_pbn, hash,
				dc->crypto_key_size, &hashpbn_value, &vsize);

	if (r == 0)
		r = handle_write_no_hash(dc, bio, lbn, hash);
	else if (r > 0)
		r = handle_write_with_hash(dc, bio, lbn, hash,
					hashpbn_value);

	if (r < 0)
		return r;
flush:
	dc->writes_after_flush++;
	if ((dc->flushrq && dc->writes_after_flush >= dc->flushrq) ||
			(bio->bi_rw & (REQ_FLUSH | REQ_FUA))) {
		r = dc->mdops->flush_meta(dc->bmd);
		if (r < 0)
			return r;
		dc->writes_after_flush = 0;
	}

	return 0;
}

static void process_bio(struct dedup_config *dc, struct bio *bio)
{
	int r;

	switch (bio_data_dir(bio)) {
	case READ:
		r = handle_read(dc, bio);
		break;
	case WRITE:
		r = handle_write(dc, bio);
	}

	if (r < 0)
		bio_endio(bio, r);
}

static void do_work(struct work_struct *ws)
{
	struct dedup_work *data = container_of(ws, struct dedup_work, worker);
	struct dedup_config *dc = (struct dedup_config *)data->config;
	struct bio *bio = (struct bio *)data->bio;

	mempool_free(data, dc->dedup_work_pool);

	process_bio(dc, bio);
}

static void set_nodedup_flag(struct dedup_config *dc, struct bio *bio)
{
	if (dc->nodedup_all)
		bio->bi_flags |= (1 << BIO_NO_DEDUP);
}

static void dedup_defer_bio(struct dedup_config *dc, struct bio *bio)
{
	struct dedup_work *data;

	data = mempool_alloc(dc->dedup_work_pool, GFP_NOIO);
	if (!data) {
		bio_endio(bio, -ENOMEM);
		return;
	}

	set_nodedup_flag(dc, bio);

	data->bio = bio;
	data->config = dc;

	INIT_WORK(&(data->worker), do_work);

	queue_work(dc->workqueue, &(data->worker));
}

static int dm_dedup_map(struct dm_target *ti, struct bio *bio)
{
	dedup_defer_bio(ti->private, bio);

	return DM_MAPIO_SUBMITTED;
}

struct dedup_args {
	struct dm_target *ti;

	struct dm_dev *meta_dev;

	struct dm_dev *data_dev;
	uint64_t data_size;

	uint32_t block_size;

	char hash_algo[CRYPTO_ALG_NAME_LEN];

	enum backend backend;
	char backend_str[MAX_BACKEND_NAME_LEN];

	uint32_t flushrq;

	int nodedup_all;
};

static int parse_nodedup_hint_all(struct dedup_args *da, struct dm_arg_set *as,
				char **err)
{
	if (kstrtoint(dm_shift_arg(as), 10, &da->nodedup_all) ||
		(da->nodedup_all != 0 && da->nodedup_all != 1)) {
		*err = "Invalid value for nodedup all hint";
		return -EINVAL;
	}

	return 0;
}

static int parse_meta_dev(struct dedup_args *da, struct dm_arg_set *as,
			  char **err)
{
	int r;

	r = dm_get_device(da->ti, dm_shift_arg(as),
			dm_table_get_mode(da->ti->table), &da->meta_dev);
	if (r)
		*err = "Error opening metadata device";

	return r;
}

static int parse_data_dev(struct dedup_args *da, struct dm_arg_set *as,
			  char **err)
{
	int r;

	r = dm_get_device(da->ti, dm_shift_arg(as),
			dm_table_get_mode(da->ti->table), &da->data_dev);
	if (r)
		*err = "Error opening data device";

	da->data_size = i_size_read(da->data_dev->bdev->bd_inode);

	return r;
}

static int parse_block_size(struct dedup_args *da, struct dm_arg_set *as,
			    char **err)
{
	uint32_t block_size;

	if (kstrtou32(dm_shift_arg(as), 10, &block_size) ||
		!block_size ||
		block_size < MIN_DATA_DEV_BLOCK_SIZE ||
		block_size > MAX_DATA_DEV_BLOCK_SIZE ||
		!is_power_of_2(block_size)) {
		*err = "Invalid data block size";
		return -EINVAL;
	}

	if (block_size > da->data_size) {
		*err = "Data block size is larger than the data device";
		return -EINVAL;
	}

	da->block_size = block_size;

	return 0;
}

static int parse_hash_algo(struct dedup_args *da, struct dm_arg_set *as,
			   char **err)
{
	strlcpy(da->hash_algo, dm_shift_arg(as), CRYPTO_ALG_NAME_LEN);

	if (!crypto_has_hash(da->hash_algo, 0, CRYPTO_ALG_ASYNC)) {
		*err = "Unrecognized hash algorithm";
		return -EINVAL;
	}

	return 0;
}

static int parse_backend(struct dedup_args *da, struct dm_arg_set *as,
			 char **err)
{
	char backend[MAX_BACKEND_NAME_LEN];

	strlcpy(backend, dm_shift_arg(as), MAX_BACKEND_NAME_LEN);

	if (!strcmp(backend, "inram"))
		da->backend = BKND_INRAM;
	else if (!strcmp(backend, "cowbtree"))
		da->backend = BKND_COWBTREE;
	else {
		*err = "Unsupported metadata backend";
		return -EINVAL;
	}

	strlcpy(da->backend_str, backend, MAX_BACKEND_NAME_LEN);

	return 0;
}

static int parse_flushrq(struct dedup_args *da, struct dm_arg_set *as,
			 char **err)
{
	if (kstrtou32(dm_shift_arg(as), 10, &da->flushrq))
		return -EINVAL;

	return 0;
}

static int parse_dedup_args(struct dedup_args *da, int argc,
			    char **argv, char **err)
{
	struct dm_arg_set as;
	int r;

	if (argc < 7) {
		*err = "Insufficient args";
		return -EINVAL;
	}

	if (argc > 7) {
		*err = "Too many args";
		return -EINVAL;
	}

	as.argc = argc;
	as.argv = argv;

	r = parse_meta_dev(da, &as, err);
	if (r)
		return r;

	r = parse_data_dev(da, &as, err);
	if (r)
		return r;

	r = parse_block_size(da, &as, err);
	if (r)
		return r;

	r = parse_hash_algo(da, &as, err);
	if (r)
		return r;

	r = parse_backend(da, &as, err);
	if (r)
		return r;

	r = parse_flushrq(da, &as, err);
	if (r)
		return r;

	r = parse_nodedup_hint_all(da, &as, err);
	if (r)
		return r;

	return 0;
}

static void destroy_dedup_args(struct dedup_args *da)
{
	if (da->meta_dev)
		dm_put_device(da->ti, da->meta_dev);

	if (da->data_dev)
		dm_put_device(da->ti, da->data_dev);
}

static int dm_dedup_ctr(struct dm_target *ti, unsigned int argc, char **argv)
{
	struct dedup_args da;
	struct dedup_config *dc;
	struct workqueue_struct *wq;

	struct init_param_inram iparam_inram;
	struct init_param_cowbtree iparam_cowbtree;
	void *iparam = NULL;
	struct metadata *md = NULL;

	sector_t data_size;
	int r;
	int crypto_key_size;

	struct on_disk_stats *data = NULL;
	uint64_t logical_block_counter = 0;
	uint64_t physical_block_counter = 0;

	mempool_t *dedup_work_pool = NULL;
	bool unformatted;
#ifdef OFFLINE_DEDUP_BITMAP
	uint64_t bmap_size;
#endif



	memset(&da, 0, sizeof(struct dedup_args));
	da.ti = ti;

	r = parse_dedup_args(&da, argc, argv, &ti->error);
	if (r)
		goto out;

	dc = kzalloc(sizeof(*dc), GFP_KERNEL);
	if (!dc) {
		ti->error = "Error allocating memory for dedup config";
		r = -ENOMEM;
		goto out;
	}

	wq = create_singlethread_workqueue("dm-dedup");
	if (!wq) {
		ti->error = "failed to create workqueue";
		r = -ENOMEM;
		goto bad_wq;
	}

	dedup_work_pool = mempool_create_kmalloc_pool(MIN_DEDUP_WORK_IO,
						sizeof(struct dedup_work));
	if (!dedup_work_pool) {
		r = -ENOMEM;
		ti->error = "failed to create mempool";
		goto bad_mempool;
	}

	dc->io_client = dm_io_client_create();
	if (IS_ERR(dc->io_client)) {
		r = PTR_ERR(dc->io_client);
		ti->error = "failed to create dm_io_client";
		goto bad_io_client;
	}

	dc->block_size = da.block_size;
	dc->sectors_per_block = to_sector(da.block_size);
	data_size = ti->len;
	(void) sector_div(data_size, dc->sectors_per_block);
	dc->lblocks = data_size;

	data_size = i_size_read(da.data_dev->bdev->bd_inode) >> SECTOR_SHIFT;
	(void) sector_div(data_size, dc->sectors_per_block);
	dc->pblocks = data_size;

	/* Meta-data backend specific part */
	switch (da.backend) {
	case BKND_INRAM:
		dc->mdops = &metadata_ops_inram;
		iparam_inram.blocks = dc->pblocks;
		iparam = &iparam_inram;
		break;
	case BKND_COWBTREE:
		dc->mdops = &metadata_ops_cowbtree;
		iparam_cowbtree.blocks = dc->pblocks;
		iparam_cowbtree.metadata_bdev = da.meta_dev->bdev;
		iparam = &iparam_cowbtree;
	}

	strcpy(dc->backend_str, da.backend_str);

	md = dc->mdops->init_meta(iparam, &unformatted);
	if (IS_ERR(md)) {
		ti->error = "failed to initialize backend metadata";
		r = PTR_ERR(md);
		goto bad_metadata_init;
	}

	dc->desc_table = desc_table_init(da.hash_algo);
	if (!dc->desc_table || IS_ERR(dc->desc_table)) {
		ti->error = "failed to initialize crypto API";
		r = PTR_ERR(dc->desc_table);
		goto bad_metadata_init;
	}

	crypto_key_size = get_hash_digestsize(dc->desc_table);

	dc->kvs_hash_pbn = dc->mdops->kvs_create_sparse(md, crypto_key_size,
				sizeof(struct hash_pbn_value),
				dc->pblocks, unformatted);
	if (IS_ERR(dc->kvs_hash_pbn)) {
		r = PTR_ERR(dc->kvs_hash_pbn);
		ti->error = "failed to create sparse KVS";
		goto bad_kvstore_init;
	}

	dc->kvs_lbn_pbn = dc->mdops->kvs_create_linear(md, 8,
			sizeof(struct lbn_pbn_value), dc->lblocks, unformatted);
	if (IS_ERR(dc->kvs_lbn_pbn)) {
		ti->error = "failed to create linear KVS";
		r = PTR_ERR(dc->kvs_lbn_pbn);
		goto bad_kvstore_init;
	}

	r = dc->mdops->flush_meta(md);
	if (r < 0) {
		ti->error = "failed to flush metadata";
		goto bad_kvstore_init;
	}

	if (!unformatted && dc->mdops->get_private_data) {
		r = dc->mdops->get_private_data(md, (void **)&data,
				sizeof(struct on_disk_stats));
		if (r < 0) {
			ti->error = "failed to get private data from superblock";
			goto bad_kvstore_init;
		}

		logical_block_counter = data->logical_block_counter;
		physical_block_counter = data->physical_block_counter;
	}

	dc->data_dev = da.data_dev;
	dc->metadata_dev = da.meta_dev;

	dc->workqueue = wq;
	dc->dedup_work_pool = dedup_work_pool;
	dc->bmd = md;

	dc->nodedup_all = da.nodedup_all;

	dc->logical_block_counter = logical_block_counter;
	dc->physical_block_counter = physical_block_counter;

	dc->writes = 0;
	dc->dupwrites = 0;
	dc->uniqwrites = 0;
	dc->reads_on_writes = 0;
	dc->overwrites = 0;
	dc->newwrites = 0;
	dc->nodedup_writes = 0;
	dc->total_dedup_blocks = 0;
	dc->dedup_blocks = 0;

	strcpy(dc->crypto_alg, da.hash_algo);
	dc->crypto_key_size = crypto_key_size;

	dc->flushrq = da.flushrq;
	dc->writes_after_flush = 0;

	r = dm_set_target_max_io_len(ti, dc->sectors_per_block);
	if (r)
		goto bad_kvstore_init;

	ti->private = dc;

#ifdef OFFLINE_DEDUP_BITMAP
	bmap_size = (dc->pblocks * sizeof(uint8_t)) / 8 + sizeof(uint8_t);
	dc->bmap = vmalloc(bmap_size);
	if (!dc->bmap) {
		printk(KERN_ALERT" bmap memory allocation failed");
		r = -ENOMEM;
		goto bad_bmap;
	}
	memset(dc->bmap, 0, bmap_size);
#endif
	if (dc->nodedup_all) {
		dc->thread = kthread_create(offline_dedup_fn, dc, "offline_mydedup");
		if (IS_ERR(dc->thread)) {
			printk(KERN_ALERT" offline worker thread creation failed");
			goto thread_err;
		}
		set_user_nice(dc->thread, MAX_NICE);
		wake_up_process(dc->thread);
	}
	return 0;

thread_err:
	kthread_stop(dc->thread);

#ifdef OFFLINE_DEDUP_BITMAP
bad_bmap:
	vfree(dc->bmap);
#endif

bad_kvstore_init:
	desc_table_deinit(dc->desc_table);
bad_metadata_init:
	if (md && !IS_ERR(md))
		dc->mdops->exit_meta(md);
	dm_io_client_destroy(dc->io_client);
bad_io_client:
	mempool_destroy(dedup_work_pool);
bad_mempool:
	destroy_workqueue(wq);
bad_wq:
	kfree(dc);
out:
	destroy_dedup_args(&da);
	return r;
}

static void dm_dedup_dtr(struct dm_target *ti)
{
	struct dedup_config *dc = ti->private;
	struct on_disk_stats data;
	int ret;

	if (dc->mdops->set_private_data) {
		data.physical_block_counter = dc->physical_block_counter;
		data.logical_block_counter = dc->logical_block_counter;

		ret = dc->mdops->set_private_data(dc->bmd, &data,
				sizeof(struct on_disk_stats));
		if (ret < 0)
			DMERR("Failed to set the private data in superblock.");
	}

	ret = dc->mdops->flush_meta(dc->bmd);
	if (ret < 0)
		DMERR("Failed to flush the metadata to disk.");

	flush_workqueue(dc->workqueue);
	destroy_workqueue(dc->workqueue);

	mempool_destroy(dc->dedup_work_pool);

	dc->mdops->exit_meta(dc->bmd);

	dm_io_client_destroy(dc->io_client);

	dm_put_device(ti, dc->data_dev);
	dm_put_device(ti, dc->metadata_dev);
	desc_table_deinit(dc->desc_table);
#ifdef OFFLINE_DEDUP_BITMAP
	if (dc->bmap)
		vfree(dc->bmap);
#endif
	if (!IS_ERR_OR_NULL(dc->thread))
		kthread_stop(dc->thread);

	kfree(dc);
}

static void dm_dedup_status(struct dm_target *ti, status_type_t status_type,
			    unsigned status_flags, char *result, unsigned maxlen)
{
	struct dedup_config *dc = ti->private;
	uint64_t data_total_block_count;
	uint64_t data_used_block_count;
	uint64_t data_free_block_count;
	uint64_t data_actual_block_count;
	int sz = 0;

	switch (status_type) {
	case STATUSTYPE_INFO:
		data_used_block_count = dc->physical_block_counter;
		data_actual_block_count = dc->logical_block_counter;
		data_total_block_count = dc->pblocks;

		data_free_block_count =
			data_total_block_count - data_used_block_count;

		DMEMIT("\nTotal blocks: %llu \nTotal Free blocks: %llu \nTotal Used blocks: %llu \nActual block count: %llu ",
                        data_total_block_count, data_free_block_count,
                        data_used_block_count, data_actual_block_count);

    	DMEMIT("\nBlock size: %u \nData Device Name: %s \nMetadata Device Name: %s ", dc->block_size,
                        dc->data_dev->name, dc->metadata_dev->name);

    	DMEMIT("\nTotal Writes: %llu \nTotal Unique Writes: %llu \nTotal Duplicate Writes: %llu \nReads on Writes: %llu \nOverwrites: %llu \nNew Writes: %llu",
                        dc->writes, dc->uniqwrites, dc->dupwrites,
                        dc->reads_on_writes, dc->overwrites, dc->newwrites);
        if(dc->nodedup_all)
        	DMEMIT("\nNoDedup Writes: %llu \nDeduplicate Write in last Iteration: %llu \nTotal Dedup Writes: %llu",
                                  dc->nodedup_writes, dc->dedup_blocks, dc->total_dedup_blocks);
		break;
	case STATUSTYPE_TABLE:
		DMEMIT("%s %s %u %s %s %u",
			dc->metadata_dev->name, dc->data_dev->name, dc->block_size,
			dc->crypto_alg, dc->backend_str, dc->flushrq);
	}
}

static int cleanup_hash_pbn(void *key, int32_t ksize, void *value,
			    int32_t vsize, void *data)
{
	int r = 0;
	uint64_t pbn_val = 0;
	struct hash_pbn_value hashpbn_value = *((struct hash_pbn_value *)value);
	struct dedup_config *dc = (struct dedup_config *)data;

	BUG_ON(!data);

	pbn_val = hashpbn_value.pbn;

	if (dc->mdops->get_refcount(dc->bmd, pbn_val) == 1) {
		r = dc->kvs_hash_pbn->kvs_delete(dc->kvs_hash_pbn,
							key, ksize);
		if (r < 0)
			goto out;

		r = dc->mdops->dec_refcount(dc->bmd, pbn_val);
		if (r < 0)
			goto out_dec_refcount;

		dc->physical_block_counter -= 1;
	}

	goto out;

out_dec_refcount:
	dc->kvs_hash_pbn->kvs_insert(dc->kvs_hash_pbn, key,
			ksize, (void *)&hashpbn_value,
			sizeof(hashpbn_value));
out:
	return r;
}

static int garbage_collect(struct dedup_config *dc)
{
	int err = 0;

	BUG_ON(!dc);

	/* Cleanup hashes if the refcount of block == 1 */
	err = dc->kvs_hash_pbn->kvs_iterate(dc->kvs_hash_pbn,
			&cleanup_hash_pbn, (void *)dc);

	return err;
}

static int dm_dedup_message(struct dm_target *ti,
			    unsigned argc, char **argv)
{
	int r = 0;

	struct dedup_config *dc = ti->private;

	if (!strcasecmp(argv[0], "garbage_collect")) {
		r = garbage_collect(dc);
		if (r < 0)
			DMERR("Error in performing garbage_collect: %d.", r);
	} else if (!strcasecmp(argv[0], "drop_bufio_cache")) {
		if (dc->mdops->flush_bufio_cache)
			dc->mdops->flush_bufio_cache(dc->bmd);
		else
			r = -ENOTSUPP;
	} else if (!strcasecmp(argv[0], "offline_dedup")) {
#ifdef OFFLINE_DEDUP_INCREMENTAL
		if (!strcasecmp(argv[1], "full"))
			r = handle_offline_dedup(dc, true);
		else if (!strcasecmp(argv[1], "incr"))
			r = handle_offline_dedup(dc, false);
		else
			DMERR("Incorrect option. Please give either 'full' or 'incr' as offline_dedup <option> ");
#else
		r = handle_offline_dedup(dc);
#endif
		if (r < 0)
			DMERR("Error in performing offline deduplication : %d", r);
	} else
		r = -EINVAL;

	return r;
}

static int dm_dedup_endio(struct dm_target *ti, struct bio *bio, int error)
{
	if (error || bio_data_dir(bio) != READ)
		return 0;

	return 0;
}

static struct target_type dm_dedup_target = {
	.name = "dedup",
	.version = {1, 0, 0},
	.module = THIS_MODULE,
	.ctr = dm_dedup_ctr,
	.dtr = dm_dedup_dtr,
	.map = dm_dedup_map,
	.end_io = dm_dedup_endio,
	.message = dm_dedup_message,
	.status = dm_dedup_status,
};

static int __init dm_dedup_init(void)
{
	int r;

	r = dm_register_target(&dm_dedup_target);
	if (r)
		return r;

	return 0;
}

static void __exit dm_dedup_exit(void)
{
	dm_unregister_target(&dm_dedup_target);
}

module_init(dm_dedup_init);
module_exit(dm_dedup_exit);

MODULE_DESCRIPTION(DM_NAME " target for data deduplication");
MODULE_LICENSE("GPL");
