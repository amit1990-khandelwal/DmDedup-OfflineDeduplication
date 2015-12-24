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
	{ 0x6b76d57e, __VMLINUX_SYMBOL_STR(dm_register_target) },
	{ 0xb1425b32, __VMLINUX_SYMBOL_STR(dm_table_add_target_callbacks) },
	{ 0x88c6fce5, __VMLINUX_SYMBOL_STR(put_page) },
	{ 0x2f6da7a9, __VMLINUX_SYMBOL_STR(md_error) },
	{ 0xcbbfb419, __VMLINUX_SYMBOL_STR(mutex_unlock) },
	{ 0x215df4df, __VMLINUX_SYMBOL_STR(md_run) },
	{ 0x896ac21b, __VMLINUX_SYMBOL_STR(mutex_lock) },
	{ 0x543b4234, __VMLINUX_SYMBOL_STR(alloc_pages_current) },
	{ 0xf92d9198, __VMLINUX_SYMBOL_STR(dm_get_device) },
	{ 0x6d0f1f89, __VMLINUX_SYMBOL_STR(dm_table_get_mode) },
	{ 0x9d5a630d, __VMLINUX_SYMBOL_STR(raid5_set_cache_size) },
	{ 0x72319cdd, __VMLINUX_SYMBOL_STR(dm_set_target_max_io_len) },
	{ 0xc592ce29, __VMLINUX_SYMBOL_STR(md_rdev_init) },
	{ 0x2231e233, __VMLINUX_SYMBOL_STR(mddev_init) },
	{ 0xd2b09ce5, __VMLINUX_SYMBOL_STR(__kmalloc) },
	{ 0x3c80c06c, __VMLINUX_SYMBOL_STR(kstrtoull) },
	{ 0xe2d5255a, __VMLINUX_SYMBOL_STR(strcmp) },
	{ 0xad84bef8, __VMLINUX_SYMBOL_STR(dm_table_event) },
	{ 0xbca91938, __VMLINUX_SYMBOL_STR(md_raid1_congested) },
	{ 0x9270bcc1, __VMLINUX_SYMBOL_STR(md_raid10_congested) },
	{ 0xf1dbcdb6, __VMLINUX_SYMBOL_STR(md_raid5_congested) },
	{ 0x5835d429, __VMLINUX_SYMBOL_STR(md_stop) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0xa6c844e3, __VMLINUX_SYMBOL_STR(md_rdev_clear) },
	{ 0xb781414f, __VMLINUX_SYMBOL_STR(dm_put_device) },
	{ 0x2e739058, __VMLINUX_SYMBOL_STR(md_stop_writes) },
	{ 0x6755ce92, __VMLINUX_SYMBOL_STR(mddev_suspend) },
	{ 0x48e7b678, __VMLINUX_SYMBOL_STR(bitmap_load) },
	{ 0xc01bc255, __VMLINUX_SYMBOL_STR(mddev_resume) },
	{ 0x5ab10213, __VMLINUX_SYMBOL_STR(sync_page_io) },
	{ 0x74c134b9, __VMLINUX_SYMBOL_STR(__sw_hweight32) },
	{ 0x4ca9669f, __VMLINUX_SYMBOL_STR(scnprintf) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0xc90c172a, __VMLINUX_SYMBOL_STR(md_wakeup_thread) },
	{ 0x37f37c30, __VMLINUX_SYMBOL_STR(md_reap_sync_thread) },
	{ 0xaafdc258, __VMLINUX_SYMBOL_STR(strcasecmp) },
	{ 0xd75f42b2, __VMLINUX_SYMBOL_STR(blk_limits_io_opt) },
	{ 0x118a5e56, __VMLINUX_SYMBOL_STR(blk_limits_io_min) },
	{ 0xbdfb6dbb, __VMLINUX_SYMBOL_STR(__fentry__) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=raid456,raid1,raid10";


MODULE_INFO(srcversion, "EA406DFFD26E9760799BC53");
