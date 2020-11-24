#include "gyro.h"

#include "stm32l475xx.h"

#define I2C_LSM6DSL_ADDR 0b1101010

#define SCL(x) SET_BIT(GPIOB->BSRR, (x) ? GPIO_BSRR_BS10 : GPIO_BSRR_BR10)
#define SDA(x) SET_BIT(GPIOB->BSRR, (x) ? GPIO_BSRR_BS11 : GPIO_BSRR_BR11)

// reference manual page 1272
// description of the initialization of I2C
// reference manual page 1286
// description of the initialization of master
void gyro_init() {
    // disable i2c2, enable analog filter, disable digital filter
    CLEAR_BIT(I2C2->CR1, I2C_CR1_PE | I2C_CR1_ANFOFF | I2C_CR1_DNF);
    // clears the start bit
    SET_BIT(I2C2->ICR, I2C_ICR_ADDRCF);

    // reset i2c2
    SET_BIT(RCC->APB1, RCC_APB1RSTR1_I2C2RST);

    // enable clock of GPIO B
    SET_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOBEN);

    // set PB10 as alternate SCL (AF4)
    GPIOB->MODER = (GPIOB->MODER & ~GPIO_MODER_MODE10) | GPIO_MODER_MODE10_1;
    GPIOB->AFRH = (GPIOB->AFRH & ~GPIO_AFRH_AFSEL_10) | GPIO_AFRH_AFSEL_10_2;
    // set PB11 as alternate SDA (AF4)
    GPIOB->MODER = (GPIOB->MODER & ~GPIO_MODER_MODE11) | GPIO_MODER_MODE10_1;
    GPIOB->AFRH = (GPIOB->AFRH & ~GPIO_AFRH_AFSEL_11) | GPIO_AFRH_AFSEL_11_2;

    // if we don't use smbus then not necessary
    // // set PB12 as alternate SMBA

    // I'll use PRESC=100ns (quite random value)
    // and other timings = 5x PRESC (why not ?)

    // PRESC
    I2C2->TIMINGR =
        (I2C2->TIMINGR & ~I2C_TIMINGR_PRESC) | (8 << I2C_TIMINGR_PRESC_Pos);
    // SCLDEL
    I2C2->TIMINGR =
        (I2C2->TIMINGR & ~I2C_TIMINGR_SCLDEL) | (4 << I2C_TIMINGR_SCLDEL_Pos);
    // SDADEL
    I2C2->TIMINGR =
        (I2C2->TIMINGR & ~I2C_TIMINGR_SDADEL) | (4 << I2C_TIMINGR_SDADEL_Pos);
    // SCLH
    I2C2->TIMINGR =
        (I2C2->TIMINGR & ~I2C_TIMINGR_SCLH) | (4 << I2C_TIMINGR_SCLH_Pos);
    // SCLL
    I2C2->TIMINGR =
        (I2C2->TIMINGR & ~I2C_TIMINGR_SCLL) | (4 << I2C_TIMINGR_SCLL_Pos);
    // NOSTRETCH
    CLEAR_BIT(I2C2->CR1, I2C_CR1_NOSTRETCH);

    // enable i2c2 clock
    SET_BIT(RCC->APB1ENR1, RCC_APB1ENR1_I2C2ENR);

    // select PCLK as I2C2 clock
    CLEAR_BIT(RCC->CCIPR, RCC_CCIPR_USART1SEL);

    // use 7 bit addr
    // clear addr bits
    CLEAR_BIT(I2C2->CR2, I2C_CR2_ADD10);
    I2C2->CR2 =
        (I2C2->CR2 & ~I2C_CR2_SADD) | (I2C_LSM6DSL_ADDR << I2C_CR2_SADD_Pos);

    // enable i2c2
    SET_BIT(I2C2->CR1, I2C_CR1_PE);

    // enable i2c2
    CLEAR_BIT(RCC->APB1, RCC_APB1RSTR1_I2C2RST);
}
