#ifndef UTILS_H
#define UTILS_H

#include <stdint.h>

typedef struct {
    uint8_t r;
    uint8_t g;
    uint8_t b;
} rgb_color;

void sleep(uint32_t);

#endif
