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
	{ 0x4332582f, __VMLINUX_SYMBOL_STR(md_set_array_sectors) },
	{ 0x7723aaab, __VMLINUX_SYMBOL_STR(md_register_thread) },
	{ 0x3f71faa1, __VMLINUX_SYMBOL_STR(mempool_create) },
	{ 0xa05c03df, __VMLINUX_SYMBOL_STR(mempool_kmalloc) },
	{ 0x6a037cf1, __VMLINUX_SYMBOL_STR(mempool_kfree) },
	{ 0xd2b09ce5, __VMLINUX_SYMBOL_STR(__kmalloc) },
	{ 0xeddb98c1, __VMLINUX_SYMBOL_STR(kmem_cache_alloc_trace) },
	{ 0x4ca4f9d8, __VMLINUX_SYMBOL_STR(kmalloc_caches) },
	{ 0x35d3fbad, __VMLINUX_SYMBOL_STR(md_check_no_bitmap) },
	{ 0x4101c3c9, __VMLINUX_SYMBOL_STR(md_flush_request) },
	{ 0xe9dff136, __VMLINUX_SYMBOL_STR(mempool_alloc) },
	{ 0x4a479984, __VMLINUX_SYMBOL_STR(generic_make_request) },
	{ 0x21e3985c, __VMLINUX_SYMBOL_STR(md_check_recovery) },
	{ 0xc90c172a, __VMLINUX_SYMBOL_STR(md_wakeup_thread) },
	{ 0x2f6da7a9, __VMLINUX_SYMBOL_STR(md_error) },
	{ 0x4aad52d7, __VMLINUX_SYMBOL_STR(mempool_free) },
	{ 0x9b52dd2d, __VMLINUX_SYMBOL_STR(bio_endio) },
	{ 0x5ed9575c, __VMLINUX_SYMBOL_STR(mddev_congested) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0xefba93e1, __VMLINUX_SYMBOL_STR(mempool_destroy) },
	{ 0x8c0603d0, __VMLINUX_SYMBOL_STR(blk_sync_queue) },
	{ 0x4c107f4a, __VMLINUX_SYMBOL_STR(md_unregister_thread) },
	{ 0x91831d70, __VMLINUX_SYMBOL_STR(seq_printf) },
	{ 0x8f64aa4, __VMLINUX_SYMBOL_STR(_raw_spin_unlock_irqrestore) },
	{ 0x9327f5ce, __VMLINUX_SYMBOL_STR(_raw_spin_lock_irqsave) },
	{ 0x784213a6, __VMLINUX_SYMBOL_STR(pv_lock_ops) },
	{ 0x2ccea702, __VMLINUX_SYMBOL_STR(md_integrity_add_rdev) },
	{ 0x78764f4e, __VMLINUX_SYMBOL_STR(pv_irq_ops) },
	{ 0xd3719d59, __VMLINUX_SYMBOL_STR(paravirt_ticketlocks_enabled) },
	{ 0x43261dca, __VMLINUX_SYMBOL_STR(_raw_spin_lock_irq) },
	{ 0x1eaffe0a, __VMLINUX_SYMBOL_STR(blk_queue_segment_boundary) },
	{ 0x677d4ce4, __VMLINUX_SYMBOL_STR(blk_queue_max_segments) },
	{ 0xee032b56, __VMLINUX_SYMBOL_STR(disk_stack_limits) },
	{ 0x719b4945, __VMLINUX_SYMBOL_STR(md_integrity_register) },
	{ 0xc2cdbf1, __VMLINUX_SYMBOL_STR(synchronize_sched) },
	{ 0x842708d6, __VMLINUX_SYMBOL_STR(bdevname) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0x1e047854, __VMLINUX_SYMBOL_STR(warn_slowpath_fmt) },
	{ 0xbdfb6dbb, __VMLINUX_SYMBOL_STR(__fentry__) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "964FA72DE133A1C9BEFDF5D");
