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
00001278 <ump_handle_create_from_secure_id>:
    1278:	e3700001 	cmn	r0, #1
    127c:	e92d40f0 	push	{r4, r5, r6, r7, lr}
    1280:	e1a06000 	mov	r6, r0
    1284:	e24dd00c 	sub	sp, sp, #12
    1288:	03a04000 	moveq	r4, #0
    128c:	0a00001e 	beq	130c <ump_handle_create_from_secure_id+0x94>
    1290:	e28d1004 	add	r1, sp, #4
    1294:	eb000236 	bl	1b74 <ump_arch_import>
    1298:	e59d1004 	ldr	r1, [sp, #4]
    129c:	e3510000 	cmp	r1, #0
    12a0:	01a04001 	moveq	r4, r1
    12a4:	e1a05000 	mov	r5, r0
    12a8:	0a000017 	beq	130c <ump_handle_create_from_secure_id+0x94>
    12ac:	eb000269 	bl	1c58 <ump_arch_lock>
    12b0:	e2507000 	subs	r7, r0, #0
    12b4:	01a04007 	moveq	r4, r7
    12b8:	0a000013 	beq	130c <ump_handle_create_from_secure_id+0x94>
    12bc:	e3a00001 	mov	r0, #1
    12c0:	e3a0101c 	mov	r1, #28
    12c4:	eb0002f9 	bl	1eb0 <_ump_osu_calloc>
    12c8:	e2504000 	subs	r4, r0, #0
    12cc:	0a000011 	beq	1318 <ump_handle_create_from_secure_id+0xa0>
    12d0:	e59d3004 	ldr	r3, [sp, #4]
    12d4:	e3a01000 	mov	r1, #0
    12d8:	e5846000 	str	r6, [r4]
    12dc:	e284000c 	add	r0, r4, #12
    12e0:	e5847004 	str	r7, [r4, #4]
    12e4:	e1a02001 	mov	r2, r1
    12e8:	e5843008 	str	r3, [r4, #8]
    12ec:	e1a03001 	mov	r3, r1
    12f0:	e5845014 	str	r5, [r4, #20]
    12f4:	eb000360 	bl	207c <_ump_osu_lock_auto_init>
    12f8:	e594300c 	ldr	r3, [r4, #12]
    12fc:	e3530000 	cmp	r3, #0
    1300:	13a03001 	movne	r3, #1
    1304:	15843010 	strne	r3, [r4, #16]
    1308:	0a000009 	beq	1334 <ump_handle_create_from_secure_id+0xbc>
    130c:	e1a00004 	mov	r0, r4
    1310:	e28dd00c 	add	sp, sp, #12
    1314:	e8bd80f0 	pop	{r4, r5, r6, r7, pc}
    1318:	e1a00005 	mov	r0, r5
    131c:	e1a01007 	mov	r1, r7
    1320:	e59d2004 	ldr	r2, [sp, #4]
    1324:	eb000255 	bl	1c80 <ump_arch_unlock>
    1328:	e1a00005 	mov	r0, r5
    132c:	eb00022a 	bl	1bdc <ump_arch_release>
    1330:	eafffff5 	b	130c <ump_handle_create_from_secure_id+0x94>
    1334:	e1a04003 	mov	r4, r3
    1338:	eafffff3 	b	130c <ump_handle_create_from_secure_id+0x94>
 */


.globl ump_handle_create_from_secure_id
.text
.align 2
ump_handle_create_from_secure_id:
 .1278: cmn r0, #1
 .127c: push {r4, r5, r6, r7, lr}
 .1280: mov r6, r0
 .1284: sub sp, sp, #12
 .1288: moveq r4, #0
 .128c: beq .130c
 .1290: add r1, sp, #4
 .1294: bl ump_arch_import
 .1298: ldr r1, [sp, #4]
 .129c: cmp r1, #0
 .12a0: moveq r4, r1
 .12a4: mov r5, r0
 .12a8: beq .130c
 .12ac: bl ump_arch_lock
 .12b0: subs r7, r0, #0
 .12b4: moveq r4, r7
 .12b8: beq .130c
 .12bc: mov r0, #1
 .12c0: mov r1, #28
 .12c4: bl _ump_osu_calloc
 .12c8: subs r4, r0, #0
 .12cc: beq .1318
 .12d0: ldr r3, [sp, #4]
 .12d4: mov r1, #0
 .12d8: str r6, [r4]
 .12dc: add r0, r4, #12
 .12e0: str r7, [r4, #4]
 .12e4: mov r2, r1
 .12e8: str r3, [r4, #8]
 .12ec: mov r3, r1
 .12f0: str r5, [r4, #20]
 .12f4: bl _ump_osu_lock_auto_init
 .12f8: ldr r3, [r4, #12]
 .12fc: cmp r3, #0
 .1300: movne r3, #1
 .1304: strne r3, [r4, #16]
 .1308: beq .1334
 .130c: mov r0, r4
 .1310: add sp, sp, #12
 .1314: pop {r4, r5, r6, r7, pc}
 .1318: mov r0, r5
 .131c: mov r1, r7
 .1320: ldr r2, [sp, #4]
 .1324: bl ump_arch_unlock
 .1328: mov r0, r5
 .132c: bl ump_arch_release
 .1330: b .130c
 .1334: mov r4, r3
 .1338: b .130c
