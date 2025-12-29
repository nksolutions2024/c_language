/* Interrupt handling using GPIO */

#define pr_fmt(fmt)	KBUILD_MODNAME ": " fmt

#include <linux/init.h>
#include <linux/module.h>
#include <linux/gpio.h>       
#include <linux/kobject.h>   
#include <linux/interrupt.h>
		
// button related
static unsigned int gpioButton = 46; // P8_16
static unsigned int irqNumber;	     // mapped to gpioButton
static unsigned int numPresses = 0;

//called when interrupt occurs
static irq_handler_t button_handler(unsigned int irq, void *dev_id, struct pt_regs *regs)
{
   pr_info("Button press interrupt!\n");
   numPresses++;

   return (irq_handler_t) IRQ_HANDLED;//inform the kernel ; pending interrupt
}

static int __init my_init(void){
   int result = 0;

   pr_info("Setting up IRQ for GPIO %d for button\n", gpioButton);

   if (!gpio_is_valid(gpioButton))
   {
      pr_err("Invalid GPIO for button!\n");
      return -ENODEV; //??
   }

   gpio_request(gpioButton, "sysfs"); 
   gpio_direction_input(gpioButton); // input kkkkkkkkkkkkk debouncing
   gpio_set_debounce(gpioButton , 200);
   irqNumber = gpio_to_irq(gpioButton);//converts the gpio into an IRQ number used by interrupt 
   pr_info("GPIO %d mapped to IRQ number %d\n", gpioButton, irqNumber);

   gpio_export(gpioButton, false);  		// export in /sys/class/gpio/...
// false ; users cannot change direction from userspace

   //registers the interrrupt handler with the kernel
   //specific ISR function
   // ORed with falling
   // my button handler in /procs/interrupts
   //  no device-specific data passed
   result = request_irq(irqNumber, 
		   	(irq_handler_t) button_handler,
			IRQF_TRIGGER_RISING,      
			"my_button_handler",
			NULL);

   return result;//not loading module
}

static void __exit my_exit(void)
{
   free_irq(irqNumber, NULL);
   gpio_unexport(gpioButton);    //removes GPIO from /sys/class/gpio/              
   gpio_free(gpioButton);       //releases GPIO so other driver an use it               
   pr_info("GPIO %d freed up\n", gpioButton);

   pr_info("%d button presses were detected!\n", numPresses); //obvious
   pr_info("Good bye from %s!\n", KBUILD_MODNAME);
}

module_init(my_init);
module_exit(my_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("CDAC EDD <edd@cdac.gov.in>");
MODULE_DESCRIPTION("A simple interrupt driver using GPIO button");
