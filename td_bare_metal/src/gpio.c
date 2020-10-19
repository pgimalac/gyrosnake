#include "gpio.h"

#include "stm32l4xx.h"

void set_as_input(ptr_t gpio_moder, uint32_t bit_0, uint32_t bit_1) {
    uint32_t val = *gpio_moder;

    CLEAR_BIT(val, bit_0);
    CLEAR_BIT(val, bit_1);

    *gpio_moder = val;
}

void set_as_output(ptr_t gpio_moder, uint32_t bit_0, uint32_t bit_1) {
    uint32_t val = *gpio_moder;

    SET_BIT(val, bit_0);
    CLEAR_BIT(val, bit_1);

    *gpio_moder = val;
}
