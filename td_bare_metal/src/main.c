#include "clocks.h"
#include "led.h"
#include "matrix.h"
#include "uart.h"
#include "utils.h"

#define N 1000

int main() {
    clocks_init();
    uart_init();
    matrix_init();

    return 0;
}
