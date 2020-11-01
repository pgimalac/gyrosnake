#include "buttons.h"
#include "led.h"
#include "stm32l4xx.h"

// button on PC13

void button_init() {
    // enable GPIOC clock
    SET_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOCEN);

    // set gpio c pin 13 as input
    CLEAR_BIT(GPIOC->MODER, GPIO_MODER_MODE13_Msk);

    // set PC13 as the input source for the interrupt
    SET_BIT(SYSCFG->EXTICR[3], SYSCFG_EXTICR4_EXTI13_PC);

    // interrupt on falling edge
    SET_BIT(EXTI->FTSR1, EXTI_FTSR1_FT13);
    // // and interrupt on rising edge
    // SET_BIT(EXTI->RTSR1, EXTI_RTSR1_RT13);

    // enable interrupts for PX13
    SET_BIT(EXTI->IMR1, EXTI_IMR1_IM13);

    NVIC_EnableIRQ(EXTI15_10_IRQn);

    // trigger the interrupt ?
    // SET_BIT(EXTI->SWIER1, EXTI_SWIER1_SWI13);
}

void EXTI15_10_IRQHandler() {
    // clear interrupt
    SET_BIT(EXTI->PR1, EXTI_PR1_PIF13);

    // toggle green led
    led_g_toggle();
}
