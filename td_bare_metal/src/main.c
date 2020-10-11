#include "led.h"

#define WAIT_TIME 10000

int main() {
    led_init();
    led_g_on();

    while(1) {}

    return 0;
}
