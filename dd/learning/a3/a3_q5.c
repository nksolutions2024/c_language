#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/moduleparam.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("LKM with module parameters and callback");
MODULE_VERSION("1.0");

/* ------------------------------------------------ */
/* Parameter 1: Integer                             */
/* ------------------------------------------------ */
static int myint = 100;
module_param(myint, int, 0644);
MODULE_PARM_DESC(myint, "An integer parameter with default value 100");

/* ------------------------------------------------ */
/* Parameter 2: Integer Array                       */
/* ------------------------------------------------ */
static int myintarray[5];
static int arr_argc = 0;

module_param_array(myintarray, int, &arr_argc, 0644);
MODULE_PARM_DESC(myintarray, "An array of integers (default all 0)");

/* ------------------------------------------------ */
/* Parameter 3: Integer with Callback               */
/* ------------------------------------------------ */
static int myint_callback = 200;

/* Callback function */
static int myint_callback_set(const char *val,
                              const struct kernel_param *kp)
{
    int ret;

    pr_info("Attempting to change myint_callback...\n");

    /* Use the standard setter */
    ret = param_set_int(val, kp);
    if (ret == 0)
        pr_info("myint_callback successfully changed to %d\n",
                myint_callback);

    return ret;
}

/* Callback operations structure */
static const struct kernel_param_ops myint_callback_ops = {
    .set = myint_callback_set,
    .get = param_get_int,
};

/* Register callback parameter */
module_param_cb(myint_callback, &myint_callback_ops,
                &myint_callback, 0644);
MODULE_PARM_DESC(myint_callback,
                 "An integer parameter with callback (default 200)");

/* ------------------------------------------------ */
/* Module Init / Exit                               */
/* ------------------------------------------------ */
static int __init mymodule_init(void)
{
    int i;

    pr_info("LKM loaded\n");
    pr_info("myint = %d\n", myint);
    pr_info("myint_callback = %d\n", myint_callback);

    for (i = 0; i < arr_argc; i++)
        pr_info("myintarray[%d] = %d\n", i, myintarray[i]);

    return 0;
}

static void __exit mymodule_exit(void)
{
    pr_info("LKM unloaded\n");
}

module_init(mymodule_init);
module_exit(mymodule_exit);

