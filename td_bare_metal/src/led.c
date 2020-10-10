#include "led.h"

void led_init() {
    // enable GPIO port B clock
    set_bit(RCC_AHB2ENR, RCC_AHB2ENR_B);

    set_as_output(&GPIOB_MODER, P14);
}

void led_g_on() {
    //TODO
}
void led_g_off() {
    //TODO
}
