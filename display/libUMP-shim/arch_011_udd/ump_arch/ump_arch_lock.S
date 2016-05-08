.globl ump_arch_lock
ump_arch_lock:
    .1c58: 	mov	r2, r1
    .1c5c: 	mov	r1, r0
    .1c60: 	ldr	r0, [pc, #20]	// 1c7c <ump_arch_lock+0x24>
    .1c64: 	push	{r3, lr}
    .1c68: 	ldr	r0, [pc, r0]
    .1c6c: 	bl	_hwmem_uku_map
    .1c70: 	cmn	r0, #1
    .1c74: 	moveq	r0, #0
    .1c78: 	pop	{r3, pc}
    .1c7c: 	andeq	r3, r0, r4, ror #7
