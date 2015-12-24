#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

__visible struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.arch = MODULE_ARCH_INIT,
};

MODULE_INFO(intree, "Y");

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x8b325cc0, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0x4ca4f9d8, __VMLINUX_SYMBOL_STR(kmalloc_caches) },
	{ 0xda3e43d1, __VMLINUX_SYMBOL_STR(_raw_spin_unlock) },
	{ 0x74dcd98c, __VMLINUX_SYMBOL_STR(dm_bufio_get_aux_data) },
	{ 0x9c256008, __VMLINUX_SYMBOL_STR(dm_bufio_get_device_size) },
	{ 0xafbda3f3, __VMLINUX_SYMBOL_STR(dm_bufio_new) },
	{ 0xa82b2066, __VMLINUX_SYMBOL_STR(dm_bufio_write_dirty_buffers) },
	{ 0x27000b29, __VMLINUX_SYMBOL_STR(crc32c) },
	{ 0xfb578fc5, __VMLINUX_SYMBOL_STR(memset) },
	{ 0x7c381a76, __VMLINUX_SYMBOL_STR(dm_bufio_get_block_size) },
	{ 0x2ec1c843, __VMLINUX_SYMBOL_STR(current_task) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0x449ad0a7, __VMLINUX_SYMBOL_STR(memcmp) },
	{ 0xb138d0bf, __VMLINUX_SYMBOL_STR(dm_ratelimit_state) },
	{ 0xe6024e59, __VMLINUX_SYMBOL_STR(dm_bufio_release) },
	{ 0x486e239f, __VMLINUX_SYMBOL_STR(dm_bufio_client_create) },
	{ 0xebcc64a4, __VMLINUX_SYMBOL_STR(dm_bufio_get_block_data) },
	{ 0xeca7949e, __VMLINUX_SYMBOL_STR(dm_bufio_client_destroy) },
	{ 0x6aba7f5e, __VMLINUX_SYMBOL_STR(dm_bufio_get_block_number) },
	{ 0x1000e51, __VMLINUX_SYMBOL_STR(schedule) },
	{ 0x79a38e61, __VMLINUX_SYMBOL_STR(___ratelimit) },
	{ 0xa202a8e5, __VMLINUX_SYMBOL_STR(kmalloc_order_trace) },
	{ 0x507dfa5c, __VMLINUX_SYMBOL_STR(wake_up_process) },
	{ 0xbdfb6dbb, __VMLINUX_SYMBOL_STR(__fentry__) },
	{ 0xeddb98c1, __VMLINUX_SYMBOL_STR(kmem_cache_alloc_trace) },
	{ 0xd52bf1ce, __VMLINUX_SYMBOL_STR(_raw_spin_lock) },
	{ 0xa1d2413a, __VMLINUX_SYMBOL_STR(dm_bufio_read) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0x69acdf38, __VMLINUX_SYMBOL_STR(memcpy) },
	{ 0xad0dc4f, __VMLINUX_SYMBOL_STR(dm_bufio_mark_buffer_dirty) },
	{ 0xcbb1bae2, __VMLINUX_SYMBOL_STR(dm_bufio_get) },
	{ 0x386e3aa9, __VMLINUX_SYMBOL_STR(__put_task_struct) },
	{ 0xa448e19f, __VMLINUX_SYMBOL_STR(dm_bufio_prefetch) },
	{ 0x6d3f57bd, __VMLINUX_SYMBOL_STR(dm_bufio_get_client) },
	{ 0xb0e602eb, __VMLINUX_SYMBOL_STR(memmove) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=dm-bufio,libcrc32c";


MODULE_INFO(srcversion, "176289007C8C55146BC749B");
