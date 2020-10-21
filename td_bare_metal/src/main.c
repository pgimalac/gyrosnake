#include "clocks.h"
#include "led.h"
#include "uart.h"
#include "utils.h"

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
