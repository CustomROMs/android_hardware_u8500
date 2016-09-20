	.cpu cortex-a9
	.fpu softvfp
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 2
	.eabi_attribute 30, 2
	.eabi_attribute 34, 1
	.eabi_attribute 18, 4
	.file	"main.c"
	.text
	.align	2
	.global	test
	.type	test, %function
test:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
	ldr	r2, .L0
	mov	r0, #6
	mov	r1, #0
.LPIC0:
	add	r2, pc, r2
	b	__android_log_print(PLT)
	.align	2
.L0:
	.word	.LC0-(.LPIC0+8)
	.size	test, .-test
	.align	2
	.global	test2
	.type	test2, %function
test2:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
	ldr	r2, .L1
	mov	r0, #6
	mov	r1, #0
.LPIC1:
	add	r2, pc, r2
	b	__android_log_print(PLT)
	.align	2
.L1:
	.word	.LC1-(.LPIC1+8)
	.size	test2, .-test2
	.section	.rodata.str1.4,"aMS",%progbits,1
	.align	2
.LC0:
	.ascii	"test: entered\000"
	.space	2
.LC1:
	.ascii	"test2: entered\000"
	.ident	"GCC: (GNU) 4.9 20150123 (prerelease)"
	.section	.note.GNU-stack,"",%progbits
