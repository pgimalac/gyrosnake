.syntax unified
.arch armv7-m
.thumb
.cpu cortex-m4

.global _start

mem_start: .word 0x10000000
mem_new_start: .word 0x10000300
pattern: .word 0xdeadbeef

_start:
  mov r0, #64
  ldr r1, pattern
  ldr r2, mem_start
write_pattern:
  subs r0,r0,#1
  str r1,[r2],#4
  bne write_pattern

  ldr r2, mem_start
  ldr r1, mem_new_start
  mov r0, #64
copy_mem:
  subs r0,r0,#1
  ldr r3, [r2], #4
  str r3, [r1], #4
  bne copy_mem

end:
  b end
