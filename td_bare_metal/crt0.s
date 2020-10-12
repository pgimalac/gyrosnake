.thumb
.syntax unified
.cpu cortex-m4
.global _start

.thumb_func
_start:
    @ load initial sp
    ldr r0, =_stack
    mov sp, r0

    @ zero bss out
    bl init_bss

    @ call main
    bl main

_exit:
    @ endless loop
    b _exit
