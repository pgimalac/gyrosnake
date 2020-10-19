#include "clocks.h"
#include "led.h"
#include "uart.h"

#define WAIT_TIME 10000000

void sleep() {
    for (uint32_t i = 0; i < WAIT_TIME; i++)
        asm volatile("nop");
}

#define N 1000

int main() {
    clocks_init();
    uart_init();

    uint32_t sum = 0;
    for (int i = 0; i < N; i++) {
        sum += uart_getchar();
    }

    return sum;
}
