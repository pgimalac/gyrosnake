#ifndef MATRIX_H
#define MATRIX_H

#include "stm32l4xx.h"
#include "utils.h"

extern rgb_color matrix[8][8];

void matrix_init();

void deactivate_rows();
void activate_row(int row);

void mat_set_row(int row, const rgb_color *val);

#endif
