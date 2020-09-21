.syntax unified
.arch armv7-m
.thumb
.cpu cortex-m4

.global _start

mem_start: .word 0x10000000
mem_new_start: .word 0x10000300
pattern: .word 0xdeadbeef

_start:

  ldr r0, mem_start
  ldr r1, pattern
  mov r2, #64
  bl memset

  ldr r0, mem_start
  ldr r1, mem_new_start
  mov r2, #64
  bl memcpy

end:
  b end

/*
 * r0 contains the origin address
 * r1 contains the destination address
 * r2 contains the memory size (in words)
 */
memcpy:
  @ ldr r0, mem_start
  @ ldr r1, mem_new_start
  @ mov r2, #64
memcpy_loop:
  subs r2,r2,#1
  ldr r3, [r0], #4
  str r3, [r1], #4
  bne memcpy_loop
  bx lr

memset:
  @ ldr r0, mem_start
  @ ldr r1, pattern
  @ mov r2, #64
memset_loop:
  subs r2,r2,#1
  str r1,[r0],#4
  bne memset_loop
  bx lr
