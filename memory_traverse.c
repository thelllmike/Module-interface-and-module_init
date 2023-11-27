#include <linux/module.h>
#include <linux/sched/signal.h>
#include <linux/mm.h>

void traverse_memory_regions(void) {
    struct task_struct *task = current;
    struct mm_struct *mm = task->mm;
    struct vm_area_struct *vma = NULL;

    if (mm) {
        down_read(&mm->mmap_sem);  // Lock the memory map
        for (vma = mm->mmap; vma; vma = vma->vm_next) {
            printk(KERN_INFO "VMA starts at 0x%lx and ends at 0x%lx\n", vma->vm_start, vma->vm_end);
        }
        up_read(&mm->mmap_sem);  // Unlock the memory map
    }
}

int init_module(void) {
    printk(KERN_INFO "Module loading...\n");
    traverse_memory_regions();
    return 0;
}

void cleanup_module(void) {
    printk(KERN_INFO "Module removed\n");
}

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("Memory Region Traversal Module");

