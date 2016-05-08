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

.globl ump_handle_create_from_secure_id
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
