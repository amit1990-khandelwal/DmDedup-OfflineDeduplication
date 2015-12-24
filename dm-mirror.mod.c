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
	{ 0xa83588eb, __VMLINUX_SYMBOL_STR(dm_rh_recovery_end) },
	{ 0xd2b09ce5, __VMLINUX_SYMBOL_STR(__kmalloc) },
	{ 0xfad9d53a, __VMLINUX_SYMBOL_STR(dm_rh_get_region_size) },
	{ 0x784213a6, __VMLINUX_SYMBOL_STR(pv_lock_ops) },
	{ 0xa68e1f06, __VMLINUX_SYMBOL_STR(dm_rh_get_state) },
	{ 0xf92d9198, __VMLINUX_SYMBOL_STR(dm_get_device) },
	{ 0x2b5a58a3, __VMLINUX_SYMBOL_STR(dm_io) },
	{ 0x43a53735, __VMLINUX_SYMBOL_STR(__alloc_workqueue_key) },
	{ 0x864a8d14, __VMLINUX_SYMBOL_STR(dm_rh_inc_pending) },
	{ 0x6d0f1f89, __VMLINUX_SYMBOL_STR(dm_table_get_mode) },
	{ 0xfc62ef4e, __VMLINUX_SYMBOL_STR(dm_rh_get_region_key) },
	{ 0x154c6338, __VMLINUX_SYMBOL_STR(dm_kcopyd_client_destroy) },
	{ 0x6cb2a52c, __VMLINUX_SYMBOL_STR(dm_region_hash_create) },
	{ 0x593a99b, __VMLINUX_SYMBOL_STR(init_timer_key) },
	{ 0x6b76d57e, __VMLINUX_SYMBOL_STR(dm_register_target) },
	{ 0xecab91e1, __VMLINUX_SYMBOL_STR(dm_kcopyd_copy) },
	{ 0xd8aa4284, __VMLINUX_SYMBOL_STR(dm_rh_region_context) },
	{ 0x7d11c268, __VMLINUX_SYMBOL_STR(jiffies) },
	{ 0xa53387c7, __VMLINUX_SYMBOL_STR(dm_rh_flush) },
	{ 0x9e4faeef, __VMLINUX_SYMBOL_STR(dm_io_client_destroy) },
	{ 0x1d2f9ac, __VMLINUX_SYMBOL_STR(dm_rh_recovery_start) },
	{ 0xbe38a431, __VMLINUX_SYMBOL_STR(dm_rh_recovery_prepare) },
	{ 0xdbccc8f9, __VMLINUX_SYMBOL_STR(dm_rh_bio_to_region) },
	{ 0xd5f2172f, __VMLINUX_SYMBOL_STR(del_timer_sync) },
	{ 0xad84bef8, __VMLINUX_SYMBOL_STR(dm_table_event) },
	{ 0x72319cdd, __VMLINUX_SYMBOL_STR(dm_set_target_max_io_len) },
	{ 0x8f64aa4, __VMLINUX_SYMBOL_STR(_raw_spin_unlock_irqrestore) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0x20c55ae0, __VMLINUX_SYMBOL_STR(sscanf) },
	{ 0xb138d0bf, __VMLINUX_SYMBOL_STR(dm_ratelimit_state) },
	{ 0xcde055a1, __VMLINUX_SYMBOL_STR(dm_unregister_target) },
	{ 0x8c03d20c, __VMLINUX_SYMBOL_STR(destroy_workqueue) },
	{ 0xbe2c0274, __VMLINUX_SYMBOL_STR(add_timer) },
	{ 0x4a479984, __VMLINUX_SYMBOL_STR(generic_make_request) },
	{ 0x42160169, __VMLINUX_SYMBOL_STR(flush_workqueue) },
	{ 0x7774620f, __VMLINUX_SYMBOL_STR(dm_rh_stop_recovery) },
	{ 0x9b52dd2d, __VMLINUX_SYMBOL_STR(bio_endio) },
	{ 0xeb184302, __VMLINUX_SYMBOL_STR(dm_rh_dirty_log) },
	{ 0x4430764e, __VMLINUX_SYMBOL_STR(dm_rh_region_to_sector) },
	{ 0x78764f4e, __VMLINUX_SYMBOL_STR(pv_irq_ops) },
	{ 0x1000e51, __VMLINUX_SYMBOL_STR(schedule) },
	{ 0x79a38e61, __VMLINUX_SYMBOL_STR(___ratelimit) },
	{ 0xd688716b, __VMLINUX_SYMBOL_STR(dm_kcopyd_client_create) },
	{ 0x43261dca, __VMLINUX_SYMBOL_STR(_raw_spin_lock_irq) },
	{ 0xbdfb6dbb, __VMLINUX_SYMBOL_STR(__fentry__) },
	{ 0x9327f5ce, __VMLINUX_SYMBOL_STR(_raw_spin_lock_irqsave) },
	{ 0x38efaf5a, __VMLINUX_SYMBOL_STR(dm_region_hash_destroy) },
	{ 0xcf21d241, __VMLINUX_SYMBOL_STR(__wake_up) },
	{ 0x34f22f94, __VMLINUX_SYMBOL_STR(prepare_to_wait_event) },
	{ 0x601f665f, __VMLINUX_SYMBOL_STR(dm_io_client_create) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0x2a5248ca, __VMLINUX_SYMBOL_STR(dm_rh_mark_nosync) },
	{ 0xd3719d59, __VMLINUX_SYMBOL_STR(paravirt_ticketlocks_enabled) },
	{ 0x969e9378, __VMLINUX_SYMBOL_STR(dm_dirty_log_destroy) },
	{ 0x4ca9669f, __VMLINUX_SYMBOL_STR(scnprintf) },
	{ 0x7d053fc5, __VMLINUX_SYMBOL_STR(dm_rh_start_recovery) },
	{ 0xfa66f77c, __VMLINUX_SYMBOL_STR(finish_wait) },
	{ 0x3a18389a, __VMLINUX_SYMBOL_STR(dm_rh_update_states) },
	{ 0xb781414f, __VMLINUX_SYMBOL_STR(dm_put_device) },
	{ 0x1008b78b, __VMLINUX_SYMBOL_STR(dm_noflush_suspending) },
	{ 0x2e0d2f7f, __VMLINUX_SYMBOL_STR(queue_work_on) },
	{ 0xfd93482e, __VMLINUX_SYMBOL_STR(dm_rh_recovery_in_flight) },
	{ 0x51dbbd0, __VMLINUX_SYMBOL_STR(dm_rh_delay) },
	{ 0x47c8baf4, __VMLINUX_SYMBOL_STR(param_ops_uint) },
	{ 0x6eaa3d4e, __VMLINUX_SYMBOL_STR(dm_dirty_log_create) },
	{ 0x45ab972a, __VMLINUX_SYMBOL_STR(dm_rh_dec) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=dm-region-hash,dm-log";


MODULE_INFO(srcversion, "F6EBBF529C0EB95C817EE2A");
