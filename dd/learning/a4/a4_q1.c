/* Create 5 character devices without cdev */

#define pr_fmt(fmt) KBUILD_MODNAME ": " fmt

#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <linux/kdev_t.h>

#define MY_CLASS_NAME  "my_class"
#define MY_DEV_NAME    "my_device"
#define MY_DEV_COUNT   5

static dev_t dev_base;
static struct class *my_class;
static struct device *my_devices[MY_DEV_COUNT];

static int __init my_mod_init(void)
{
	int ret, i;
	char dev_name[20];

	pr_info("Module loaded\n");

	/* Allocate dynamic major & minor numbers */
	ret = alloc_chrdev_region(&dev_base, 0, MY_DEV_COUNT, MY_DEV_NAME);
	if (ret < 0) {
		pr_err("Failed to allocate char device numbers\n");
		return ret;
	}

	pr_info("Allocated Major=%d Minor=%d\n",
		MAJOR(dev_base), MINOR(dev_base));

	/* Create device class */
	my_class = class_create(THIS_MODULE, MY_CLASS_NAME);
	if (IS_ERR(my_class)) {
		pr_err("Failed to create class\n");
		ret = PTR_ERR(my_class);
		goto err_class;
	}

	/* Create 5 devices: my_deviceA .. my_deviceE */
	for (i = 0; i < MY_DEV_COUNT; i++) {
		snprintf(dev_name, sizeof(dev_name),
			 "%s%c", MY_DEV_NAME, 'A' + i);

		my_devices[i] =
			device_create(my_class,
				      NULL,
				      MKDEV(MAJOR(dev_base),
					    MINOR(dev_base) + i),
				      NULL,
				      dev_name);

		if (IS_ERR(my_devices[i])) {
			pr_err("Failed to create device %s\n", dev_name);
			ret = PTR_ERR(my_devices[i]);
			goto err_device;
		}

		pr_info("Created /dev/%s\n", dev_name);
	}

	return 0;

/* Error handling */
err_device:
	while (--i >= 0)
		device_destroy(my_class,
			       MKDEV(MAJOR(dev_base),
				     MINOR(dev_base) + i));

	class_destroy(my_class);

err_class:
	unregister_chrdev_region(dev_base, MY_DEV_COUNT);
	return ret;
}

static void __exit my_mod_exit(void)
{
	int i;

	pr_info("Module unloading\n");

	for (i = 0; i < MY_DEV_COUNT; i++) {
		device_destroy(my_class,
			       MKDEV(MAJOR(dev_base),
				     MINOR(dev_base) + i));
	}

	class_destroy(my_class);
	unregister_chrdev_region(dev_base, MY_DEV_COUNT);

	pr_info("Resources freed\n");
}

module_init(my_mod_init);
module_exit(my_mod_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("LKM creating 5 devices using dynamic major/minor");

