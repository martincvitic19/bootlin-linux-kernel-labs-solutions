
// SPDX-License-Identifier: GPL-2.0
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/utsname.h>  // for utsname()

static int __init hello_init(void)
{
    struct new_utsname *u = utsname();
    printk(KERN_INFO "Hello World. You are currently using Linux %s.\n", u->release);
    return 0;
}

static void __exit hello_exit(void)
{
    printk(KERN_INFO "Goodbye! Unloading the hello_version module.\n");
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Martin Cvitic");
MODULE_DESCRIPTION("Kernel module to display runtime Linux version info");
MODULE_VERSION("1.0");
