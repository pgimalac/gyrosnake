#include "led.h"

#include "stm32l4xx.h"

void led_init() {
    // green led
    SET_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOBEN);
    GPIOB->MODER =
        (GPIOB->MODER & ~GPIO_MODER_MODE14_Msk) | GPIO_MODER_MODE14_0;

    // yellow and blue led
    SET_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOCEN);
    CLEAR_BIT(GPIOC->MODER, GPIO_MODER_MODE9_Msk);
}

void led_b_on() {
    GPIOC->MODER = (GPIOC->MODER & ~GPIO_MODER_MODE9_Msk) | GPIO_MODER_MODE9_0;
    SET_BIT(GPIOC->BSRR, GPIO_BSRR_BR9);
}

void led_b_y_off() { CLEAR_BIT(GPIOC->MODER, GPIO_MODER_MODE9_Msk); }

void led_y_on() {
    GPIOC->MODER = (GPIOC->MODER & ~GPIO_MODER_MODE9_Msk) | GPIO_MODER_MODE9_0;
    SET_BIT(GPIOC->BSRR, GPIO_BSRR_BS9);
}

void led_g_on() { SET_BIT(GPIOB->BSRR, GPIO_BSRR_BS14); }

void led_g_off() { SET_BIT(GPIOB->BSRR, GPIO_BSRR_BR14); }
