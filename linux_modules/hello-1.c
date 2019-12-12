#include <linux/init.h>
#include <linux/module.h>

static int hello_init(void) {
  /* linux kernel: no printf() scanf() */

  /* printk(): print to a file instead */
  /* - KERN_ALERT: priority of log info */
  printk(KERN_ALERT "TEST: Hello world, this is Thawee's test code\n");

  return 0;
}

static void hello_exit(void) {
  printk(KERN_ALERT "TEST: Good bye from Thawee's test code\n");
}

module_init(hello_init);

/* run whenever the module exits */
module_exit(hello_exit);
