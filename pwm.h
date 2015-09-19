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




/* ----------- Exported defines ------------- */

/* Maximum PWM frequency */
#define PWM_MAX_FREQ_HZ					100000	/* 100kHz */

/* Channels indexes defines */
#define PWM_CH1							0
#define PWM_CH2							1
#define PWM_CH3							2
#define PWM_CH4							3




/* ----------- Exported functions prototypes ------------- */

extern void pwm_init(void);
extern void pwm_set_frequency(uint32_t);
extern void pwm_set_dc(uint8_t, uint16_t);
extern void pwm_start(void);




/* End of file */

