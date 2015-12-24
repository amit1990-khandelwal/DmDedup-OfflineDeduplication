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
	{ 0xc1eb978a, __VMLINUX_SYMBOL_STR(blk_queue_merge_bvec) },
	{ 0x543b4234, __VMLINUX_SYMBOL_STR(alloc_pages_current) },
	{ 0x4ca4f9d8, __VMLINUX_SYMBOL_STR(kmalloc_caches) },
	{ 0xd2b09ce5, __VMLINUX_SYMBOL_STR(__kmalloc) },
	{ 0x7b56f141, __VMLINUX_SYMBOL_STR(submit_bio_wait) },
	{ 0x3d69f5a0, __VMLINUX_SYMBOL_STR(bio_alloc_bioset) },
	{ 0x5ed9575c, __VMLINUX_SYMBOL_STR(mddev_congested) },
	{ 0xc24e2400, __VMLINUX_SYMBOL_STR(rdev_set_badblocks) },
	{ 0x784213a6, __VMLINUX_SYMBOL_STR(pv_lock_ops) },
	{ 0xb6b46a7c, __VMLINUX_SYMBOL_STR(param_ops_int) },
	{ 0x412fc7c2, __VMLINUX_SYMBOL_STR(md_is_badblock) },
	{ 0xb78f29de, __VMLINUX_SYMBOL_STR(bio_clone_mddev) },
	{ 0xc8b57c27, __VMLINUX_SYMBOL_STR(autoremove_wake_function) },
	{ 0x6c3e048, __VMLINUX_SYMBOL_STR(bio_alloc_mddev) },
	{ 0x21e3985c, __VMLINUX_SYMBOL_STR(md_check_recovery) },
	{ 0x2a62f6ea, __VMLINUX_SYMBOL_STR(md_write_end) },
	{ 0x91831d70, __VMLINUX_SYMBOL_STR(seq_printf) },
	{ 0xf087137d, __VMLINUX_SYMBOL_STR(__dynamic_pr_debug) },
	{ 0x28624bc7, __VMLINUX_SYMBOL_STR(bitmap_endwrite) },
	{ 0xefba93e1, __VMLINUX_SYMBOL_STR(mempool_destroy) },
	{ 0x8c6766ba, __VMLINUX_SYMBOL_STR(bitmap_unplug) },
	{ 0x2fa06db6, __VMLINUX_SYMBOL_STR(bio_trim) },
	{ 0x4224ec8a, __VMLINUX_SYMBOL_STR(unregister_md_personality) },
	{ 0x91715312, __VMLINUX_SYMBOL_STR(sprintf) },
	{ 0x5c750c00, __VMLINUX_SYMBOL_STR(revalidate_disk) },
	{ 0xeeff458e, __VMLINUX_SYMBOL_STR(bitmap_resize) },
	{ 0xf432dd3d, __VMLINUX_SYMBOL_STR(__init_waitqueue_head) },
	{ 0xc3639d5e, __VMLINUX_SYMBOL_STR(bio_reset) },
	{ 0x78b3a75f, __VMLINUX_SYMBOL_STR(bitmap_start_sync) },
	{ 0xd27b25dd, __VMLINUX_SYMBOL_STR(blk_check_plugged) },
	{ 0x7723aaab, __VMLINUX_SYMBOL_STR(md_register_thread) },
	{ 0x8f64aa4, __VMLINUX_SYMBOL_STR(_raw_spin_unlock_irqrestore) },
	{ 0x2ec1c843, __VMLINUX_SYMBOL_STR(current_task) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0x449ad0a7, __VMLINUX_SYMBOL_STR(memcmp) },
	{ 0xd14e5bc6, __VMLINUX_SYMBOL_STR(bio_add_page) },
	{ 0xee032b56, __VMLINUX_SYMBOL_STR(disk_stack_limits) },
	{ 0xb2eec3d, __VMLINUX_SYMBOL_STR(bitmap_close_sync) },
	{ 0xa1c76e0a, __VMLINUX_SYMBOL_STR(_cond_resched) },
	{ 0xc2cdbf1, __VMLINUX_SYMBOL_STR(synchronize_sched) },
	{ 0x4a479984, __VMLINUX_SYMBOL_STR(generic_make_request) },
	{ 0x27edb51, __VMLINUX_SYMBOL_STR(sysfs_remove_link) },
	{ 0x669183e6, __VMLINUX_SYMBOL_STR(md_wait_for_blocked_rdev) },
	{ 0x2ccea702, __VMLINUX_SYMBOL_STR(md_integrity_add_rdev) },
	{ 0x9b52dd2d, __VMLINUX_SYMBOL_STR(bio_endio) },
	{ 0x4f0c3029, __VMLINUX_SYMBOL_STR(bio_put) },
	{ 0xfc5b7524, __VMLINUX_SYMBOL_STR(md_done_sync) },
	{ 0x73d8cb6e, __VMLINUX_SYMBOL_STR(flush_signals) },
	{ 0x210fd9b, __VMLINUX_SYMBOL_STR(sysfs_create_link) },
	{ 0xbd9074b1, __VMLINUX_SYMBOL_STR(blk_finish_plug) },
	{ 0x78764f4e, __VMLINUX_SYMBOL_STR(pv_irq_ops) },
	{ 0x48dc4149, __VMLINUX_SYMBOL_STR(__free_pages) },
	{ 0x4af67747, __VMLINUX_SYMBOL_STR(bitmap_cond_end_sync) },
	{ 0xe9dff136, __VMLINUX_SYMBOL_STR(mempool_alloc) },
	{ 0xc16fc560, __VMLINUX_SYMBOL_STR(md_write_start) },
	{ 0x842708d6, __VMLINUX_SYMBOL_STR(bdevname) },
	{ 0xd98d7985, __VMLINUX_SYMBOL_STR(rdev_clear_badblocks) },
	{ 0x4b0f0127, __VMLINUX_SYMBOL_STR(md_allow_write) },
	{ 0x1000e51, __VMLINUX_SYMBOL_STR(schedule) },
	{ 0x79a38e61, __VMLINUX_SYMBOL_STR(___ratelimit) },
	{ 0x4332582f, __VMLINUX_SYMBOL_STR(md_set_array_sectors) },
	{ 0x3f71faa1, __VMLINUX_SYMBOL_STR(mempool_create) },
	{ 0x43261dca, __VMLINUX_SYMBOL_STR(_raw_spin_lock_irq) },
	{ 0xc90c172a, __VMLINUX_SYMBOL_STR(md_wakeup_thread) },
	{ 0xbdfb6dbb, __VMLINUX_SYMBOL_STR(__fentry__) },
	{ 0xcc5005fe, __VMLINUX_SYMBOL_STR(msleep_interruptible) },
	{ 0x7d788265, __VMLINUX_SYMBOL_STR(kernfs_notify) },
	{ 0xeddb98c1, __VMLINUX_SYMBOL_STR(kmem_cache_alloc_trace) },
	{ 0x4aad52d7, __VMLINUX_SYMBOL_STR(mempool_free) },
	{ 0x9327f5ce, __VMLINUX_SYMBOL_STR(_raw_spin_lock_irqsave) },
	{ 0xcf21d241, __VMLINUX_SYMBOL_STR(__wake_up) },
	{ 0x34f22f94, __VMLINUX_SYMBOL_STR(prepare_to_wait_event) },
	{ 0x5ab10213, __VMLINUX_SYMBOL_STR(sync_page_io) },
	{ 0x4c107f4a, __VMLINUX_SYMBOL_STR(md_unregister_thread) },
	{ 0x7dbce81d, __VMLINUX_SYMBOL_STR(bio_alloc_pages) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0x2db8046c, __VMLINUX_SYMBOL_STR(bitmap_startwrite) },
	{ 0x69acdf38, __VMLINUX_SYMBOL_STR(memcpy) },
	{ 0x5c8b5ce8, __VMLINUX_SYMBOL_STR(prepare_to_wait) },
	{ 0xd3719d59, __VMLINUX_SYMBOL_STR(paravirt_ticketlocks_enabled) },
	{ 0x2f6da7a9, __VMLINUX_SYMBOL_STR(md_error) },
	{ 0x88c6fce5, __VMLINUX_SYMBOL_STR(put_page) },
	{ 0xfa66f77c, __VMLINUX_SYMBOL_STR(finish_wait) },
	{ 0x53219ee8, __VMLINUX_SYMBOL_STR(bio_copy_data) },
	{ 0x7d705738, __VMLINUX_SYMBOL_STR(blk_start_plug) },
	{ 0x3cb8db59, __VMLINUX_SYMBOL_STR(blk_queue_max_write_same_sectors) },
	{ 0x719b4945, __VMLINUX_SYMBOL_STR(md_integrity_register) },
	{ 0x6718077, __VMLINUX_SYMBOL_STR(register_md_personality) },
	{ 0xa73afe00, __VMLINUX_SYMBOL_STR(bitmap_end_sync) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "CC013552B21CCC59204B6F6");
