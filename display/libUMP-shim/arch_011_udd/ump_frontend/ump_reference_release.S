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
    .14c4:	e92d4038 	push	{r3, r4, r5, lr}
    .14c8:	e2504000 	subs	r4, r0, #0
    .14cc:	08bd8038 	popeq	{r3, r4, r5, pc}
    .14d0:	e5943000 	ldr	r3, [r4]
    .14d4:	e3730001 	cmn	r3, #1
    .14d8:	08bd8038 	popeq	{r3, r4, r5, pc}
    .14dc:	e594000c 	ldr	r0, [r4, #12]
    .14e0:	e3a01000 	mov	r1, #0
    .14e4:	eb000430 	bl	25ac <_ump_osu_lock_wait>
    .14e8:	e5945010 	ldr	r5, [r4, #16]
    .14ec:	e2455001 	sub	r5, r5, #1
    .14f0:	e5845010 	str	r5, [r4, #16]
    .14f4:	e3550000 	cmp	r5, #0
    .14f8:	0a000003 	beq	.150c <ump_reference_release+0x48>
    .14fc:	e594000c 	ldr	r0, [r4, #12]
    .1500:	e3a01000 	mov	r1, #0
    .1504:	e8bd4038 	pop	{r3, r4, r5, lr}
    .1508:	ea00058c 	b	2b40 <_ump_osu_lock_signal>
    .150c:	e59400.14 	ldr	r0, [r4, #20]
    .1510:	eb0001b1 	bl	1bdc <ump_arch_release>
    .15.14:	e594000c 	ldr	r0, [r4, #12]
    .1518:	e1a01005 	mov	r1, r5
    .151c:	eb000587 	bl	2b40 <_ump_osu_lock_signal>
    .1520:	e594000c 	ldr	r0, [r4, #12]
    .1524:	eb000655 	bl	2e80 <_ump_osu_lock_term>
    .1528:	e1a00004 	mov	r0, r4
    .152c:	e8bd4038 	pop	{r3, r4, r5, lr}
    .1530:	ea000261 	b	1ebc <_ump_osu_free>
 */


.globl ump_reference_release
.text
.align 2
ump_reference_release:
    .14c4:	 	push	{r3, r4, r5, lr}
    .14c8:	 	subs	r4, r0, #0
    .14cc:	 	popeq	{r3, r4, r5, pc}
    .14d0:	 	ldr	r3, [r4]
    .14d4:	 	cmn	r3, #1
    .14d8:	 	popeq	{r3, r4, r5, pc}
    .14dc:	 	ldr	r0, [r4, #12]
    .14e0:	 	mov	r1, #0
    .14e4:	 	bl	_ump_osu_lock_wait
    .14e8:	 	ldr	r5, [r4, #16]
    .14ec:		sub	r5, r5, #1
    .14f0:	 	str	r5, [r4, #16]
    .14f4:	 	cmp	r5, #0
    .14f8:	 	beq	.150c
    .14fc:	 	ldr	r0, [r4, #12]
    .1500:	 	mov	r1, #0
    .1504:	 	pop	{r3, r4, r5, lr}
    .1508:	 	b	_ump_osu_lock_signal
    .150c:	 	ldr	r0, [r4, #20]
    .1510:	 	bl	ump_arch_release
    .1514:	 	ldr	r0, [r4, #12]
    .1518:	 	mov	r1, r5
    .151c:	 	bl	_ump_osu_lock_signal
    .1520:	 	ldr	r0, [r4, #12]
    .1524:	 	bl	_ump_osu_lock_term
    .1528:	 	mov	r0, r4
    .152c:	 	pop	{r3, r4, r5, lr}
    .1530:	 	b	_ump_osu_free
