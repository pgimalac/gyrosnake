#include "led.h"

static void led_init_spec(ptr_t moder, int port, int pin) {
    // enable GPIO port B clock
    set_bit(RCC_AHB2ENR, port);

    // set pin 14 of gpio b as output
    set_as_output(moder, pin);
}

void led_init() {
    led_init_spec(&GPIOB_MODER, RCC_AHB2ENR_B, P14);
    led_init_spec(&GPIOC_MODER, RCC_AHB2ENR_C, P09);
}

void led_b_on() {
    set_as_output(&GPIOC_MODER, P09);
    set_bit(GPIOC_BSRR, P09 + 16);
}

void led_b_off() {
    set_as_input(&GPIOC_MODER, P09);
}

void led_y_on() {
    set_as_output(&GPIOC_MODER, P09);
    set_bit(GPIOC_BSRR, P09);
}

void led_y_off() {
    set_as_input(&GPIOC_MODER, P09);
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
