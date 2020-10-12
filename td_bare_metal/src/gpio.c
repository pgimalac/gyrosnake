#include "gpio.h"

void set_as_input(ptr_t gpio_moder, int pin) {
    uint32_t val = *gpio_moder;

    unset_bit(val, pin * 2 + 1);
    unset_bit(val, pin * 2);

    *gpio_moder = val;
}

void set_as_output(ptr_t gpio_moder, int pin) {
    uint32_t val = *gpio_moder;

    unset_bit(val, pin * 2 + 1);
    set_bit(val, pin * 2);

    *gpio_moder = val;
}
