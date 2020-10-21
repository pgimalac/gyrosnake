#include "utils.h"
#include <stdint.h>

#define WAIT_TIME 10000000

void sleep() {
    for (uint32_t i = 0; i < WAIT_TIME; i++)
        asm volatile("nop");
}
