#ifndef MATRIX_H
#define MATRIX_H

#include "stm32l4xx.h"
#include "utils.h"

extern rgb_color matrix[8][8];

void matrix_init();

#define SB(x) SET_BIT(GPIOC->BSRR, (x) ? GPIO_BSRR_BS5 : GPIO_BSRR_BR5)
#define LAT(x) SET_BIT(GPIOC->BSRR, (x) ? GPIO_BSRR_BS4 : GPIO_BSRR_BR4)
#define RST(x) SET_BIT(GPIOC->BSRR, (x) ? GPIO_BSRR_BS3 : GPIO_BSRR_BR3)
#define SCK(x) SET_BIT(GPIOB->BSRR, (x) ? GPIO_BSRR_BS1 : GPIO_BSRR_BR1)
#define SDA(x) SET_BIT(GPIOA->BSRR, (x) ? GPIO_BSRR_BS4 : GPIO_BSRR_BR4)
#define ROW0(x) SET_BIT(GPIOB->BSRR, (x) ? GPIO_BSRR_BS2 : GPIO_BSRR_BR2)
#define ROW1(x) SET_BIT(GPIOA->BSRR, (x) ? GPIO_BSRR_BS15 : GPIO_BSRR_BR15)
#define ROW2(x) SET_BIT(GPIOA->BSRR, (x) ? GPIO_BSRR_BS2 : GPIO_BSRR_BR2)
#define ROW3(x) SET_BIT(GPIOA->BSRR, (x) ? GPIO_BSRR_BS7 : GPIO_BSRR_BR7)
#define ROW4(x) SET_BIT(GPIOA->BSRR, (x) ? GPIO_BSRR_BS6 : GPIO_BSRR_BR6)
#define ROW5(x) SET_BIT(GPIOA->BSRR, (x) ? GPIO_BSRR_BS5 : GPIO_BSRR_BR5)
#define ROW6(x) SET_BIT(GPIOB->BSRR, (x) ? GPIO_BSRR_BS0 : GPIO_BSRR_BR0)
#define ROW7(x) SET_BIT(GPIOA->BSRR, (x) ? GPIO_BSRR_BS3 : GPIO_BSRR_BR3)

void deactivate_rows();
void activate_row(int row);

void pulse_SCK();
void pulse_LAT();

void send_byte(uint8_t val, int bank);
void mat_set_row(int row, const rgb_color *val);

#endif
