#ifndef MATRIX_H
#define MATRIX_H

#include "stm32l4xx.h"
#include "utils.h"

void matrix_init();

void SB(int x);
void LAT(int x);
void RST(int x);
void SCK(int x);
void SDA(int x);

void C0(int x);
void C1(int x);
void C2(int x);
void C3(int x);
void C4(int x);
void C5(int x);
void C6(int x);
void C7(int x);

void deactivate_rows();
void activate_row(int row);

void pulse_SCK();
void pulse_LAT();

void send_byte(uint8_t val, int bank);
void mat_set_row(int row, const rgb_color *val);

#endif
