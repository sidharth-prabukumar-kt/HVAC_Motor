#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/drivers/pwm.h>

#define DT_ALIAS_PWM_0_LABEL "PWM_1"

/* period of motor signal ->  20ms (50Hz) */
#define PERIOD (NSEC_PER_SEC / 50U)

#define SLEEP_TIME_MS 500  /* Pause time in seconds*/

void main(void)
{
	printk("HVAC Motor Control - PWM Test\n");

    const struct device *pwm_dev;

	pwm_dev = device_get_binding(DT_ALIAS_PWM_0_LABEL);
	if (!pwm_dev)
	{
		printk("Cannot find PWM device!\n");
		return;
	}
	else
	{
		printk("PWM device find\n");
		printk("%s\n", DT_ALIAS_PWM_0_LABEL);
	}
	printk("PWM device cycle 1\n");
	if (pwm_set(pwm_dev, 1, PERIOD, (PERIOD * 0.9), 0))
	{
		printk("PWM pin set fails\n");
		return;
	}
	printk("PWM device cycle 2\n");
	if (pwm_set(pwm_dev, 2, PERIOD, (PERIOD * 0.5), 0))
	{
		printk("PWM pin set fails\n");
		return;
	}
	printk("PWM device cycle 3\n");
	if (pwm_set(pwm_dev, 3, PERIOD, (PERIOD * 0.3), 0))
	{
		printk("PWM pin set fails\n");
		return;
	}
    printk("Running...\n");

}
