#include "led.h"

#include "stm32l4xx.h"

void led_init() {
    enable_clock_gpio(RCC_AHB2ENR_GPIOBEN);
    set_as_output(&GPIOB->MODER, GPIO_MODER_MODE14_0, GPIO_MODER_MODE14_1);

    enable_clock_gpio(RCC_AHB2ENR_GPIOCEN);
    set_as_output(&GPIOC->MODER, GPIO_MODER_MODE9_0, GPIO_MODER_MODE9_1);
}

void led_b_on() {
    set_as_output(&GPIOC->MODER, GPIO_MODER_MODE9_0, GPIO_MODER_MODE9_1);
    SET_BIT(GPIOC->BSRR, GPIO_BSRR_BR9);
}

void led_b_y_off() {
    set_as_input(&GPIOC->MODER, GPIO_MODER_MODE9_0, GPIO_MODER_MODE9_1);
}

void led_y_on() {
    set_as_output(&GPIOC->MODER, GPIO_MODER_MODE9_0, GPIO_MODER_MODE9_1);
    SET_BIT(GPIOC->BSRR, GPIO_BSRR_BS9);
}

void led_g_on() {
    SET_BIT(GPIOB->BSRR, GPIO_BSRR_BS14);
}

void led_g_off() {
    SET_BIT(GPIOB->BSRR, GPIO_BSRR_BR14);
}
