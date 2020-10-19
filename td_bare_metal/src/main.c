#include "clocks.h"
#include "led.h"
#include "uart.h"

#define WAIT_TIME 10000000

void sleep() {
    for (uint32_t i = 0; i < WAIT_TIME; i++)
        asm volatile("nop");
}

#define SIZE 4
int main() {
    clocks_init();
    uart_init();

    uint8_t buffer[SIZE + 1];

    while (1) {
        uart_gets(buffer, SIZE);

        uart_puts(buffer);

        sleep();
    }

    return 0;
}
