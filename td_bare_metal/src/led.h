#ifndef __LED_H__
#define __LED_H__

#include <stdint.h>

// RCC register
#define RCC (*(volatile uint32_t *)0x40021000)

// AHB2 clock enable register, offset=4C -> (RCC + 4C)
#define RCC_AHB2ENR (*(volatile uint32_t *)0x4002104C)

// port B clock
#define RCC_AHB2ENR_B 1

void led_init();

void led_g_on();
void led_g_off();

#endif
