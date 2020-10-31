#ifndef IRQ_H
#define IRQ_H

#include <stdint.h>

void irq_init();

#define disable_irq() asm volatile("cpsid i")

#endif
