#include "gyro.h"

#include "stm32l475xx.h"

#define I2C_LSM6DSL_ADDR 0b11010100

void gyro_init() {
    // reset i2c2
    SET_BIT(RCC->APB1, RCC_APB1_I2C2RST);

    // enable i2c2 clock
    SET_BIT(RCC->APB1ENR1, RCC_APB1ENR1_I2C2ENR);

    // use 7 bit addr
    // clear addr bits
    CLEAR_BIT(I2C2->CR2, I2C_CR2_ADD10);
    I2C2->CR2 =
        (I2C2->CR2 & ~I2C_CR2_SADD) | (I2C_LSM6DSL_ADDR << I2C_CR2_SADD_Pos);

    // enable i2c2
    SET_BIT(I2C2->CR1, I2C_CR1_PE);

    // enable i2c2
    CLEAR_BIT(RCC->APB1, RCC_APB1_I2C2RST);
}
