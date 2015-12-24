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
	{ 0x8487a2b6, __VMLINUX_SYMBOL_STR(flush_work) },
	{ 0x2d3385d3, __VMLINUX_SYMBOL_STR(system_wq) },
	{ 0xace7f227, __VMLINUX_SYMBOL_STR(scsi_dh_set_params) },
	{ 0xb76552eb, __VMLINUX_SYMBOL_STR(kmem_cache_destroy) },
	{ 0x402b8281, __VMLINUX_SYMBOL_STR(__request_module) },
	{ 0x4ca4f9d8, __VMLINUX_SYMBOL_STR(kmalloc_caches) },
	{ 0xd2b09ce5, __VMLINUX_SYMBOL_STR(__kmalloc) },
	{ 0x7deff673, __VMLINUX_SYMBOL_STR(dm_consume_args) },
	{ 0x5876c094, __VMLINUX_SYMBOL_STR(up_read) },
	{ 0x754d539c, __VMLINUX_SYMBOL_STR(strlen) },
	{ 0xf92d9198, __VMLINUX_SYMBOL_STR(dm_get_device) },
	{ 0x43a53735, __VMLINUX_SYMBOL_STR(__alloc_workqueue_key) },
	{ 0x2f113952, __VMLINUX_SYMBOL_STR(dm_path_uevent) },
	{ 0xb5dcab5b, __VMLINUX_SYMBOL_STR(remove_wait_queue) },
	{ 0x6d0f1f89, __VMLINUX_SYMBOL_STR(dm_table_get_mode) },
	{ 0x6b06fdce, __VMLINUX_SYMBOL_STR(delayed_work_timer_fn) },
	{ 0xefba93e1, __VMLINUX_SYMBOL_STR(mempool_destroy) },
	{ 0x593a99b, __VMLINUX_SYMBOL_STR(init_timer_key) },
	{ 0xcbbfb419, __VMLINUX_SYMBOL_STR(mutex_unlock) },
	{ 0x6b76d57e, __VMLINUX_SYMBOL_STR(dm_register_target) },
	{ 0x91715312, __VMLINUX_SYMBOL_STR(sprintf) },
	{ 0xc499ae1e, __VMLINUX_SYMBOL_STR(kstrdup) },
	{ 0x4708400e, __VMLINUX_SYMBOL_STR(scsi_dh_attached_handler_name) },
	{ 0xf96cc7e, __VMLINUX_SYMBOL_STR(down_read) },
	{ 0xe2d5255a, __VMLINUX_SYMBOL_STR(strcmp) },
	{ 0xf432dd3d, __VMLINUX_SYMBOL_STR(__init_waitqueue_head) },
	{ 0xffd5a395, __VMLINUX_SYMBOL_STR(default_wake_function) },
	{ 0x183fa88b, __VMLINUX_SYMBOL_STR(mempool_alloc_slab) },
	{ 0xe04f7caa, __VMLINUX_SYMBOL_STR(dm_read_arg_group) },
	{ 0xad84bef8, __VMLINUX_SYMBOL_STR(dm_table_event) },
	{ 0xf8c0f16e, __VMLINUX_SYMBOL_STR(__blkdev_driver_ioctl) },
	{ 0x8f64aa4, __VMLINUX_SYMBOL_STR(_raw_spin_unlock_irqrestore) },
	{ 0x2ec1c843, __VMLINUX_SYMBOL_STR(current_task) },
	{ 0xbf333e27, __VMLINUX_SYMBOL_STR(__mutex_init) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0x20c55ae0, __VMLINUX_SYMBOL_STR(sscanf) },
	{ 0x9c123043, __VMLINUX_SYMBOL_STR(scsi_dh_activate) },
	{ 0x98fa1e20, __VMLINUX_SYMBOL_STR(dm_get_reserved_rq_based_ios) },
	{ 0xcde055a1, __VMLINUX_SYMBOL_STR(dm_unregister_target) },
	{ 0x3dbf87c4, __VMLINUX_SYMBOL_STR(scsi_dh_attach) },
	{ 0xaafdc258, __VMLINUX_SYMBOL_STR(strcasecmp) },
	{ 0x5eb24829, __VMLINUX_SYMBOL_STR(dm_shift_arg) },
	{ 0x93a6e0b2, __VMLINUX_SYMBOL_STR(io_schedule) },
	{ 0x896ac21b, __VMLINUX_SYMBOL_STR(mutex_lock) },
	{ 0x8c03d20c, __VMLINUX_SYMBOL_STR(destroy_workqueue) },
	{ 0x46feb099, __VMLINUX_SYMBOL_STR(dm_read_arg) },
	{ 0x960f071e, __VMLINUX_SYMBOL_STR(dm_suspended) },
	{ 0x8a99a016, __VMLINUX_SYMBOL_STR(mempool_free_slab) },
	{ 0x6e5db7e4, __VMLINUX_SYMBOL_STR(up_write) },
	{ 0x2ed55c8e, __VMLINUX_SYMBOL_STR(down_write) },
	{ 0x593a36c2, __VMLINUX_SYMBOL_STR(scsi_dh_handler_exist) },
	{ 0x42160169, __VMLINUX_SYMBOL_STR(flush_workqueue) },
	{ 0xbe0498f3, __VMLINUX_SYMBOL_STR(module_put) },
	{ 0xe9dff136, __VMLINUX_SYMBOL_STR(mempool_alloc) },
	{ 0xeeec26a7, __VMLINUX_SYMBOL_STR(queue_delayed_work_on) },
	{ 0x4df6e7a2, __VMLINUX_SYMBOL_STR(scsi_verify_blk_ioctl) },
	{ 0x3bd1b1f6, __VMLINUX_SYMBOL_STR(msecs_to_jiffies) },
	{ 0x3f71faa1, __VMLINUX_SYMBOL_STR(mempool_create) },
	{ 0xbde67803, __VMLINUX_SYMBOL_STR(dm_underlying_device_busy) },
	{ 0xbdfb6dbb, __VMLINUX_SYMBOL_STR(__fentry__) },
	{ 0xeddb98c1, __VMLINUX_SYMBOL_STR(kmem_cache_alloc_trace) },
	{ 0x4aad52d7, __VMLINUX_SYMBOL_STR(mempool_free) },
	{ 0x9327f5ce, __VMLINUX_SYMBOL_STR(_raw_spin_lock_irqsave) },
	{ 0xa85d2821, __VMLINUX_SYMBOL_STR(kmem_cache_create) },
	{ 0xcf21d241, __VMLINUX_SYMBOL_STR(__wake_up) },
	{ 0x5860aad4, __VMLINUX_SYMBOL_STR(add_wait_queue) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0x4ca9669f, __VMLINUX_SYMBOL_STR(scnprintf) },
	{ 0xa203bd85, __VMLINUX_SYMBOL_STR(scsi_dh_detach) },
	{ 0xb781414f, __VMLINUX_SYMBOL_STR(dm_put_device) },
	{ 0x1008b78b, __VMLINUX_SYMBOL_STR(dm_noflush_suspending) },
	{ 0x2e0d2f7f, __VMLINUX_SYMBOL_STR(queue_work_on) },
	{ 0x37af3190, __VMLINUX_SYMBOL_STR(dm_table_run_md_queue_async) },
	{ 0x8ea31722, __VMLINUX_SYMBOL_STR(try_module_get) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=scsi_dh";


MODULE_INFO(srcversion, "E5697BA16B757D09DE56A67");
