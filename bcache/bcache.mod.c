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
	{ 0x61b7b126, __VMLINUX_SYMBOL_STR(simple_strtoull) },
	{ 0x964b601a, __VMLINUX_SYMBOL_STR(kobject_put) },
	{ 0x9822c0cb, __VMLINUX_SYMBOL_STR(blkdev_issue_discard) },
	{ 0x53326531, __VMLINUX_SYMBOL_STR(mempool_alloc_pages) },
	{ 0x2d3385d3, __VMLINUX_SYMBOL_STR(system_wq) },
	{ 0xeb594c85, __VMLINUX_SYMBOL_STR(bio_split) },
	{ 0xb76552eb, __VMLINUX_SYMBOL_STR(kmem_cache_destroy) },
	{ 0xecea2194, __VMLINUX_SYMBOL_STR(part_round_stats) },
	{ 0x262f20a8, __VMLINUX_SYMBOL_STR(local_clock) },
	{ 0x4ca4f9d8, __VMLINUX_SYMBOL_STR(kmalloc_caches) },
	{ 0x71ccd88e, __VMLINUX_SYMBOL_STR(kobject_get) },
	{ 0xd2b09ce5, __VMLINUX_SYMBOL_STR(__kmalloc) },
	{ 0xea38ada, __VMLINUX_SYMBOL_STR(perf_tp_event) },
	{ 0x405c1144, __VMLINUX_SYMBOL_STR(get_seconds) },
	{ 0xfea376d0, __VMLINUX_SYMBOL_STR(alloc_disk) },
	{ 0x5876c094, __VMLINUX_SYMBOL_STR(up_read) },
	{ 0x26f9f3d6, __VMLINUX_SYMBOL_STR(blk_cleanup_queue) },
	{ 0x96d19383, __VMLINUX_SYMBOL_STR(__bread) },
	{ 0x4c4fef19, __VMLINUX_SYMBOL_STR(kernel_stack) },
	{ 0x3d69f5a0, __VMLINUX_SYMBOL_STR(bio_alloc_bioset) },
	{ 0xda3e43d1, __VMLINUX_SYMBOL_STR(_raw_spin_unlock) },
	{ 0xb5c51be8, __VMLINUX_SYMBOL_STR(debugfs_create_dir) },
	{ 0xd6ee688f, __VMLINUX_SYMBOL_STR(vmalloc) },
	{ 0x754d539c, __VMLINUX_SYMBOL_STR(strlen) },
	{ 0xc29bf967, __VMLINUX_SYMBOL_STR(strspn) },
	{ 0xc7a1840e, __VMLINUX_SYMBOL_STR(llist_add_batch) },
	{ 0x43a53735, __VMLINUX_SYMBOL_STR(__alloc_workqueue_key) },
	{ 0xc8b57c27, __VMLINUX_SYMBOL_STR(autoremove_wake_function) },
	{ 0x79aa04a2, __VMLINUX_SYMBOL_STR(get_random_bytes) },
	{ 0x4e68e9be, __VMLINUX_SYMBOL_STR(rb_next_postorder) },
	{ 0x7756ced9, __VMLINUX_SYMBOL_STR(downgrade_write) },
	{ 0xce6693ca, __VMLINUX_SYMBOL_STR(bd_link_disk_holder) },
	{ 0x7ab88a45, __VMLINUX_SYMBOL_STR(system_freezing_cnt) },
	{ 0x20000329, __VMLINUX_SYMBOL_STR(simple_strtoul) },
	{ 0xc0a3d105, __VMLINUX_SYMBOL_STR(find_next_bit) },
	{ 0x6b06fdce, __VMLINUX_SYMBOL_STR(delayed_work_timer_fn) },
	{ 0x5e8ba93e, __VMLINUX_SYMBOL_STR(sysfs_create_files) },
	{ 0xf087137d, __VMLINUX_SYMBOL_STR(__dynamic_pr_debug) },
	{ 0xee91879b, __VMLINUX_SYMBOL_STR(rb_first_postorder) },
	{ 0xefba93e1, __VMLINUX_SYMBOL_STR(mempool_destroy) },
	{ 0x593a99b, __VMLINUX_SYMBOL_STR(init_timer_key) },
	{ 0x797c8fa9, __VMLINUX_SYMBOL_STR(cancel_delayed_work_sync) },
	{ 0xcbbfb419, __VMLINUX_SYMBOL_STR(mutex_unlock) },
	{ 0xb573114a, __VMLINUX_SYMBOL_STR(ida_simple_get) },
	{ 0xb7067e8, __VMLINUX_SYMBOL_STR(bio_advance) },
	{ 0x703dfdb2, __VMLINUX_SYMBOL_STR(kobject_del) },
	{ 0x999e8297, __VMLINUX_SYMBOL_STR(vfree) },
	{ 0x131916df, __VMLINUX_SYMBOL_STR(debugfs_create_file) },
	{ 0x7a2af7b4, __VMLINUX_SYMBOL_STR(cpu_number) },
	{ 0xfa4f7eb4, __VMLINUX_SYMBOL_STR(blk_queue_flush) },
	{ 0x91715312, __VMLINUX_SYMBOL_STR(sprintf) },
	{ 0xd48c3f21, __VMLINUX_SYMBOL_STR(debugfs_remove_recursive) },
	{ 0x880519c1, __VMLINUX_SYMBOL_STR(kthread_create_on_node) },
	{ 0x7d11c268, __VMLINUX_SYMBOL_STR(jiffies) },
	{ 0x9eda469c, __VMLINUX_SYMBOL_STR(lookup_bdev) },
	{ 0xecd85ddb, __VMLINUX_SYMBOL_STR(bio_endio_nodec) },
	{ 0xcf2786a9, __VMLINUX_SYMBOL_STR(mutex_trylock) },
	{ 0xf96cc7e, __VMLINUX_SYMBOL_STR(down_read) },
	{ 0xe2d5255a, __VMLINUX_SYMBOL_STR(strcmp) },
	{ 0x64aa2bb6, __VMLINUX_SYMBOL_STR(kobject_create_and_add) },
	{ 0x2b5ad4ee, __VMLINUX_SYMBOL_STR(down_write_trylock) },
	{ 0x733c3b54, __VMLINUX_SYMBOL_STR(kasprintf) },
	{ 0xece784c2, __VMLINUX_SYMBOL_STR(rb_first) },
	{ 0xf432dd3d, __VMLINUX_SYMBOL_STR(__init_waitqueue_head) },
	{ 0x4f8b5ddb, __VMLINUX_SYMBOL_STR(_copy_to_user) },
	{ 0x183fa88b, __VMLINUX_SYMBOL_STR(mempool_alloc_slab) },
	{ 0xc3639d5e, __VMLINUX_SYMBOL_STR(bio_reset) },
	{ 0xd5f2172f, __VMLINUX_SYMBOL_STR(del_timer_sync) },
	{ 0x3c80c06c, __VMLINUX_SYMBOL_STR(kstrtoull) },
	{ 0x33b7a697, __VMLINUX_SYMBOL_STR(trace_define_field) },
	{ 0x2a4dcf38, __VMLINUX_SYMBOL_STR(ftrace_event_buffer_commit) },
	{ 0xf8c0f16e, __VMLINUX_SYMBOL_STR(__blkdev_driver_ioctl) },
	{ 0xe693f9c5, __VMLINUX_SYMBOL_STR(bio_init) },
	{ 0x5991219c, __VMLINUX_SYMBOL_STR(cancel_delayed_work) },
	{ 0x3721cc78, __VMLINUX_SYMBOL_STR(bd_unlink_disk_holder) },
	{ 0xfcce2ebd, __VMLINUX_SYMBOL_STR(blk_alloc_queue) },
	{ 0x11089ac7, __VMLINUX_SYMBOL_STR(_ctype) },
	{ 0x2ec1c843, __VMLINUX_SYMBOL_STR(current_task) },
	{ 0x7fde6769, __VMLINUX_SYMBOL_STR(freezing_slow_path) },
	{ 0x37befc70, __VMLINUX_SYMBOL_STR(jiffies_to_msecs) },
	{ 0xf147ecb1, __VMLINUX_SYMBOL_STR(down_trylock) },
	{ 0xbf333e27, __VMLINUX_SYMBOL_STR(__mutex_init) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0x30976d5f, __VMLINUX_SYMBOL_STR(kthread_stop) },
	{ 0x449ad0a7, __VMLINUX_SYMBOL_STR(memcmp) },
	{ 0x44b58df0, __VMLINUX_SYMBOL_STR(del_gendisk) },
	{ 0x7c1372e8, __VMLINUX_SYMBOL_STR(panic) },
	{ 0x4c9d28b0, __VMLINUX_SYMBOL_STR(phys_base) },
	{ 0xd3249e1, __VMLINUX_SYMBOL_STR(bio_clone_fast) },
	{ 0xeef9bff6, __VMLINUX_SYMBOL_STR(ida_simple_remove) },
	{ 0x479c3c86, __VMLINUX_SYMBOL_STR(find_next_zero_bit) },
	{ 0xa1c76e0a, __VMLINUX_SYMBOL_STR(_cond_resched) },
	{ 0x4d9b652b, __VMLINUX_SYMBOL_STR(rb_erase) },
	{ 0xafb0f5d2, __VMLINUX_SYMBOL_STR(blkdev_get_by_path) },
	{ 0xd985dc99, __VMLINUX_SYMBOL_STR(mempool_free_pages) },
	{ 0x50410d4e, __VMLINUX_SYMBOL_STR(debugfs_remove) },
	{ 0xbf8ba54a, __VMLINUX_SYMBOL_STR(vprintk) },
	{ 0x16305289, __VMLINUX_SYMBOL_STR(warn_slowpath_null) },
	{ 0x896ac21b, __VMLINUX_SYMBOL_STR(mutex_lock) },
	{ 0x8c03d20c, __VMLINUX_SYMBOL_STR(destroy_workqueue) },
	{ 0x68aca4ad, __VMLINUX_SYMBOL_STR(down) },
	{ 0x71a50dbc, __VMLINUX_SYMBOL_STR(register_blkdev) },
	{ 0xbe2c0274, __VMLINUX_SYMBOL_STR(add_timer) },
	{ 0x4a479984, __VMLINUX_SYMBOL_STR(generic_make_request) },
	{ 0x27edb51, __VMLINUX_SYMBOL_STR(sysfs_remove_link) },
	{ 0x8a99a016, __VMLINUX_SYMBOL_STR(mempool_free_slab) },
	{ 0xe3a53f4c, __VMLINUX_SYMBOL_STR(sort) },
	{ 0x6e5db7e4, __VMLINUX_SYMBOL_STR(up_write) },
	{ 0x95eb8512, __VMLINUX_SYMBOL_STR(kobject_add) },
	{ 0x2ed55c8e, __VMLINUX_SYMBOL_STR(down_write) },
	{ 0xf09de776, __VMLINUX_SYMBOL_STR(get_random_int) },
	{ 0xca8c76e1, __VMLINUX_SYMBOL_STR(__get_page_tail) },
	{ 0x9b52dd2d, __VMLINUX_SYMBOL_STR(bio_endio) },
	{ 0x4f0c3029, __VMLINUX_SYMBOL_STR(bio_put) },
	{ 0x992814f4, __VMLINUX_SYMBOL_STR(kobject_uevent_env) },
	{ 0x9f46ced8, __VMLINUX_SYMBOL_STR(__sw_hweight64) },
	{ 0xaf6ae696, __VMLINUX_SYMBOL_STR(kstrndup) },
	{ 0xf11543ff, __VMLINUX_SYMBOL_STR(find_first_zero_bit) },
	{ 0xac1a55be, __VMLINUX_SYMBOL_STR(unregister_reboot_notifier) },
	{ 0xb5a459dc, __VMLINUX_SYMBOL_STR(unregister_blkdev) },
	{ 0xf8d7a305, __VMLINUX_SYMBOL_STR(ftrace_event_reg) },
	{ 0x210fd9b, __VMLINUX_SYMBOL_STR(sysfs_create_link) },
	{ 0xbe0498f3, __VMLINUX_SYMBOL_STR(module_put) },
	{ 0x63d68f9d, __VMLINUX_SYMBOL_STR(submit_bio) },
	{ 0x40a9b349, __VMLINUX_SYMBOL_STR(vzalloc) },
	{ 0x48dc4149, __VMLINUX_SYMBOL_STR(__free_pages) },
	{ 0x8f54fe7e, __VMLINUX_SYMBOL_STR(blkdev_put) },
	{ 0x45ba5804, __VMLINUX_SYMBOL_STR(unregister_shrinker) },
	{ 0xe9dff136, __VMLINUX_SYMBOL_STR(mempool_alloc) },
	{ 0xdd22209, __VMLINUX_SYMBOL_STR(fs_kobj) },
	{ 0x842708d6, __VMLINUX_SYMBOL_STR(bdevname) },
	{ 0x3517383e, __VMLINUX_SYMBOL_STR(register_reboot_notifier) },
	{ 0x2daea771, __VMLINUX_SYMBOL_STR(blk_queue_make_request) },
	{ 0x93fca811, __VMLINUX_SYMBOL_STR(__get_free_pages) },
	{ 0xeeec26a7, __VMLINUX_SYMBOL_STR(queue_delayed_work_on) },
	{ 0x3bd1b1f6, __VMLINUX_SYMBOL_STR(msecs_to_jiffies) },
	{ 0x1000e51, __VMLINUX_SYMBOL_STR(schedule) },
	{ 0xd62c833f, __VMLINUX_SYMBOL_STR(schedule_timeout) },
	{ 0xa202a8e5, __VMLINUX_SYMBOL_STR(kmalloc_order_trace) },
	{ 0x68edcc89, __VMLINUX_SYMBOL_STR(put_disk) },
	{ 0x3f71faa1, __VMLINUX_SYMBOL_STR(mempool_create) },
	{ 0x155cb2eb, __VMLINUX_SYMBOL_STR(bioset_create) },
	{ 0x6b2dc060, __VMLINUX_SYMBOL_STR(dump_stack) },
	{ 0x4482cdb, __VMLINUX_SYMBOL_STR(__refrigerator) },
	{ 0x6a037cf1, __VMLINUX_SYMBOL_STR(mempool_kfree) },
	{ 0xb678366f, __VMLINUX_SYMBOL_STR(int_sqrt) },
	{ 0x507dfa5c, __VMLINUX_SYMBOL_STR(wake_up_process) },
	{ 0xbdfb6dbb, __VMLINUX_SYMBOL_STR(__fentry__) },
	{ 0xeddb98c1, __VMLINUX_SYMBOL_STR(kmem_cache_alloc_trace) },
	{ 0x4aad52d7, __VMLINUX_SYMBOL_STR(mempool_free) },
	{ 0xd52bf1ce, __VMLINUX_SYMBOL_STR(_raw_spin_lock) },
	{ 0x3928efe9, __VMLINUX_SYMBOL_STR(__per_cpu_offset) },
	{ 0x556a4898, __VMLINUX_SYMBOL_STR(ftrace_event_buffer_reserve) },
	{ 0xa5526619, __VMLINUX_SYMBOL_STR(rb_insert_color) },
	{ 0xa85d2821, __VMLINUX_SYMBOL_STR(kmem_cache_create) },
	{ 0x9c0404c1, __VMLINUX_SYMBOL_STR(__module_get) },
	{ 0x4302d0eb, __VMLINUX_SYMBOL_STR(free_pages) },
	{ 0xcf21d241, __VMLINUX_SYMBOL_STR(__wake_up) },
	{ 0x3e652c7d, __VMLINUX_SYMBOL_STR(event_triggers_call) },
	{ 0xb3f7646e, __VMLINUX_SYMBOL_STR(kthread_should_stop) },
	{ 0xa05c03df, __VMLINUX_SYMBOL_STR(mempool_kmalloc) },
	{ 0x1e047854, __VMLINUX_SYMBOL_STR(warn_slowpath_fmt) },
	{ 0x7dbce81d, __VMLINUX_SYMBOL_STR(bio_alloc_pages) },
	{ 0x9c55cec, __VMLINUX_SYMBOL_STR(schedule_timeout_interruptible) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0x69acdf38, __VMLINUX_SYMBOL_STR(memcpy) },
	{ 0xd881702e, __VMLINUX_SYMBOL_STR(trace_event_raw_init) },
	{ 0x5c8b5ce8, __VMLINUX_SYMBOL_STR(prepare_to_wait) },
	{ 0x53eb9c3, __VMLINUX_SYMBOL_STR(register_shrinker) },
	{ 0x7f24cd1d, __VMLINUX_SYMBOL_STR(add_disk) },
	{ 0x56777a, __VMLINUX_SYMBOL_STR(kobject_init) },
	{ 0xe6602e9f, __VMLINUX_SYMBOL_STR(perf_trace_buf_prepare) },
	{ 0x71e3cecb, __VMLINUX_SYMBOL_STR(up) },
	{ 0x71abd310, __VMLINUX_SYMBOL_STR(__bio_clone_fast) },
	{ 0x7628f3c7, __VMLINUX_SYMBOL_STR(this_cpu_off) },
	{ 0x88c6fce5, __VMLINUX_SYMBOL_STR(put_page) },
	{ 0x4ca9669f, __VMLINUX_SYMBOL_STR(scnprintf) },
	{ 0xfa66f77c, __VMLINUX_SYMBOL_STR(finish_wait) },
	{ 0x758a782e, __VMLINUX_SYMBOL_STR(blk_fill_rwbs) },
	{ 0xca9360b5, __VMLINUX_SYMBOL_STR(rb_next) },
	{ 0xb742fd7, __VMLINUX_SYMBOL_STR(simple_strtol) },
	{ 0x2e0d2f7f, __VMLINUX_SYMBOL_STR(queue_work_on) },
	{ 0x28318305, __VMLINUX_SYMBOL_STR(snprintf) },
	{ 0x1e3a88fb, __VMLINUX_SYMBOL_STR(trace_seq_printf) },
	{ 0xb0e602eb, __VMLINUX_SYMBOL_STR(memmove) },
	{ 0xa8f9d5a5, __VMLINUX_SYMBOL_STR(vmalloc_to_page) },
	{ 0xf186e58, __VMLINUX_SYMBOL_STR(set_blocksize) },
	{ 0x77bc13a0, __VMLINUX_SYMBOL_STR(strim) },
	{ 0x53219ee8, __VMLINUX_SYMBOL_STR(bio_copy_data) },
	{ 0xd7e56a4e, __VMLINUX_SYMBOL_STR(simple_strtoll) },
	{ 0xdf2c2742, __VMLINUX_SYMBOL_STR(rb_last) },
	{ 0x869526c5, __VMLINUX_SYMBOL_STR(zero_fill_bio) },
	{ 0x6ab31aba, __VMLINUX_SYMBOL_STR(bioset_free) },
	{ 0x624ce36c, __VMLINUX_SYMBOL_STR(ftrace_raw_output_prep) },
	{ 0xa88bd3e3, __VMLINUX_SYMBOL_STR(__init_rwsem) },
	{ 0x8ea31722, __VMLINUX_SYMBOL_STR(try_module_get) },
	{ 0x7c2d098f, __VMLINUX_SYMBOL_STR(krealloc) },
	{ 0x6c07d933, __VMLINUX_SYMBOL_STR(add_uevent_var) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "FFCCF8C8C32D31086349BD6");
