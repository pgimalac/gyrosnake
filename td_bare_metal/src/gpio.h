#ifndef __GPIO_H__
#define __GPIO_H__

#include <stdint.h>

// The main pointer type we use
typedef volatile uint32_t * ptr_t;

/*
 * Write the gpio_moder register given such as pin is an input.
 */
void set_as_input(ptr_t gpio_moder, uint32_t bit_0, uint32_t bit_1);

/*
 * Write the gpio_moder register given such as pin is an output.
 */
void set_as_output(ptr_t gpio_moder, uint32_t bit_0, uint32_t bit_1);

#define enable_clock_gpio(gpio) RCC->AHB2ENR |= (gpio)

#endif
