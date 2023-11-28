#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/export-internal.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif


static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x2d0684a9, "hrtimer_init" },
	{ 0x3c5d543a, "hrtimer_start_range_ns" },
	{ 0x122c3a7e, "_printk" },
	{ 0x5b8239ca, "__x86_return_thunk" },
	{ 0x46a4b118, "hrtimer_cancel" },
	{ 0x8d522714, "__rcu_read_lock" },
	{ 0x1499307a, "find_vpid" },
	{ 0x92e71f2, "pid_task" },
	{ 0x2469810f, "__rcu_read_unlock" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x828e22f4, "hrtimer_forward" },
	{ 0x453e7dc, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "6379A1FCE8C64624B3E4C20");
