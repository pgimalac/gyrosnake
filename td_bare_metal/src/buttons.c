#include "buttons.h"
#include "stm32l4xx.h"

// button on PC13

void button_init() {
    // enable GPIOC clock
    SET_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOCEN);

    // set pin 13 as output
    CLEAR_BIT(GPIOC->MODER, GPIO_MODER_MODE13_Msk);

    // enable interrupts for PX13
    SET_BIT(EXTI->IMR1, EXTI_IMR1_IM13);

    // set PC13 as the input source for the interrupt
    SET_BIT(SYSCFG->EXTICR4, SYSCFG_EXTICR4_EXTI13_PC);

    // interrupt on falling edge
    SET_BIT(EXTI->FTSR1, EXTI_FTSR1_FT13);
}
