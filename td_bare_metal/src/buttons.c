#include "buttons.h"
#include "stm32l4xx.h"

void button_init() {
    // enable GPIOC clock
    SET_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOCEN);

    // set pin 13 as output
    CLEAR_BIT(GPIOC->MODER, GPIO_MODER_MODE13_Msk);
}
