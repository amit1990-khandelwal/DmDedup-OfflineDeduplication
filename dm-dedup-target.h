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

#ifndef DM_DEDUP_H
#define DM_DEDUP_H

#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/device-mapper.h>
#include <linux/dm-io.h>
#include <linux/dm-kcopyd.h>
#include <linux/list.h>
#include <linux/err.h>
#include <asm/current.h>
#include <linux/string.h>
#include <linux/gfp.h>
#include <linux/delay.h>
#include <linux/time.h>
#include <linux/parser.h>
#include <linux/blk_types.h>
#include <linux/mempool.h>

#include <linux/scatterlist.h>
#include <asm/page.h>
#include <asm/unaligned.h>
#include <crypto/hash.h>
#include <crypto/md5.h>
#include <crypto/sha.h>
#include <crypto/algapi.h>

#define DM_MSG_PREFIX "dedup-mod"

#define CRYPTO_ALG_NAME_LEN     16
#define MAX_DIGEST_SIZE	SHA256_DIGEST_SIZE

#define MAX_BACKEND_NAME_LEN (64)

#define MIN_DEDUP_WORK_IO	16
#define MIN_DEDUP_WRITES_FOR_DEDUP 1000

//#define OFFLINE_DEDUP_INCREMENTAL
#define OFFLINE_DEDUP_BITMAP

/* Per target instance structure */
struct dedup_config {
	struct dm_dev *data_dev;
	struct dm_dev *metadata_dev;

	uint32_t block_size;	/* in bytes */
	uint32_t sectors_per_block;

	uint32_t pblocks;	/* physical blocks */
	uint32_t lblocks;	/* logical blocks */

	struct workqueue_struct *workqueue;

	struct hash_desc_table *desc_table;

	uint64_t logical_block_counter;	/* Total number of used LBNs */
	uint64_t physical_block_counter;/* Total number of allocated PBNs */

	uint64_t	writes;		/* total number of writes */
	uint64_t	dupwrites;
	uint64_t	uniqwrites;
	uint64_t	reads_on_writes;
	uint64_t	overwrites;	/* writes to a prev. written offset */
	uint64_t	newwrites;	/* writes to never written offsets */
	uint64_t	nodedup_writes;	/* writes which aren't deduplicated */
	uint64_t	total_dedup_blocks;	/* total blocks deduplicated
						in offline deduplication */
	uint64_t	dedup_blocks;	/* blocks deduplicated in one offline
					deduplication iteration */
#ifdef OFFLINE_DEDUP_INCREMENTAL
	uint64_t	lbn_crawler;
#endif

	int		nodedup_all;	/* Enable nodedup hint for all writes */
	struct task_struct *thread;	/* background thread for running
					offline deduplication periodically */
#ifdef OFFLINE_DEDUP_BITMAP
	uint8_t		*bmap;
#endif

	struct dm_io_client *io_client;		/* used for read-on-write
						of misaligned requests */
	char backend_str[MAX_BACKEND_NAME_LEN];
	struct metadata_ops *mdops;
	struct metadata *bmd;
	struct kvstore *kvs_hash_pbn;
	struct kvstore *kvs_lbn_pbn;

	char crypto_alg[CRYPTO_ALG_NAME_LEN];
	int crypto_key_size;

	uint32_t flushrq;		/* after how many writes call flush */
	uint64_t writes_after_flush;	/* # of writes after the last flush */

	mempool_t *dedup_work_pool;	/* Dedup work pool */
};

/* Value of the HASH-PBN key-value store */
struct hash_pbn_value {
	uint64_t pbn;	/* in blocks */
};

/* Value of the LBN-PBN key-value store */
struct lbn_pbn_value {
	uint64_t pbn;	/* in blocks */
};

#endif /* DM_DEDUP_H */
