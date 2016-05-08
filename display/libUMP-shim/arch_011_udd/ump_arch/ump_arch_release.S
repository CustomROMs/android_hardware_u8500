.globl ump_arch_release
ump_arch_release:
    .1bdc:      mov     r1, r0
    .1be0:      ldr     r0, [pc, #8]   // ; 1c40 <ump_arch_release+0x64>
    .1be4:      push    {r3, lr}
    .1be8:      ldr     r0, [pc, r0]
    .1bec:      bl      _hwmem_uku_release
/*
    .1bf0:      cmp     r0, #0
    .1bf4:      popeq   {r3, pc}
    .1bf8:      ldr     lr, [pc, #68]   // ; 1c44 <ump_arch_release+0x68>
    .1bfc:      add     r0, pc, lr
    .1c00:      bl      puts@plt
    .1c04:      ldr     r2, [pc, #60]   // ; 1c48 <ump_arch_release+0x6c>
    .1c08:      add     r0, pc, r2
    .1c0c:      bl      printf@plt
    .1c10:      ldr     ip, [pc, #52]   // ; 1c4c <ump_arch_release+0x70>
    .1c14:      ldr     r3, [pc, #52]   // ; 1c50 <ump_arch_release+0x74>
    .1c18:      mov     r2, #167        // ; 0xa7
    .1c1c:      add     r0, pc, ip
    .1c20:      add     r1, pc, r3
    .1c24:      bl      printf@plt
    .1c28:      ldr     r1, [pc, #36]   // ; 1c54 <ump_arch_release+0x78>
    .1c2c:      add     r0, pc, r1
    .1c30:      bl      printf@plt
    .1c34:      mov     r0, #10
    .1c38:      bl      putchar@plt
    .1c3c:      bl      abort@plt
*/
    .1bf0:      .word 0x00003464
/*
    .1c44:      .word 0x00001964
    .1c48:      .word 0x000019a0
    .1c4c:      .word 0x0000199c
    .1c50:      .word 0x000018d4
    .1c54:      .word 0x00001b38
*/
