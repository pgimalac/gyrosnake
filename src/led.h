#ifndef __LED_H__
#define __LED_H__

#include "stdint.h"

void led_init();

void led_b_on();
void led_y_on();
void led_g_on();
void led_g_off();
uint32_t led_g_status();
void led_b_y_off();
void led_g_toggle();

#endif
