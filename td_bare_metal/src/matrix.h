#ifndef MATRIX_H
#define MATRIX_H

#include "stm32l4xx.h"

void matrix_init();

void SB(int x) {
    if (x)
        SET_BIT(GPIOC->BSRR, GPIO_BSRR_BS5);
    else
        SET_BIT(GPIOC->BSRR, GPIO_BSRR_BR5);
}

void LAT(int x) {
    if (x)
        SET_BIT(GPIOC->BSRR, GPIO_BSRR_BS4);
    else
        SET_BIT(GPIOC->BSRR, GPIO_BSRR_BR4);
}

void RST(int x) {
    if (x)
        SET_BIT(GPIOC->BSRR, GPIO_BSRR_BS3);
    else
        SET_BIT(GPIOC->BSRR, GPIO_BSRR_BR3);
}

void SCK(int x) {
    if (x)
        SET_BIT(GPIOB->BSRR, GPIO_BSRR_BS1);
    else
        SET_BIT(GPIOB->BSRR, GPIO_BSRR_BR1);
}

void SDA(int x) {
    if (x)
        SET_BIT(GPIOA->BSRR, GPIO_BSRR_BS4);
    else
        SET_BIT(GPIOA->BSRR, GPIO_BSRR_BR4);
}

void C0(int x) {
    if (x)
        SET_BIT(GPIOB->BSRR, GPIO_BSRR_BS2);
    else
        SET_BIT(GPIOB->BSRR, GPIO_BSRR_BR2);
}

void C1(int x) {
    if (x)
        SET_BIT(GPIOA->BSRR, GPIO_BSRR_BS15);
    else
        SET_BIT(GPIOA->BSRR, GPIO_BSRR_BR15);
}

void C2(int x) {
    if (x)
        SET_BIT(GPIOA->BSRR, GPIO_BSRR_BS2);
    else
        SET_BIT(GPIOA->BSRR, GPIO_BSRR_BR2);
}

void C3(int x) {
    if (x)
        SET_BIT(GPIOA->BSRR, GPIO_BSRR_BS7);
    else
        SET_BIT(GPIOA->BSRR, GPIO_BSRR_BR7);
}

void C4(int x) {
    if (x)
        SET_BIT(GPIOA->BSRR, GPIO_BSRR_BS6);
    else
        SET_BIT(GPIOA->BSRR, GPIO_BSRR_BR6);
}

void C5(int x) {
    if (x)
        SET_BIT(GPIOA->BSRR, GPIO_BSRR_BS5);
    else
        SET_BIT(GPIOA->BSRR, GPIO_BSRR_BR5);
}

void C6(int x) {
    if (x)
        SET_BIT(GPIOB->BSRR, GPIO_BSRR_BS0);
    else
        SET_BIT(GPIOB->BSRR, GPIO_BSRR_BR0);
}

void C7(int x) {
    if (x)
        SET_BIT(GPIOA->BSRR, GPIO_BSRR_BS3);
    else
        SET_BIT(GPIOA->BSRR, GPIO_BSRR_BR3);
}

#endif
