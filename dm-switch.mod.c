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
	{ 0xd6ee688f, __VMLINUX_SYMBOL_STR(vmalloc) },
	{ 0x3c80c06c, __VMLINUX_SYMBOL_STR(kstrtoull) },
	{ 0xf92d9198, __VMLINUX_SYMBOL_STR(dm_get_device) },
	{ 0x5eb24829, __VMLINUX_SYMBOL_STR(dm_shift_arg) },
	{ 0x6d0f1f89, __VMLINUX_SYMBOL_STR(dm_table_get_mode) },
	{ 0x72319cdd, __VMLINUX_SYMBOL_STR(dm_set_target_max_io_len) },
	{ 0xd2b09ce5, __VMLINUX_SYMBOL_STR(__kmalloc) },
	{ 0xe04f7caa, __VMLINUX_SYMBOL_STR(dm_read_arg_group) },
	{ 0x46feb099, __VMLINUX_SYMBOL_STR(dm_read_arg) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0xcbbfb419, __VMLINUX_SYMBOL_STR(mutex_unlock) },
	{ 0xaafdc258, __VMLINUX_SYMBOL_STR(strcasecmp) },
	{ 0x896ac21b, __VMLINUX_SYMBOL_STR(mutex_lock) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0x999e8297, __VMLINUX_SYMBOL_STR(vfree) },
	{ 0xb781414f, __VMLINUX_SYMBOL_STR(dm_put_device) },
	{ 0x4ca9669f, __VMLINUX_SYMBOL_STR(scnprintf) },
	{ 0xf8c0f16e, __VMLINUX_SYMBOL_STR(__blkdev_driver_ioctl) },
	{ 0x4df6e7a2, __VMLINUX_SYMBOL_STR(scsi_verify_blk_ioctl) },
	{ 0xbdfb6dbb, __VMLINUX_SYMBOL_STR(__fentry__) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "180CEEAA37089A4EC60CCD7");
