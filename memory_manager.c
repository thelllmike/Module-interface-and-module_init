#include <linux/module.h>  // Needed by all modules
#include <linux/kernel.h>  // Needed for KERN_INFO
#include <linux/init.h>    // Needed for the macros

static int pid = 0;  // Default value for pid
module_param(pid, int, S_IRUGO); // Module parameter for pid, readable by all users in sysfs

// Initialization function of the module
static int __init memory_manager_init(void) {
    printk(KERN_INFO "Memory Manager: Loaded with pid %d\n", pid);
    // Your initialization code here (if needed)
    return 0;  // Return 0 indicates success
}

// Cleanup function of the module
static void __exit memory_manager_exit(void) {
    printk(KERN_INFO "Memory Manager: Unloaded\n");
    // Your cleanup code here (if needed)
}

module_init(memory_manager_init);  // Macro to declare the initialization function
module_exit(memory_manager_exit);  // Macro to declare the cleanup function

MODULE_LICENSE("GPL");  // Declares the license of the module
MODULE_AUTHOR("Your Name");  // Optional: Author name
MODULE_DESCRIPTION("A simple Linux kernel module for memory management");  // Optional: Description
MODULE_VERSION("0.1");  // Optional: Module version

