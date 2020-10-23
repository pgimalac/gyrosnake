#include "irq.h"
#include "handlers.h"

#define VTOR (*(volatile uint32_t *)0xE000ED08)
#define NVIC_ISER (*(volatile uint32_t *)0xE000E100)
#define NVIC_ICER (*(volatile uint32_t *)0xE000E180)
#define NVIC_ISPR (*(volatile uint32_t *)0xE000E200)
#define NVIC_ICPR (*(volatile uint32_t *)0xE000E280)

extern uint32_t *_stack;
extern void _start();

void *vector_table[] __attribute__((section(".vectors"))) = {
    // Stack and Reset Handler
    &_stack, /* Top of stack */
    _start,  /* Reset handler */

    // ARM internal exceptions
    NMI_Handler,              /* NMI handler */
    HardFault_Handler,        /* Hard Fault handler */
    MemoryManagement_Handler, /* Memory Management Handler */
    BusFault_Handler,         /* Bus Fault handler */
    UsageFault_Handler,       /* Usage Fault Handler */
    0,                        /* Reserved */
    0,                        /* Reserved */
    0,                        /* Reserved */
    0,                        /* Reserved */
    SVC_Handler,              /* SVC handler */
    DebugMonitor_Handler,     /* Debug Monitor handler */
    0,                        /* Reserved */
    PendSV_Handler,           /* Pending SVC handler */
    SysTick_Handler,          /* SysTick handler */

    // External interrupts
    GPIOA_IRQHandler, (void *)GPIOB_IRQHandler, (void *)GPIOC_IRQHandler,
    (void *)GPIOD_IRQHandler, (void *)GPIOE_IRQHandler,
    (void *)UART0_IRQHandler, (void *)UART1_IRQHandler, (void *)SSI0_IRQHandler,
    (void *)I2C0_IRQHandler, (void *)PWMFault_IRQHandler,
    (void *)PWMGen0_IRQHandler, (void *)PWMGen1_IRQHandler,
    (void *)PWMGen2_IRQHandler, (void *)QEI0_IRQHandler,
    (void *)ADC0Seq0_IRQHandler, (void *)ADC0Seq1_IRQHandler,
    (void *)ADC0Seq2_IRQHandler, (void *)ADC0Seq3_IRQHandler,
    (void *)WDTimer0_IRQHandler, (void *)Timer0A_IRQHandler,
    (void *)Timer0B_IRQHandler, (void *)Timer1A_IRQHandler,
    (void *)Timer1B_IRQHandler, (void *)Timer2A_IRQHandler,
    (void *)Timer2B_IRQHandler, (void *)AnalogCmp0_IRQHandler,
    (void *)AnalogCmp1_IRQHandler, (void *)0, (void *)SC_IRQHandler,
    (void *)FMC_IRQHandler, (void *)GPIOF_IRQHandler, (void *)GPIOG_IRQHandler,
    (void *)0, (void *)UART2_IRQHandler, (void *)0, (void *)Timer3A_IRQHandler,
    (void *)Timer3B_IRQHandler, (void *)I2C1_IRQHandler,
    (void *)QEI1_IRQHandler, (void *)0, (void *)0, (void *)0,
    (void *)Ethernet_IRQHandler, (void *)Hibernation_IRQHandler};
