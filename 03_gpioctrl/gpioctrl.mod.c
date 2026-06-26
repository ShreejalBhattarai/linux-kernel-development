#include <linux/module.h>
#include <linux/export-internal.h>
#include <linux/compiler.h>

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



static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x92997ed8, "_printk" },
	{ 0x1983ecbd, "gpiod_set_value" },
	{ 0x4310d28d, "gpio_to_desc" },
	{ 0x1f7e849c, "gpiod_direction_output" },
	{ 0x5426307b, "gpiod_direction_input" },
	{ 0x77613bf4, "gpiod_get_value" },
	{ 0x91d66ee9, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "8B1D3763B3C3AA440AB6903");
