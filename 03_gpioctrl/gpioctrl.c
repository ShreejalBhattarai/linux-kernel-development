#include <linux/module.h>
#include <linux/init.h>
#include <linux/gpio/consumer.h>

static struct gpio_desc *led,*button;

#define IO_LED 21
#define IO_BUTTON 20
#define IO_OFFSET 0


static int __init my_init(void)
{
	int status;
	led = gpio_to_desc(IO_LED+IO_OFFSET);
	if (!led) {
			printk("gpioctrl - Error getting pin 21\n");
			return -ENODEV;
		}
	 button = gpio_to_desc(IO_BUTTON+IO_OFFSET);
         if (!button) {
                        printk("gpioctrl - Error getting pin 20\n");
                        return -ENODEV;
        }
	status = gpiod_direction_output(led, 0);
	if (status){
		printk("gpiotrl - Error setting pin 20 to output");
		return status;	
	}

	status = gpiod_direction_input(button);
        if (status){
                printk("gpicotrl - Error setting pin 21 to output");
                return status;  
        }


	gpiod_set_value(led, 1);
	printk("Button %s is pressed\n", gpiod_get_value(button)?"":"not");


	return 0;
}
static void __exit my_exit(void)
{
	printk("hello- Goodbye, Kernel!\n");
	gpiod_set_value(led, 0);
}

module_init(my_init);
module_exit(my_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Shreejal Bhattarai");
MODULE_DESCRIPTION("Using GPIO using device tree");
