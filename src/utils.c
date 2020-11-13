#include "utils.h"

void sleep(uint32_t ns) {
    // 4 asm instructions per loop turn:

    //  a:   bf00        nop
    //  c:   4291        cmp     r1, r2
    //  e:   f102 0201   add.w   r2, r2, #1
    // 12:   d1fa        bne.n   a <sleep+0xa>

    // F=8000000Hz and 1/80000000 = 12.5 ns
    // so each loop turn takes 50ns (or 62 ?)

    // but after a hand made measure, 200 is better (because of gdb ?)
    // better wait too much than not enough so we use 50
    for (uint32_t i = 0; i < ns / 50 + 1; i++)
        asm volatile("nop");
}
