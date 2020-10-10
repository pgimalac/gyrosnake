#include "led.h"

int main() {
    volatile uint32_t *ptr0 = GPIO_B_ADDR;
    volatile uint32_t *ptr1 = GPIO_B_ADDR + OFFSET_MODER;
    volatile uint32_t *ptr2 = 0;

    ptr0 = ptr0;
    ptr1 = ptr1;
    ptr2 = ptr2;

    return 0;
}
