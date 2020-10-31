#include "matrix.h"
#include "stm32l4xx.h"

static void init_bank(int x) {
    for (int i = 0; i < 24; i++) {
        send_byte((uint8_t)-1, x);
    }
    pulse_LAT();
}

void matrix_init() {
    // enable gpio A, B and C
    SET_BIT(RCC->AHB2ENR,
            RCC_AHB2ENR_GPIOAEN | RCC_AHB2ENR_GPIOBEN | RCC_AHB2ENR_GPIOCEN);

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

    sleep(100000000);

    RST(1);

    init_bank(0);
    init_bank(1);
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
    LAT(1);
    sleep(30);
    LAT(0);
    sleep(10);
    LAT(1);
}

void deactivate_rows() {
    ROW0(0);
    ROW1(0);
    ROW2(0);
    ROW3(0);
    ROW4(0);
    ROW5(0);
    ROW6(0);
    ROW7(0);
}

void activate_row(int row) {
    switch (row) {
    case 0:
        ROW0(1);
        break;
    case 1:
        ROW1(1);
        break;
    case 2:
        ROW2(1);
        break;
    case 3:
        ROW3(1);
        break;
    case 4:
        ROW4(1);
        break;
    case 5:
        ROW5(1);
        break;
    case 6:
        ROW6(1);
        break;
    case 7:
        ROW7(1);
        break;
    }
}

void mat_set_row(int row, const rgb_color *val) {
    for (int i = 7; i >= 0; i--) {
        send_byte(val[i].b, 1);
        send_byte(val[i].g, 1);
        send_byte(val[i].r, 1);
    }
    pulse_LAT();

    deactivate_rows();
    activate_row(row);
}

void send_byte(uint8_t val, int bank) {
    SB(bank);
    for (int i = bank ? 7 : 5; i >= 0; i--) {
        SDA(val & (1 << i));
        pulse_SCK();
    }
}
