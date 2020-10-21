#include "matrix.h"
#include "gpio.h"
#include "stm32l4xx.h"

void matrix_init() {
    // enable gpio A
    enable_clock_gpio(RCC_AHB2ENR_GPIOAEN);
    // enable gpio B
    enable_clock_gpio(RCC_AHB2ENR_GPIOBEN);
    // enable gpio C
    enable_clock_gpio(RCC_AHB2ENR_GPIOCEN);

    //
}
