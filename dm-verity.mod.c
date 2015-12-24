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
	{ 0x47c8baf4, __VMLINUX_SYMBOL_STR(param_ops_uint) },
	{ 0xcde055a1, __VMLINUX_SYMBOL_STR(dm_unregister_target) },
	{ 0x6b76d57e, __VMLINUX_SYMBOL_STR(dm_register_target) },
	{ 0x43a53735, __VMLINUX_SYMBOL_STR(__alloc_workqueue_key) },
	{ 0x63c4d61f, __VMLINUX_SYMBOL_STR(__bitmap_weight) },
	{ 0xbd100793, __VMLINUX_SYMBOL_STR(cpu_online_mask) },
	{ 0x3f71faa1, __VMLINUX_SYMBOL_STR(mempool_create) },
	{ 0x6a037cf1, __VMLINUX_SYMBOL_STR(mempool_kfree) },
	{ 0xa05c03df, __VMLINUX_SYMBOL_STR(mempool_kmalloc) },
	{ 0x9c256008, __VMLINUX_SYMBOL_STR(dm_bufio_get_device_size) },
	{ 0x486e239f, __VMLINUX_SYMBOL_STR(dm_bufio_client_create) },
	{ 0xe2d5255a, __VMLINUX_SYMBOL_STR(strcmp) },
	{ 0x5377e556, __VMLINUX_SYMBOL_STR(hex2bin) },
	{ 0xd2b09ce5, __VMLINUX_SYMBOL_STR(__kmalloc) },
	{ 0x82cb7df, __VMLINUX_SYMBOL_STR(crypto_alloc_shash) },
	{ 0xc499ae1e, __VMLINUX_SYMBOL_STR(kstrdup) },
	{ 0xf92d9198, __VMLINUX_SYMBOL_STR(dm_get_device) },
	{ 0x20c55ae0, __VMLINUX_SYMBOL_STR(sscanf) },
	{ 0x6d0f1f89, __VMLINUX_SYMBOL_STR(dm_table_get_mode) },
	{ 0xa448e19f, __VMLINUX_SYMBOL_STR(dm_bufio_prefetch) },
	{ 0x4a479984, __VMLINUX_SYMBOL_STR(generic_make_request) },
	{ 0xeddb98c1, __VMLINUX_SYMBOL_STR(kmem_cache_alloc_trace) },
	{ 0x4ca4f9d8, __VMLINUX_SYMBOL_STR(kmalloc_caches) },
	{ 0x1e047854, __VMLINUX_SYMBOL_STR(warn_slowpath_fmt) },
	{ 0x4629334c, __VMLINUX_SYMBOL_STR(__preempt_count) },
	{ 0xb781414f, __VMLINUX_SYMBOL_STR(dm_put_device) },
	{ 0x18489876, __VMLINUX_SYMBOL_STR(crypto_destroy_tfm) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0xeca7949e, __VMLINUX_SYMBOL_STR(dm_bufio_client_destroy) },
	{ 0xefba93e1, __VMLINUX_SYMBOL_STR(mempool_destroy) },
	{ 0x8c03d20c, __VMLINUX_SYMBOL_STR(destroy_workqueue) },
	{ 0x2e0d2f7f, __VMLINUX_SYMBOL_STR(queue_work_on) },
	{ 0xecd85ddb, __VMLINUX_SYMBOL_STR(bio_endio_nodec) },
	{ 0x79a38e61, __VMLINUX_SYMBOL_STR(___ratelimit) },
	{ 0xb138d0bf, __VMLINUX_SYMBOL_STR(dm_ratelimit_state) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0xe6024e59, __VMLINUX_SYMBOL_STR(dm_bufio_release) },
	{ 0x69acdf38, __VMLINUX_SYMBOL_STR(memcpy) },
	{ 0x449ad0a7, __VMLINUX_SYMBOL_STR(memcmp) },
	{ 0xf7026158, __VMLINUX_SYMBOL_STR(crypto_shash_final) },
	{ 0xfdc8de49, __VMLINUX_SYMBOL_STR(crypto_shash_update) },
	{ 0xa1d2413a, __VMLINUX_SYMBOL_STR(dm_bufio_read) },
	{ 0x74dcd98c, __VMLINUX_SYMBOL_STR(dm_bufio_get_aux_data) },
	{ 0x4ca9669f, __VMLINUX_SYMBOL_STR(scnprintf) },
	{ 0xf8c0f16e, __VMLINUX_SYMBOL_STR(__blkdev_driver_ioctl) },
	{ 0x4df6e7a2, __VMLINUX_SYMBOL_STR(scsi_verify_blk_ioctl) },
	{ 0x118a5e56, __VMLINUX_SYMBOL_STR(blk_limits_io_min) },
	{ 0xbdfb6dbb, __VMLINUX_SYMBOL_STR(__fentry__) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=dm-bufio";


MODULE_INFO(srcversion, "D4773F4967B7B8F756537E1");
