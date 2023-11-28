#include <linux/hrtimer.h>
#include <linux/ktime.h>
#include <linux/module.h>
#include <linux/sched/signal.h>
#include <linux/mm.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("A Kernel Module to monitor process memory stats");

static struct hrtimer hr_timer;
ktime_t interval;
static unsigned long timer_interval_ns = 10 * 1000000000L; // 10 seconds

// Dummy PID - replace with the target process PID
static const pid_t target_pid = 1234;

enum hrtimer_restart timer_callback(struct hrtimer *timer) {
    struct task_struct *task;
    struct mm_struct *mm;
    long rss = 0, swap = 0, wss = 0; // Variables for memory measurements

    // Find the task_struct associated with the given PID
    rcu_read_lock();
    task = pid_task(find_vpid(target_pid), PIDTYPE_PID);
    if (task && task->mm) {
        mm = task->mm;
        rss = get_mm_rss(mm) << (PAGE_SHIFT - 10); // Convert pages to KB
        // Swap and WSS calculation goes here (if needed)
    }
    rcu_read_unlock();

    printk(KERN_INFO "PID %d: RSS=%ld KB, SWAP=%ld KB, WSS=%ld KB\n", target_pid, rss, swap, wss);

    hrtimer_forward_now(timer, interval);
    return HRTIMER_RESTART;
}

static int __init process_stats_init(void) {
    interval = ktime_set(0, timer_interval_ns);
    hrtimer_init(&hr_timer, CLOCK_MONOTONIC, HRTIMER_MODE_REL);
    hr_timer.function = &timer_callback;
    hrtimer_start(&hr_timer, interval, HRTIMER_MODE_REL);

    printk(KERN_INFO "Process Stats Module loaded\n");
    return 0;
}

static void __exit process_stats_exit(void) {
    int ret = hrtimer_cancel(&hr_timer);
    if (ret)
        printk(KERN_INFO "The timer was in use...\n");

    printk(KERN_INFO "Process Stats Module unloaded\n");
}

module_init(process_stats_init);
module_exit(process_stats_exit);
