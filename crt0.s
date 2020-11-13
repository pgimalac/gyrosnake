.thumb
.syntax unified
.cpu cortex-m4
.global _start

.thumb_func
_start:
    @ load initial sp
    ldr r0, =_stack
    mov sp, r0

    @ copy vtor in ram
    ldr r0, =_vtor_lma
    ldr r1, =_vtor_lma_end
    ldr r2, =_vtor_vma
    bl memcopy

    @ copy text in ram
    ldr r0, =_text_lma
    ldr r1, =_text_lma_end
    ldr r2, =_text_vma
    bl memcopy

    @ zero bss out
    bl init_bss

    @ copy data in ram
    ldr r0, =_data_lma
    ldr r1, =_data_lma_end
    ldr r2, =_data_vma
    bl memcopy

    @ call main
    bl main

_exit:
    @ endless loop
    b _exit
