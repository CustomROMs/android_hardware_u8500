/*
 * Copyright (C) 2010-2011, 2013 ARM Limited. All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*
000013b4 <ump_mapped_pointer_get>:
    13b4:	e92d4010 	push	{r4, lr}
    13b8:	e2504000 	subs	r4, r0, #0
    13bc:	01a00004 	moveq	r0, r4
    13c0:	08bd8010 	popeq	{r4, pc}
    13c4:	e5943000 	ldr	r3, [r4]
    13c8:	e3730001 	cmn	r3, #1
    13cc:	0a00001a 	beq	143c <ump_mapped_pointer_get+0x88>
    13d0:	e5940004 	ldr	r0, [r4, #4]
    13d4:	e3500000 	cmp	r0, #0
    13d8:	18bd8010 	popne	{r4, pc}
    13dc:	e5940014 	ldr	r0, [r4, #20]
    13e0:	e5941008 	ldr	r1, [r4, #8]
    13e4:	eb00021b 	bl	1c58 <ump_arch_lock>
    13e8:	e3500000 	cmp	r0, #0
    13ec:	e5840004 	str	r0, [r4, #4]
    13f0:	18bd8010 	popne	{r4, pc}
    13f4:	e59fc048 	ldr	ip, [pc, #72]	; 1444 <ump_mapped_pointer_get+0x90>
    13f8:	e59f4048 	ldr	r4, [pc, #72]	; 1448 <ump_mapped_pointer_get+0x94>
    13fc:	e08f000c 	add	r0, pc, ip
    1400:	ebffff39 	bl	10ec <puts@plt>
    1404:	e59f2040 	ldr	r2, [pc, #64]	; 144c <ump_mapped_pointer_get+0x98>
    1408:	e08f0002 	add	r0, pc, r2
    140c:	ebffff39 	bl	10f8 <printf@plt>
    1410:	e59f1038 	ldr	r1, [pc, #56]	; 1450 <ump_mapped_pointer_get+0x9c>
    1414:	e3a02092 	mov	r2, #146	; 0x92
    1418:	e08f0004 	add	r0, pc, r4
    141c:	e08f1001 	add	r1, pc, r1
    1420:	ebffff34 	bl	10f8 <printf@plt>
    1424:	e59f0028 	ldr	r0, [pc, #40]	; 1454 <ump_mapped_pointer_get+0xa0>
    1428:	e08f0000 	add	r0, pc, r0
    142c:	ebffff31 	bl	10f8 <printf@plt>
    1430:	e3a0000a 	mov	r0, #10
    1434:	ebffff32 	bl	1104 <putchar@plt>
    1438:	ebffff34 	bl	1110 <abort@plt>
    143c:	e3a00000 	mov	r0, #0
    1440:	e8bd8010 	pop	{r4, pc}
    1444:	00001e2c 	andeq	r1, r0, ip, lsr #28
    1448:	00001e68 	andeq	r1, r0, r8, ror #28
    144c:	00001e68 	andeq	r1, r0, r8, ror #28
    1450:	00001f18 	andeq	r1, r0, r8, lsl pc
    1454:	00001ee4 	andeq	r1, r0, r4, ror #29

*/

.globl ump_mapped_pointer_get
.text
.align 2
ump_mapped_pointer_get:
    .13b4:	push	{r4, lr}
    .13b8:	subs	r4, r0, #0
    .13bc:	moveq	r0, r4
    .13c0:	popeq	{r4, pc}
    .13c4:	ldr	r3, [r4]
    .13c8:	cmn	r3, #1
    .13cc:	beq	.143c
    .13d0:	ldr	r0, [r4, #4]
    .13d4:	cmp	r0, #0
    .13d8:	popne	{r4, pc}
    .13dc:	ldr	r0, [r4, #20]
    .13e0:	ldr	r1, [r4, #8]
    .13e4:	bl	ump_arch_lock
    .13e8:	cmp	r0, #0
    .13ec:	str	r0, [r4, #4]
    .13f0:	popne	{r4, pc}
    .13f4:	ldr	ip, [pc, #72]	/* 1444 <ump_mapped_pointer_get+0x90> */
    .13f8:	ldr	r4, [pc, #72]	/* 1448 <ump_mapped_pointer_get+0x94> */
    .13fc:	add	r0, pc, ip
    .1400:	bl	puts@plt
    .1404:	ldr	r2, [pc, #64]	/* 144c <ump_mapped_pointer_get+0x98> */
    .1408:	add	r0, pc, r2
    .140c:	bl	printf@plt
    .1410:	ldr	r1, [pc, #56]	/* 1450 <ump_mapped_pointer_get+0x9c> */
    .1414:	mov	r2, #146	/* 0x92 */
    .1418:	add	r0, pc, r4
    .141c:	add	r1, pc, r1
    .1420:	bl	printf@plt
    .1424:	ldr	r0, [pc, #40]	/* 1454 <ump_mapped_pointer_get+0xa0> */
    .1428:	add	r0, pc, r0
    .142c:	bl	printf@plt
    .1430:	mov	r0, #10
    .1434:	bl	putchar@plt
    .1438:	bl	abort@plt
    .143c:	mov	r0, #0
    .1440:	pop	{r4, pc}
    .1444:	andeq	r1, r0, ip, lsr #28
    .1448:	andeq	r1, r0, r8, ror #28
    .144c:	andeq	r1, r0, r8, ror #28
    .1450:	andeq	r1, r0, r8, lsl pc
    .1454:	andeq	r1, r0, r4, ror #29
