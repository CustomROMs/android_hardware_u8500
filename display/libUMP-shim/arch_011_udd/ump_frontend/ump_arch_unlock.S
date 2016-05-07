.globl ump_arch_unlock
ump_arch_unlock:
    .1c80: 	mov	r0, r1
    .1c84: 	mov	r1, r2
    .1c88: 	b	_hwmem_uku_unmap
