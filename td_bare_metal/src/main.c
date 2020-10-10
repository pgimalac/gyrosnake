#include "led.h"

#define WAIT_TIME 10000

int main() {
    led_init();

    while(1) {
        led_g_on();

        for(int i = 0; i < WAIT_TIME; i++){}

        led_g_off();

        for(int i = 0; i < WAIT_TIME; i++){}
    }

    return 0;
}
