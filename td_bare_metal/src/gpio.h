#ifndef __GPIO_H__
#define __GPIO_H__

#include <stdint.h>

typedef volatile uint32_t * ptr_t;

void set_as_input(ptr_t gpio_moder, int pin);
void set_as_output(ptr_t gpio_moder, int pin);

#define ADDR_ADD_OFFSET(addr, offet) (*(ptr_t)((addr) + (offet)))
#define set_bit(addr, bit) (addr) |= 1 << (bit)
#define unset_bit(addr, bit) (addr) &= ~(1 << (bit))

// RCC register
#define RCC    (*(ptr_t)0x40021000)

// AHB2 clock enable register
#define RCC_AHB2ENR ADDR_ADD_OFFSET(RCC, 0x4C)

// port B clock
#define RCC_AHB2ENR_B 1

// GPIO registers
#define GPIO_A_ADDR 0x48000000
#define GPIO_B_ADDR 0x48000400
#define GPIO_C_ADDR 0x48000800
#define GPIO_D_ADDR 0x48000C00
#define GPIO_E_ADDR 0x48001000
#define GPIO_F_ADDR 0x48001400
#define GPIO_G_ADDR 0x48001800
#define GPIO_H_ADDR 0x48001C00

// GPIO MODER
#define OFFSET_GPIO_MODER 0x00
#define GPIO_A_MODER ADDR_ADD_OFFSET(GPIO_A_ADDR, OFFSET_GPIO_MODER)
#define GPIO_B_MODER ADDR_ADD_OFFSET(GPIO_B_ADDR, OFFSET_GPIO_MODER)
#define GPIO_C_MODER ADDR_ADD_OFFSET(GPIO_C_ADDR, OFFSET_GPIO_MODER)
#define GPIO_D_MODER ADDR_ADD_OFFSET(GPIO_D_ADDR, OFFSET_GPIO_MODER)
#define GPIO_E_MODER ADDR_ADD_OFFSET(GPIO_E_ADDR, OFFSET_GPIO_MODER)
#define GPIO_F_MODER ADDR_ADD_OFFSET(GPIO_F_ADDR, OFFSET_GPIO_MODER)
#define GPIO_G_MODER ADDR_ADD_OFFSET(GPIO_G_ADDR, OFFSET_GPIO_MODER)
#define GPIO_H_MODER ADDR_ADD_OFFSET(GPIO_H_ADDR, OFFSET_GPIO_MODER)

// GPIO BSRR
#define OFFSET_GPIO_BSRR 0x18
#define GPIO_A_BSRR ADDR_ADD_OFFSET(GPIO_A_ADDR, OFFSET_GPIO_BSRR)
#define GPIO_B_BSRR ADDR_ADD_OFFSET(GPIO_B_ADDR, OFFSET_GPIO_BSRR)
#define GPIO_C_BSRR ADDR_ADD_OFFSET(GPIO_C_ADDR, OFFSET_GPIO_BSRR)
#define GPIO_D_BSRR ADDR_ADD_OFFSET(GPIO_D_ADDR, OFFSET_GPIO_BSRR)
#define GPIO_E_BSRR ADDR_ADD_OFFSET(GPIO_E_ADDR, OFFSET_GPIO_BSRR)
#define GPIO_F_BSRR ADDR_ADD_OFFSET(GPIO_F_ADDR, OFFSET_GPIO_BSRR)
#define GPIO_G_BSRR ADDR_ADD_OFFSET(GPIO_G_ADDR, OFFSET_GPIO_BSRR)
#define GPIO_H_BSRR ADDR_ADD_OFFSET(GPIO_H_ADDR, OFFSET_GPIO_BSRR)

// pins
#define P00 0
#define P01 1
#define P02 2
#define P03 3
#define P04 4
#define P05 5
#define P06 6
#define P07 7
#define P08 8
#define P09 9
#define P10 10
#define P11 11
#define P12 12
#define P13 13
#define P14 14
#define P15 15

#endif
