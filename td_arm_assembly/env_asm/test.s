.global _start

_start:
  mov r0, #33
  ldr r0, =33
  ldr r0, =0xC01dCafe

/* initialisation du compteur */
  mov r0, #10
loop:
  subs r0,r0,#1
  bne loop

end:
  b end
