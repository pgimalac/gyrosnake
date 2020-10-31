#include "uart.h"

void uart_init() {
    // disable UART1
    CLEAR_BIT(USART1->CR1, USART_CR1_UE);

    // enable the clock of gpio b
    SET_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOBEN);

    // set TX as USART
    GPIOB->MODER = (GPIOB->MODER & ~GPIO_MODER_MODE6_Msk) | GPIO_MODER_MODE6_1;
    SET_BIT(GPIOB->AFR[0],
            GPIO_AFRL_AFSEL6_0 | GPIO_AFRL_AFSEL6_1 | GPIO_AFRL_AFSEL6_2);

    // set RX as USART
    GPIOB->MODER = (GPIOB->MODER & ~GPIO_MODER_MODE7_Msk) | GPIO_MODER_MODE7_1;
    SET_BIT(GPIOB->AFR[0],
            GPIO_AFRL_AFSEL7_0 | GPIO_AFRL_AFSEL7_1 | GPIO_AFRL_AFSEL7_2);

    // enable clock
    SET_BIT(RCC->APB2ENR, RCC_APB2ENR_USART1EN);

    // specify clock
    CLEAR_BIT(RCC->CCIPR, RCC_CCIPR_USART1SEL);

    // reset serial port
    SET_BIT(RCC->APB2RSTR, RCC_APB2RSTR_USART1RST);
    CLEAR_BIT(RCC->APB2RSTR, RCC_APB2RSTR_USART1RST);

    // set serial port speed
    // clock freq = 80MHz, baud = 115200 => USARTDIV = 80000000 / 115200 = 694
    const uint32_t baud = 80000000 / 115200;
    USART1->BRR = (uint16_t)baud;

    // oversampling
    // CLEAR_BIT(USART1->CR1, USART_CR1_OVER8);
    // no parity bit
    // CLEAR_BIT(USART1->CR1, USART_CR1_PCE);
    // 8N1 mode
    // CLEAR_BIT(USART1->CR1, USART_CR1_M);
    // 1 stop bit
    // CLEAR_BIT(USART1->CR2, USART_CR2_STOP);

    // enable USART, sender and receiver
    // SET_BIT(USART1->CR1, USART_CR1_TE | USART_CR1_RE | USART_CR1_UE);
    USART1->CR2 = 0;
    USART1->CR1 = USART_CR1_TE | USART_CR1_RE | USART_CR1_UE;
}

void uart_putchar(uint8_t c) {
    // reference manual page 1340
    do {
    } while (!READ_BIT(USART1->ISR, USART_ISR_TXE));

    USART1->TDR = c;

    // do {
    // } while (!READ_BIT(USART1->ISR, USART_ISR_TC));
}

uint8_t uart_getchar() {
    // reference manual page 1343
    while (!READ_BIT(USART1->ISR, USART_ISR_RXNE)) {
    }

    if (READ_BIT(USART1->ISR, USART_ISR_ORE | USART_ISR_FE)) {
        while (1) {
        }
    }

    uint32_t c = USART1->RDR;
    return (uint8_t)c;
}

void uart_puts(const uint8_t *s) {
    while (*s != 0) {
        uart_putchar(*s);
        s++;
    }

    uart_putchar('\r');
    uart_putchar('\n');

    do {
    } while (!READ_BIT(USART1->ISR, USART_ISR_TC));
}

void uart_gets(uint8_t *s, size_t size) {
    size_t i = 0;
    while (i < size) {
        s[i] = uart_getchar();
        i++;
        if (s[i - 1] == '\n') {
            break;
        }
    }
    s[i] = 0;
}
