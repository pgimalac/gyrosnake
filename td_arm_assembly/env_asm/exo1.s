.syntax unified
.arch armv7-m
.thumb
.cpu cortex-m4

.global _start

mem_start: .word 0x10000000
pattern: .word 0xdeadbeef

_start:

/* initialisation du compteur */
  mov r0, #64
  ldr r1,pattern
  ldr r2,mem_start
loop:
  subs r0,r0,#1
  str r1,[r2],#4
  bne loop

end:
  b end
