#ifndef __GPIO_H__
#define __GPIO_H__

#include <stdint.h>

// The main pointer type we use
typedef volatile uint32_t *ptr_t;

/*
 * Write the gpio_moder register given such as pin is an input.
 */
void set_as_input(ptr_t gpio_moder, uint32_t bit_0, uint32_t bit_1);

/*
 * Write the gpio_moder register given such as pin is an output.
 */
void set_as_output(ptr_t gpio_moder, uint32_t bit_0, uint32_t bit_1);

#define enable_clock_gpio(gpio) RCC->AHB2ENR |= (gpio)

#define GPIO_AF0 0x0
#define GPIO_AF1 0x1
#define GPIO_AF2 0x2
#define GPIO_AF3 0x3
#define GPIO_AF4 0x4
#define GPIO_AF5 0x5
#define GPIO_AF6 0x6
#define GPIO_AF7 0x7
#define GPIO_AF8 0x8
#define GPIO_AF9 0x9
#define GPIO_AF10 0xA
#define GPIO_AF11 0xB
#define GPIO_AF12 0xC
#define GPIO_AF13 0xD
#define GPIO_AF14 0xE
#define GPIO_AF15 0xF

#endif
