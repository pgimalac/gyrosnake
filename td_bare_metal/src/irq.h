#ifndef IRQ_H
#define IRQ_H

#include <stdint.h>

#define disable_irq() asm volatile("cpsid i")

#endif
