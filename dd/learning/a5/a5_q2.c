#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/kthread.h>
#include <linux/delay.h>
#include <linux/sched.h>

#define MIN_THREADS 1
#define MAX_THREADS 10

static int num_threads = 1;
module_param(num_threads, int, 0444);
MODULE_PARM_DESC(num_threads, "Number of kernel threads (1-10)");

static struct task_struct *threads[MAX_THREADS];

/* Kernel thread function */
static int thread_fn(void *data)
{
    int id = *(int *)data;

    while (!kthread_should_stop()) {
        pr_info("my_module: kernel thread %d running (PID=%d)\n",
                id, current->pid);
        ssleep(1);
    }

    pr_info("my_module: kernel thread %d stopping\n", id);
    return 0;
}

/* Module initialization */
static int __init my_module_init(void)
{
    int i;
    static int thread_ids[MAX_THREADS];

    if (num_threads < MIN_THREADS || num_threads > MAX_THREADS) {
        pr_err("my_module: num_threads must be between %d and %d\n",
               MIN_THREADS, MAX_THREADS);
        return -EINVAL;
    }

    pr_info("my_module: loading with %d kernel threads\n", num_threads);

    for (i = 0; i < num_threads; i++) {
        thread_ids[i] = i;

        threads[i] = kthread_run(thread_fn, &thread_ids[i],
                                 "my_kthread_%d", i);
        if (IS_ERR(threads[i])) {
            pr_err("my_module: failed to create thread %d\n", i);
            threads[i] = NULL;
            goto cleanup;
        }
    }

    return 0;

cleanup:
    while (--i >= 0) {
        if (threads[i])
            kthread_stop(threads[i]);
    }
    return -ENOMEM;
}

/* Module cleanup */
static void __exit my_module_exit(void)
{
    int i;

    pr_info("my_module: unloading\n");

    for (i = 0; i < num_threads; i++) {
        if (threads[i]) {
            kthread_stop(threads[i]);
            threads[i] = NULL;
        }
    }

    pr_info("my_module: all kernel threads stopped\n");
}

module_init(my_module_init);
module_exit(my_module_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("LKM that creates kernel threads on demand");

