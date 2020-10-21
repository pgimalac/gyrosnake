#include "utils.h"

void sleep(uint32_t ns) {
    // 4 asm instructions per loop turn:

    //  a:   bf00        nop
    //  c:   4291        cmp     r1, r2
    //  e:   f102 0201   add.w   r2, r2, #1
    // 12:   d1fa        bne.n   a <sleep+0xa>

    // F=8000000Hz and 1/80000000 = 12.5 ns
    // so each loop turn takes 60ns
    for (uint32_t i = 0; i < ns / 60 + 1; i++)
        asm volatile("nop");
}
