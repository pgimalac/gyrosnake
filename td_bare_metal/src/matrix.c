#include "matrix.h"
#include "gpio.h"
#include "stm32l4xx.h"
#include "utils.h"

static void init_bank0() {
    SB(0);
    for (int i = 0; i < 144; i++) {
        SDA(1);
        pulse_SCK();
    }
    pulse_LAT();
}

void matrix_init() {
    // enable gpio A
    enable_clock_gpio(RCC_AHB2ENR_GPIOAEN);
    // enable gpio B
    enable_clock_gpio(RCC_AHB2ENR_GPIOBEN);
    // enable gpio C
    enable_clock_gpio(RCC_AHB2ENR_GPIOCEN);

    // set PC5 as output and high speed
    GPIOC->MODER = (GPIOC->MODER & ~GPIO_MODER_MODE5) | GPIO_MODER_MODE5_0;
    GPIOC->OSPEEDR =
        (GPIOC->OSPEEDR & ~GPIO_OSPEEDR_OSPEED5) | GPIO_OSPEEDR_OSPEED5_1;
    // set PC4 as output and high speed
    GPIOC->MODER = (GPIOC->MODER & ~GPIO_MODER_MODE4) | GPIO_MODER_MODE4_0;
    GPIOC->OSPEEDR =
        (GPIOC->OSPEEDR & ~GPIO_OSPEEDR_OSPEED4) | GPIO_OSPEEDR_OSPEED4_1;
    // set PC3 as output and high speed
    GPIOC->MODER = (GPIOC->MODER & ~GPIO_MODER_MODE3) | GPIO_MODER_MODE3_0;
    GPIOC->OSPEEDR =
        (GPIOC->OSPEEDR & ~GPIO_OSPEEDR_OSPEED3) | GPIO_OSPEEDR_OSPEED3_1;
    // set PB1 as output and high speed
    GPIOB->MODER = (GPIOB->MODER & ~GPIO_MODER_MODE1) | GPIO_MODER_MODE1_0;
    GPIOB->OSPEEDR =
        (GPIOB->OSPEEDR & ~GPIO_OSPEEDR_OSPEED1) | GPIO_OSPEEDR_OSPEED1_1;
    // set PA4 as output and high speed
    GPIOA->MODER = (GPIOA->MODER & ~GPIO_MODER_MODE4) | GPIO_MODER_MODE4_0;
    GPIOA->OSPEEDR =
        (GPIOA->OSPEEDR & ~GPIO_OSPEEDR_OSPEED4) | GPIO_OSPEEDR_OSPEED4_1;
    // set PB2 as output and high speed
    GPIOB->MODER = (GPIOB->MODER & ~GPIO_MODER_MODE2) | GPIO_MODER_MODE2_0;
    GPIOB->OSPEEDR =
        (GPIOB->OSPEEDR & ~GPIO_OSPEEDR_OSPEED2) | GPIO_OSPEEDR_OSPEED2_1;
    // set PA15 as output and high speed
    GPIOA->MODER = (GPIOA->MODER & ~GPIO_MODER_MODE15) | GPIO_MODER_MODE15_0;
    GPIOA->OSPEEDR =
        (GPIOA->OSPEEDR & ~GPIO_OSPEEDR_OSPEED15) | GPIO_OSPEEDR_OSPEED15_1;
    // set PA2 as output and high speed
    GPIOA->MODER = (GPIOA->MODER & ~GPIO_MODER_MODE2) | GPIO_MODER_MODE2_0;
    GPIOA->OSPEEDR =
        (GPIOA->OSPEEDR & ~GPIO_OSPEEDR_OSPEED2) | GPIO_OSPEEDR_OSPEED2_1;
    // set PA7 as output and high speed
    GPIOA->MODER = (GPIOA->MODER & ~GPIO_MODER_MODE7) | GPIO_MODER_MODE7_0;
    GPIOA->OSPEEDR =
        (GPIOA->OSPEEDR & ~GPIO_OSPEEDR_OSPEED7) | GPIO_OSPEEDR_OSPEED7_1;
    // set PA6 as output and high speed
    GPIOA->MODER = (GPIOA->MODER & ~GPIO_MODER_MODE6) | GPIO_MODER_MODE6_0;
    GPIOA->OSPEEDR =
        (GPIOA->OSPEEDR & ~GPIO_OSPEEDR_OSPEED6) | GPIO_OSPEEDR_OSPEED6_1;
    // set PA5 as output and high speed
    GPIOA->MODER = (GPIOA->MODER & ~GPIO_MODER_MODE5) | GPIO_MODER_MODE5_0;
    GPIOA->OSPEEDR =
        (GPIOA->OSPEEDR & ~GPIO_OSPEEDR_OSPEED5) | GPIO_OSPEEDR_OSPEED5_1;
    // set PB0 as output and high speed
    GPIOB->MODER = (GPIOB->MODER & ~GPIO_MODER_MODE0) | GPIO_MODER_MODE0_0;
    GPIOB->OSPEEDR =
        (GPIOB->OSPEEDR & ~GPIO_OSPEEDR_OSPEED0) | GPIO_OSPEEDR_OSPEED0_1;
    // set PA3 as output and high speed
    GPIOA->MODER = (GPIOA->MODER & ~GPIO_MODER_MODE3) | GPIO_MODER_MODE3_0;
    GPIOA->OSPEEDR =
        (GPIOA->OSPEEDR & ~GPIO_OSPEEDR_OSPEED3) | GPIO_OSPEEDR_OSPEED3_1;

    SB(1);
    LAT(1);
    RST(0);
    SCK(0);
    SDA(0);

    deactivate_rows();

    sleep(100);

    RST(1);

    init_bank0();

    SB(1);
    for (int i = 0; i < 192; i++) {
        SDA(1);
        pulse_SCK();
    }
    pulse_LAT();
}

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

void pulse_SCK() {
    SCK(0);
    sleep(30);
    SCK(1);
    sleep(30);
    SCK(0);
    sleep(30);
}

void pulse_LAT() {
    SCK(1);
    sleep(30);
    SCK(0);
    sleep(30);
    SCK(1);
    sleep(30);
}

void deactivate_rows() {
    C0(0);
    C1(0);
    C2(0);
    C3(0);
    C4(0);
    C5(0);
    C6(0);
    C7(0);
}

void activate_row(int row) {
    switch (row) {
        0 : C0(1);
        break;
        1 : C1(1);
        break;
        2 : C2(1);
        break;
        3 : C3(1);
        break;
        4 : C4(1);
        break;
        5 : C5(1);
        break;
        6 : C6(1);
        break;
        7 : C7(1);
        break;
    }
}
