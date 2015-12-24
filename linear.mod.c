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
	{ 0x4224ec8a, __VMLINUX_SYMBOL_STR(unregister_md_personality) },
	{ 0x6718077, __VMLINUX_SYMBOL_STR(register_md_personality) },
	{ 0x719b4945, __VMLINUX_SYMBOL_STR(md_integrity_register) },
	{ 0xc1eb978a, __VMLINUX_SYMBOL_STR(blk_queue_merge_bvec) },
	{ 0x35d3fbad, __VMLINUX_SYMBOL_STR(md_check_no_bitmap) },
	{ 0x9469482, __VMLINUX_SYMBOL_STR(kfree_call_rcu) },
	{ 0x5c750c00, __VMLINUX_SYMBOL_STR(revalidate_disk) },
	{ 0x4332582f, __VMLINUX_SYMBOL_STR(md_set_array_sectors) },
	{ 0xee032b56, __VMLINUX_SYMBOL_STR(disk_stack_limits) },
	{ 0xd2b09ce5, __VMLINUX_SYMBOL_STR(__kmalloc) },
	{ 0x5ed9575c, __VMLINUX_SYMBOL_STR(mddev_congested) },
	{ 0xfb254830, __VMLINUX_SYMBOL_STR(bio_chain) },
	{ 0xeb594c85, __VMLINUX_SYMBOL_STR(bio_split) },
	{ 0x153e70d9, __VMLINUX_SYMBOL_STR(fs_bio_set) },
	{ 0x9b52dd2d, __VMLINUX_SYMBOL_STR(bio_endio) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0x842708d6, __VMLINUX_SYMBOL_STR(bdevname) },
	{ 0x4101c3c9, __VMLINUX_SYMBOL_STR(md_flush_request) },
	{ 0x4a479984, __VMLINUX_SYMBOL_STR(generic_make_request) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0x8c0603d0, __VMLINUX_SYMBOL_STR(blk_sync_queue) },
	{ 0x60a13e90, __VMLINUX_SYMBOL_STR(rcu_barrier) },
	{ 0x91831d70, __VMLINUX_SYMBOL_STR(seq_printf) },
	{ 0x1e047854, __VMLINUX_SYMBOL_STR(warn_slowpath_fmt) },
	{ 0xbdfb6dbb, __VMLINUX_SYMBOL_STR(__fentry__) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "BAA54D90BBDCB7FFC433CC5");
