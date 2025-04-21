// SPDX-License-Identifier: GPL-2.0
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/utsname.h>
#include <linux/timekeeping.h>

static char *who = "World";
module_param(who, charp, 0000);
MODULE_PARM_DESC(who, "Who to greet");

static unsigned long load_time;

static int __init hello_init(void)
{
	struct new_utsname *u = utsname();

	load_time = ktime_get_seconds();

	pr_info("Hello %s. You are currently using Linux %s.\n", who, u->release);

	return 0;
}

static void __exit hello_exit(void)
{
	unsigned long unload_time = ktime_get_seconds();
	unsigned long elapsed = unload_time - load_time;

	pr_info("Goodbye %s! Module was loaded for %lu seconds.\n", who, elapsed);
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Martin Cvitic");
MODULE_DESCRIPTION("Kernel module to greet and show version and uptime");
MODULE_VERSION("1.1");

