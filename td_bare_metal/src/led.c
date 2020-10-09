#include "led.h"

void led_init() {
    // enable GPIO port B clock
    RCC_AHB2ENR |= 1 << RCC_AHB2ENR_B;
}

void led_g_on() {
    //TODO
}
void led_g_off() {
    //TODO
}
