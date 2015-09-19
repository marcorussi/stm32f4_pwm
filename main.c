/*
* The MIT License (MIT)
*
* Copyright (c) 2015 Marco Russi
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*/


/* ---------------- Inclusions ----------------- */

#include <stdint.h>
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
/* PWM module */
#include "pwm.h"




/* ------------- Local functions prototypes --------------- */

/* Store current PWM DC value */
static uint16_t pwm_dc_value = 0;




/* ------------- Local functions prototypes --------------- */

static void clock_setup(void);
static void pwm_demo(void);




/* ------------ Local functions implementation ----------- */

/* Function to setup the clock device */
static void clock_setup(void)
{
	rcc_clock_setup_hse_3v3(&hse_8mhz_3v3[CLOCK_3V3_168MHZ]);
}


/* Function to run a PWM demo */
static void pwm_demo(void)
{
	pwm_dc_value++;
	if (pwm_dc_value > 2000)
	{
		pwm_dc_value = 0;
	}

	if (pwm_dc_value <= 1000)
	{
		pwm_set_dc(PWM_CH1, pwm_dc_value);
		pwm_set_dc(PWM_CH2, (1000 - pwm_dc_value));
		pwm_set_dc(PWM_CH3, pwm_dc_value);
		pwm_set_dc(PWM_CH4, (1000 - pwm_dc_value));
	}
	else
	{
		pwm_set_dc(PWM_CH1, (2000 - pwm_dc_value));
		pwm_set_dc(PWM_CH2, (pwm_dc_value - 1000));
		pwm_set_dc(PWM_CH3, (2000 - pwm_dc_value));
		pwm_set_dc(PWM_CH4, (pwm_dc_value - 1000));
	}

	
}


/* Main function */
int main(void)
{
	int i;

	/* setup clock */
	clock_setup();

	pwm_init();
	pwm_set_frequency(1000);
	pwm_set_dc(PWM_CH1, 0);
	pwm_set_dc(PWM_CH2, 0);
	pwm_set_dc(PWM_CH3, 0);
	pwm_set_dc(PWM_CH4, 0);
	pwm_start();

	/* infinite loop */
	while (1) {
		/* call PWM demo */
		pwm_demo();

		/* Wait a bit... */
		for (i = 0; i < 20000; i++)
		{
			__asm__("nop");
		}
	}

	return 0;
}




/* End of file */
