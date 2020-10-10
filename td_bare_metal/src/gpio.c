#include "gpio.h"

void set_as_input(ptr_t gpio_moder, int pin) {
    unset_bit(*gpio_moder, pin * 2 + 1);
    unset_bit(*gpio_moder, pin * 2);
}

void set_as_output(ptr_t gpio_moder, int pin) {
    unset_bit(*gpio_moder, pin * 2 + 1);
    set_bit(*gpio_moder, pin * 2);
}
