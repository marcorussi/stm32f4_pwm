# STM32F4_PWM
A simple PWM driver implemented on top of libopencm3 library. It includes a demo application for STM32F4 Discovery board that drives the LEDs by varying their illumination in a loop.

For compiling the project it is necessary to download the libopencm3 library https://github.com/libopencm3/libopencm3. This project folder must be located in the same folder where libopencm3 is located. For compiling the project run:

    $ make

and for flashing the STM32F4Discovery board run:

    $ make flash

The default toolchain is the same of libopencm3, an arm-none-eabi/arm-elf toolchain.

