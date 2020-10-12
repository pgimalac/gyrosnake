#include "led.h"

void led_init() {
    // enable GPIO port B clock
    set_bit(RCC_AHB2ENR, RCC_AHB2ENR_B);

    // set pin 14 of gpio b as output
    set_as_output(&GPIOB_MODER, P14);
}

void led_g_on() {
    // GPIOx_BSRR[15:0] to set
    set_bit(GPIOB_BSRR, P14);
}

void led_g_off() {
    // GPIOx_BSRR[31:16] to reset
    // hence + 16
    set_bit(GPIOB_BSRR, P14 + 16);
}
