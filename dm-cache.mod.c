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
	{ 0xb76552eb, __VMLINUX_SYMBOL_STR(kmem_cache_destroy) },
	{ 0x402b8281, __VMLINUX_SYMBOL_STR(__request_module) },
	{ 0xd041d62b, __VMLINUX_SYMBOL_STR(dm_array_get_value) },
	{ 0x4ca4f9d8, __VMLINUX_SYMBOL_STR(kmalloc_caches) },
	{ 0xd2b09ce5, __VMLINUX_SYMBOL_STR(__kmalloc) },
	{ 0x7deff673, __VMLINUX_SYMBOL_STR(dm_consume_args) },
	{ 0xb7bad799, __VMLINUX_SYMBOL_STR(dm_bm_unlock) },
	{ 0x5876c094, __VMLINUX_SYMBOL_STR(up_read) },
	{ 0xda3e43d1, __VMLINUX_SYMBOL_STR(_raw_spin_unlock) },
	{ 0x23e3b40d, __VMLINUX_SYMBOL_STR(dm_get_cell) },
	{ 0x754d539c, __VMLINUX_SYMBOL_STR(strlen) },
	{ 0xf92d9198, __VMLINUX_SYMBOL_STR(dm_get_device) },
	{ 0x43a53735, __VMLINUX_SYMBOL_STR(__alloc_workqueue_key) },
	{ 0x24fa6664, __VMLINUX_SYMBOL_STR(dm_bitset_set_bit) },
	{ 0xd75f42b2, __VMLINUX_SYMBOL_STR(blk_limits_io_opt) },
	{ 0x688d422d, __VMLINUX_SYMBOL_STR(dm_bm_block_size) },
	{ 0xd00dbc46, __VMLINUX_SYMBOL_STR(dm_bio_prison_free_cell) },
	{ 0x6b06fdce, __VMLINUX_SYMBOL_STR(delayed_work_timer_fn) },
	{ 0x154c6338, __VMLINUX_SYMBOL_STR(dm_kcopyd_client_destroy) },
	{ 0xefba93e1, __VMLINUX_SYMBOL_STR(mempool_destroy) },
	{ 0x593a99b, __VMLINUX_SYMBOL_STR(init_timer_key) },
	{ 0x999e8297, __VMLINUX_SYMBOL_STR(vfree) },
	{ 0x6b76d57e, __VMLINUX_SYMBOL_STR(dm_register_target) },
	{ 0xecab91e1, __VMLINUX_SYMBOL_STR(dm_kcopyd_copy) },
	{ 0x91715312, __VMLINUX_SYMBOL_STR(sprintf) },
	{ 0xc499ae1e, __VMLINUX_SYMBOL_STR(kstrdup) },
	{ 0x118a5e56, __VMLINUX_SYMBOL_STR(blk_limits_io_min) },
	{ 0xd163cade, __VMLINUX_SYMBOL_STR(dm_tm_commit) },
	{ 0x6791a44e, __VMLINUX_SYMBOL_STR(dm_deferred_entry_dec) },
	{ 0x7d11c268, __VMLINUX_SYMBOL_STR(jiffies) },
	{ 0x5aed1dd7, __VMLINUX_SYMBOL_STR(dm_bitset_flush) },
	{ 0xf96cc7e, __VMLINUX_SYMBOL_STR(down_read) },
	{ 0xe2d5255a, __VMLINUX_SYMBOL_STR(strcmp) },
	{ 0xf432dd3d, __VMLINUX_SYMBOL_STR(__init_waitqueue_head) },
	{ 0xb70b342a, __VMLINUX_SYMBOL_STR(dm_bio_prison_destroy) },
	{ 0xd292ed14, __VMLINUX_SYMBOL_STR(dm_cell_release) },
	{ 0x183fa88b, __VMLINUX_SYMBOL_STR(mempool_alloc_slab) },
	{ 0xe04f7caa, __VMLINUX_SYMBOL_STR(dm_read_arg_group) },
	{ 0xffff2ac3, __VMLINUX_SYMBOL_STR(dm_bitset_resize) },
	{ 0x832bf228, __VMLINUX_SYMBOL_STR(dm_array_del) },
	{ 0x3c80c06c, __VMLINUX_SYMBOL_STR(kstrtoull) },
	{ 0xad84bef8, __VMLINUX_SYMBOL_STR(dm_table_event) },
	{ 0xfb578fc5, __VMLINUX_SYMBOL_STR(memset) },
	{ 0x5991219c, __VMLINUX_SYMBOL_STR(cancel_delayed_work) },
	{ 0x72319cdd, __VMLINUX_SYMBOL_STR(dm_set_target_max_io_len) },
	{ 0x17c36f29, __VMLINUX_SYMBOL_STR(dm_bm_checksum) },
	{ 0x8f64aa4, __VMLINUX_SYMBOL_STR(_raw_spin_unlock_irqrestore) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0x20c55ae0, __VMLINUX_SYMBOL_STR(sscanf) },
	{ 0x62c1b9ee, __VMLINUX_SYMBOL_STR(dm_array_walk) },
	{ 0x72289260, __VMLINUX_SYMBOL_STR(dm_block_manager_destroy) },
	{ 0xed58cfa1, __VMLINUX_SYMBOL_STR(dm_bitset_empty) },
	{ 0xb138d0bf, __VMLINUX_SYMBOL_STR(dm_ratelimit_state) },
	{ 0xcde055a1, __VMLINUX_SYMBOL_STR(dm_unregister_target) },
	{ 0xaafdc258, __VMLINUX_SYMBOL_STR(strcasecmp) },
	{ 0xca2e3a88, __VMLINUX_SYMBOL_STR(dm_deferred_entry_inc) },
	{ 0x9166fada, __VMLINUX_SYMBOL_STR(strncpy) },
	{ 0x5eb24829, __VMLINUX_SYMBOL_STR(dm_shift_arg) },
	{ 0x5a921311, __VMLINUX_SYMBOL_STR(strncmp) },
	{ 0x32b5f546, __VMLINUX_SYMBOL_STR(dm_array_empty) },
	{ 0xf375d009, __VMLINUX_SYMBOL_STR(dm_bm_write_lock) },
	{ 0x8c03d20c, __VMLINUX_SYMBOL_STR(destroy_workqueue) },
	{ 0x960f071e, __VMLINUX_SYMBOL_STR(dm_suspended) },
	{ 0x4a479984, __VMLINUX_SYMBOL_STR(generic_make_request) },
	{ 0x8a99a016, __VMLINUX_SYMBOL_STR(mempool_free_slab) },
	{ 0x6e5db7e4, __VMLINUX_SYMBOL_STR(up_write) },
	{ 0x2ed55c8e, __VMLINUX_SYMBOL_STR(down_write) },
	{ 0xab96bd2d, __VMLINUX_SYMBOL_STR(dm_bitset_test_bit) },
	{ 0x42160169, __VMLINUX_SYMBOL_STR(flush_workqueue) },
	{ 0x858c8d94, __VMLINUX_SYMBOL_STR(dm_array_set_value) },
	{ 0x8e4150e1, __VMLINUX_SYMBOL_STR(dm_bio_prison_alloc_cell) },
	{ 0x9b52dd2d, __VMLINUX_SYMBOL_STR(bio_endio) },
	{ 0x7ade1071, __VMLINUX_SYMBOL_STR(dm_tm_destroy) },
	{ 0xf12ec3cd, __VMLINUX_SYMBOL_STR(dm_disk_bitset_init) },
	{ 0x7657e859, __VMLINUX_SYMBOL_STR(dm_bitset_clear_bit) },
	{ 0xafeda29f, __VMLINUX_SYMBOL_STR(dm_bm_write_lock_zero) },
	{ 0xbe0498f3, __VMLINUX_SYMBOL_STR(module_put) },
	{ 0xb968aca0, __VMLINUX_SYMBOL_STR(dm_cell_release_no_holder) },
	{ 0x40a9b349, __VMLINUX_SYMBOL_STR(vzalloc) },
	{ 0xe9dff136, __VMLINUX_SYMBOL_STR(mempool_alloc) },
	{ 0x842708d6, __VMLINUX_SYMBOL_STR(bdevname) },
	{ 0xa87c5b4d, __VMLINUX_SYMBOL_STR(dm_array_resize) },
	{ 0x55b4bd4d, __VMLINUX_SYMBOL_STR(dm_tm_create_with_sm) },
	{ 0xeeec26a7, __VMLINUX_SYMBOL_STR(queue_delayed_work_on) },
	{ 0x1000e51, __VMLINUX_SYMBOL_STR(schedule) },
	{ 0xf5455120, __VMLINUX_SYMBOL_STR(dm_bm_read_lock) },
	{ 0x79a38e61, __VMLINUX_SYMBOL_STR(___ratelimit) },
	{ 0xd688716b, __VMLINUX_SYMBOL_STR(dm_kcopyd_client_create) },
	{ 0x3f71faa1, __VMLINUX_SYMBOL_STR(mempool_create) },
	{ 0x2eb01e04, __VMLINUX_SYMBOL_STR(dm_deferred_set_destroy) },
	{ 0xbdfb6dbb, __VMLINUX_SYMBOL_STR(__fentry__) },
	{ 0x3ad0f55b, __VMLINUX_SYMBOL_STR(dm_bm_flush) },
	{ 0xeddb98c1, __VMLINUX_SYMBOL_STR(kmem_cache_alloc_trace) },
	{ 0x4aad52d7, __VMLINUX_SYMBOL_STR(mempool_free) },
	{ 0xd52bf1ce, __VMLINUX_SYMBOL_STR(_raw_spin_lock) },
	{ 0x9327f5ce, __VMLINUX_SYMBOL_STR(_raw_spin_lock_irqsave) },
	{ 0xa85d2821, __VMLINUX_SYMBOL_STR(kmem_cache_create) },
	{ 0xcf21d241, __VMLINUX_SYMBOL_STR(__wake_up) },
	{ 0x54f69d, __VMLINUX_SYMBOL_STR(dm_tm_pre_commit) },
	{ 0x34f22f94, __VMLINUX_SYMBOL_STR(prepare_to_wait_event) },
	{ 0x2c112836, __VMLINUX_SYMBOL_STR(dm_block_location) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0xb6d5c65d, __VMLINUX_SYMBOL_STR(dm_deferred_set_add_work) },
	{ 0x4ca9669f, __VMLINUX_SYMBOL_STR(scnprintf) },
	{ 0xebd06eaf, __VMLINUX_SYMBOL_STR(dm_bio_prison_create) },
	{ 0xfa66f77c, __VMLINUX_SYMBOL_STR(finish_wait) },
	{ 0xd091cdcf, __VMLINUX_SYMBOL_STR(dm_block_manager_create) },
	{ 0xb781414f, __VMLINUX_SYMBOL_STR(dm_put_device) },
	{ 0x1e3f728d, __VMLINUX_SYMBOL_STR(dm_block_data) },
	{ 0x2025e954, __VMLINUX_SYMBOL_STR(dm_array_info_init) },
	{ 0x2e0d2f7f, __VMLINUX_SYMBOL_STR(queue_work_on) },
	{ 0xb1425b32, __VMLINUX_SYMBOL_STR(dm_table_add_target_callbacks) },
	{ 0x47c8baf4, __VMLINUX_SYMBOL_STR(param_ops_uint) },
	{ 0xa88bd3e3, __VMLINUX_SYMBOL_STR(__init_rwsem) },
	{ 0x8ea31722, __VMLINUX_SYMBOL_STR(try_module_get) },
	{ 0x17dd39d6, __VMLINUX_SYMBOL_STR(dm_deferred_set_create) },
	{ 0xa4fd3f13, __VMLINUX_SYMBOL_STR(dm_bio_detain) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=dm-persistent-data,dm-bio-prison";


MODULE_INFO(srcversion, "93EE58CD52FCC5AD620B7A1");
