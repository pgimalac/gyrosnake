#include "led.h"

#define WAIT_TIME 1000000

int main() {
    led_init();

    while(1) {
        led_g_on();

        for (uint32_t i = 0; i < WAIT_TIME; i++)
            asm volatile("nop");

        led_g_off();

        for (uint32_t i = 0; i < WAIT_TIME; i++)
            asm volatile("nop");
    }

    return 0;
}
