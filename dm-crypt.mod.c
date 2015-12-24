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
	{ 0xcde055a1, __VMLINUX_SYMBOL_STR(dm_unregister_target) },
	{ 0xb76552eb, __VMLINUX_SYMBOL_STR(kmem_cache_destroy) },
	{ 0x6b76d57e, __VMLINUX_SYMBOL_STR(dm_register_target) },
	{ 0xa85d2821, __VMLINUX_SYMBOL_STR(kmem_cache_create) },
	{ 0x66051eb6, __VMLINUX_SYMBOL_STR(crypto_alloc_base) },
	{ 0x82cb7df, __VMLINUX_SYMBOL_STR(crypto_alloc_shash) },
	{ 0x64999478, __VMLINUX_SYMBOL_STR(congestion_wait) },
	{ 0xd14e5bc6, __VMLINUX_SYMBOL_STR(bio_add_page) },
	{ 0x3d69f5a0, __VMLINUX_SYMBOL_STR(bio_alloc_bioset) },
	{ 0xf432dd3d, __VMLINUX_SYMBOL_STR(__init_waitqueue_head) },
	{ 0x4b06d2e7, __VMLINUX_SYMBOL_STR(complete) },
	{ 0x1e047854, __VMLINUX_SYMBOL_STR(warn_slowpath_fmt) },
	{ 0xe9dff136, __VMLINUX_SYMBOL_STR(mempool_alloc) },
	{ 0xa1c76e0a, __VMLINUX_SYMBOL_STR(_cond_resched) },
	{ 0x6d0aba34, __VMLINUX_SYMBOL_STR(wait_for_completion) },
	{ 0xc897c382, __VMLINUX_SYMBOL_STR(sg_init_table) },
	{ 0x43a53735, __VMLINUX_SYMBOL_STR(__alloc_workqueue_key) },
	{ 0x5eb24829, __VMLINUX_SYMBOL_STR(dm_shift_arg) },
	{ 0xe04f7caa, __VMLINUX_SYMBOL_STR(dm_read_arg_group) },
	{ 0xf92d9198, __VMLINUX_SYMBOL_STR(dm_get_device) },
	{ 0x6d0f1f89, __VMLINUX_SYMBOL_STR(dm_table_get_mode) },
	{ 0x155cb2eb, __VMLINUX_SYMBOL_STR(bioset_create) },
	{ 0x53326531, __VMLINUX_SYMBOL_STR(mempool_alloc_pages) },
	{ 0xd985dc99, __VMLINUX_SYMBOL_STR(mempool_free_pages) },
	{ 0x6a037cf1, __VMLINUX_SYMBOL_STR(mempool_kfree) },
	{ 0xa05c03df, __VMLINUX_SYMBOL_STR(mempool_kmalloc) },
	{ 0x3f71faa1, __VMLINUX_SYMBOL_STR(mempool_create) },
	{ 0x183fa88b, __VMLINUX_SYMBOL_STR(mempool_alloc_slab) },
	{ 0x8a99a016, __VMLINUX_SYMBOL_STR(mempool_free_slab) },
	{ 0xed4baf13, __VMLINUX_SYMBOL_STR(crypto_alloc_ablkcipher) },
	{ 0x28318305, __VMLINUX_SYMBOL_STR(snprintf) },
	{ 0xeddb98c1, __VMLINUX_SYMBOL_STR(kmem_cache_alloc_trace) },
	{ 0x4ca4f9d8, __VMLINUX_SYMBOL_STR(kmalloc_caches) },
	{ 0x20c55ae0, __VMLINUX_SYMBOL_STR(sscanf) },
	{ 0x85df9b6c, __VMLINUX_SYMBOL_STR(strsep) },
	{ 0xc499ae1e, __VMLINUX_SYMBOL_STR(kstrdup) },
	{ 0x349cba85, __VMLINUX_SYMBOL_STR(strchr) },
	{ 0xd2b09ce5, __VMLINUX_SYMBOL_STR(__kmalloc) },
	{ 0xb6244511, __VMLINUX_SYMBOL_STR(sg_init_one) },
	{ 0x4629334c, __VMLINUX_SYMBOL_STR(__preempt_count) },
	{ 0xf7026158, __VMLINUX_SYMBOL_STR(crypto_shash_final) },
	{ 0xfdc8de49, __VMLINUX_SYMBOL_STR(crypto_shash_update) },
	{ 0x8810ad5e, __VMLINUX_SYMBOL_STR(crypto_xor) },
	{ 0xb781414f, __VMLINUX_SYMBOL_STR(dm_put_device) },
	{ 0xefba93e1, __VMLINUX_SYMBOL_STR(mempool_destroy) },
	{ 0x6ab31aba, __VMLINUX_SYMBOL_STR(bioset_free) },
	{ 0x8c03d20c, __VMLINUX_SYMBOL_STR(destroy_workqueue) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0x2e0d2f7f, __VMLINUX_SYMBOL_STR(queue_work_on) },
	{ 0x4f0c3029, __VMLINUX_SYMBOL_STR(bio_put) },
	{ 0x69acdf38, __VMLINUX_SYMBOL_STR(memcpy) },
	{ 0x7a4497db, __VMLINUX_SYMBOL_STR(kzfree) },
	{ 0x18489876, __VMLINUX_SYMBOL_STR(crypto_destroy_tfm) },
	{ 0x9b52dd2d, __VMLINUX_SYMBOL_STR(bio_endio) },
	{ 0x4aad52d7, __VMLINUX_SYMBOL_STR(mempool_free) },
	{ 0x4a479984, __VMLINUX_SYMBOL_STR(generic_make_request) },
	{ 0xa068ae96, __VMLINUX_SYMBOL_STR(bio_clone_bioset) },
	{ 0x4ca9669f, __VMLINUX_SYMBOL_STR(scnprintf) },
	{ 0xaafdc258, __VMLINUX_SYMBOL_STR(strcasecmp) },
	{ 0x5f005368, __VMLINUX_SYMBOL_STR(kstrtou8) },
	{ 0x754d539c, __VMLINUX_SYMBOL_STR(strlen) },
	{ 0xfb578fc5, __VMLINUX_SYMBOL_STR(memset) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0xbdfb6dbb, __VMLINUX_SYMBOL_STR(__fentry__) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "3337089129FD0E57B4E6DF5");
