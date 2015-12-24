#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

__visible struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

MODULE_INFO(intree, "Y");

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x8b325cc0, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0x827a42f4, __VMLINUX_SYMBOL_STR(dm_tm_open_with_sm) },
	{ 0x543b4234, __VMLINUX_SYMBOL_STR(alloc_pages_current) },
	{ 0x153e70d9, __VMLINUX_SYMBOL_STR(fs_bio_set) },
	{ 0x4ca4f9d8, __VMLINUX_SYMBOL_STR(kmalloc_caches) },
	{ 0xd2b09ce5, __VMLINUX_SYMBOL_STR(__kmalloc) },
	{ 0xc897c382, __VMLINUX_SYMBOL_STR(sg_init_table) },
	{ 0xb7bad799, __VMLINUX_SYMBOL_STR(dm_bm_unlock) },
	{ 0x96d19383, __VMLINUX_SYMBOL_STR(__bread) },
	{ 0x3d69f5a0, __VMLINUX_SYMBOL_STR(bio_alloc_bioset) },
	{ 0xed1e1f96, __VMLINUX_SYMBOL_STR(dm_btree_remove) },
	{ 0xd6ee688f, __VMLINUX_SYMBOL_STR(vmalloc) },
	{ 0xf92d9198, __VMLINUX_SYMBOL_STR(dm_get_device) },
	{ 0x2b5a58a3, __VMLINUX_SYMBOL_STR(dm_io) },
	{ 0x43a53735, __VMLINUX_SYMBOL_STR(__alloc_workqueue_key) },
	{ 0x6d0f1f89, __VMLINUX_SYMBOL_STR(dm_table_get_mode) },
	{ 0x688d422d, __VMLINUX_SYMBOL_STR(dm_bm_block_size) },
	{ 0xefba93e1, __VMLINUX_SYMBOL_STR(mempool_destroy) },
	{ 0x999e8297, __VMLINUX_SYMBOL_STR(vfree) },
	{ 0x6b76d57e, __VMLINUX_SYMBOL_STR(dm_register_target) },
	{ 0xd163cade, __VMLINUX_SYMBOL_STR(dm_tm_commit) },
	{ 0x9f624559, __VMLINUX_SYMBOL_STR(dm_sm_disk_open) },
	{ 0x9e4faeef, __VMLINUX_SYMBOL_STR(dm_io_client_destroy) },
	{ 0xaee02382, __VMLINUX_SYMBOL_STR(dm_btree_empty) },
	{ 0xfb578fc5, __VMLINUX_SYMBOL_STR(memset) },
	{ 0x72319cdd, __VMLINUX_SYMBOL_STR(dm_set_target_max_io_len) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0x449ad0a7, __VMLINUX_SYMBOL_STR(memcmp) },
	{ 0x72289260, __VMLINUX_SYMBOL_STR(dm_block_manager_destroy) },
	{ 0xd14e5bc6, __VMLINUX_SYMBOL_STR(bio_add_page) },
	{ 0xcde055a1, __VMLINUX_SYMBOL_STR(dm_unregister_target) },
	{ 0xaafdc258, __VMLINUX_SYMBOL_STR(strcasecmp) },
	{ 0x5eb24829, __VMLINUX_SYMBOL_STR(dm_shift_arg) },
	{ 0x5792f848, __VMLINUX_SYMBOL_STR(strlcpy) },
	{ 0xf375d009, __VMLINUX_SYMBOL_STR(dm_bm_write_lock) },
	{ 0x5e6aea80, __VMLINUX_SYMBOL_STR(dm_btree_walk) },
	{ 0x8c03d20c, __VMLINUX_SYMBOL_STR(destroy_workqueue) },
	{ 0x4a479984, __VMLINUX_SYMBOL_STR(generic_make_request) },
	{ 0x2276db98, __VMLINUX_SYMBOL_STR(kstrtoint) },
	{ 0x42160169, __VMLINUX_SYMBOL_STR(flush_workqueue) },
	{ 0x9b52dd2d, __VMLINUX_SYMBOL_STR(bio_endio) },
	{ 0x4f0c3029, __VMLINUX_SYMBOL_STR(bio_put) },
	{ 0x7ade1071, __VMLINUX_SYMBOL_STR(dm_tm_destroy) },
	{ 0x966a8838, __VMLINUX_SYMBOL_STR(dm_btree_lookup) },
	{ 0xafeda29f, __VMLINUX_SYMBOL_STR(dm_bm_write_lock_zero) },
	{ 0xe9dff136, __VMLINUX_SYMBOL_STR(mempool_alloc) },
	{ 0x49b35849, __VMLINUX_SYMBOL_STR(dm_sm_disk_create) },
	{ 0x55b4bd4d, __VMLINUX_SYMBOL_STR(dm_tm_create_with_sm) },
	{ 0xf5455120, __VMLINUX_SYMBOL_STR(dm_bm_read_lock) },
	{ 0x89f1e1cc, __VMLINUX_SYMBOL_STR(dm_btree_insert_notify) },
	{ 0x3f71faa1, __VMLINUX_SYMBOL_STR(mempool_create) },
	{ 0x6a037cf1, __VMLINUX_SYMBOL_STR(mempool_kfree) },
	{ 0x18489876, __VMLINUX_SYMBOL_STR(crypto_destroy_tfm) },
	{ 0xbdfb6dbb, __VMLINUX_SYMBOL_STR(__fentry__) },
	{ 0xeddb98c1, __VMLINUX_SYMBOL_STR(kmem_cache_alloc_trace) },
	{ 0x4aad52d7, __VMLINUX_SYMBOL_STR(mempool_free) },
	{ 0x4302d0eb, __VMLINUX_SYMBOL_STR(free_pages) },
	{ 0x54f69d, __VMLINUX_SYMBOL_STR(dm_tm_pre_commit) },
	{ 0x601f665f, __VMLINUX_SYMBOL_STR(dm_io_client_create) },
	{ 0xa05c03df, __VMLINUX_SYMBOL_STR(mempool_kmalloc) },
	{ 0x1e047854, __VMLINUX_SYMBOL_STR(warn_slowpath_fmt) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0x69ad2f20, __VMLINUX_SYMBOL_STR(kstrtouint) },
	{ 0x69acdf38, __VMLINUX_SYMBOL_STR(memcpy) },
	{ 0x4ca9669f, __VMLINUX_SYMBOL_STR(scnprintf) },
	{ 0xd091cdcf, __VMLINUX_SYMBOL_STR(dm_block_manager_create) },
	{ 0x90a1004a, __VMLINUX_SYMBOL_STR(crypto_has_alg) },
	{ 0xb781414f, __VMLINUX_SYMBOL_STR(dm_put_device) },
	{ 0x1e3f728d, __VMLINUX_SYMBOL_STR(dm_block_data) },
	{ 0x2e0d2f7f, __VMLINUX_SYMBOL_STR(queue_work_on) },
	{ 0xb0e602eb, __VMLINUX_SYMBOL_STR(memmove) },
	{ 0xca40abd5, __VMLINUX_SYMBOL_STR(dm_btree_insert) },
	{ 0x869526c5, __VMLINUX_SYMBOL_STR(zero_fill_bio) },
	{ 0x66051eb6, __VMLINUX_SYMBOL_STR(crypto_alloc_base) },
	{ 0xe914e41e, __VMLINUX_SYMBOL_STR(strcpy) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=dm-persistent-data";


MODULE_INFO(srcversion, "5EE63830B7AF1B9D1D9220F");
