#include "gyro.h"

#include "stm32l475xx.h"

#define I2C_LSM6DSL_ADDR 0b1101010

void gyro_init() {
    // disable i2c2, enable analog filter, disable digital filter
    CLEAR_BIT(I2C2->CR1, I2C_CR1_PE | I2C_CR1_ANFOFF | I2C_CR1_DNF);

    // reset i2c2
    SET_BIT(RCC->APB1, RCC_APB1RSTR1_I2C2RST);

    // enable clock of GPIO B
    SET_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOBEN);

    // set PB10 as alternate SCL
    // set PB11 as alternate SDA

    // if we don't use smbus then not necessary
    // // set PB12 as alternate SMBA

    // PRESC, SDADEL, SCLDEL, SCLH, SCLL in I2C_TIMINGR ????
    // NOSTRETCH in I2C_CR1

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
