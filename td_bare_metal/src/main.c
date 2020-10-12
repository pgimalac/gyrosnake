#include "led.h"
#include "clocks.h"

#define WAIT_TIME 10000000

void sleep() {
    for (uint32_t i = 0; i < WAIT_TIME; i++)
        asm volatile("nop");
}

int main() {
    clocks_init();
    led_init();

    while(1) {
        led_b_y_off();
        led_g_on();

        sleep();

        led_g_off();
        led_y_on();

        sleep();

        led_b_y_off();
        led_b_on();

        sleep();
    }

    return 0;
}
