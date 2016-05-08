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


#if 0
.globl ump_arch_import
ump_arch_import:
 .1b74: push {r4, r5, r6, lr}
 .1b78: mov r6, r1
 .1b7c: ldr r4, [pc, #64] /* ; .1bc4 <ump_arch_import+0x50> */
 .1b80: sub sp, sp, #16
 .1b84: mov r1, r0
 .1b88: add r4, pc, r4
 .1b8c: ldr r0, [r4]
 .1b90: bl _hwmem_uku_import
 .1b94: mov r1, sp
 .1b98: mov r2, #0
 .1b9c: str r2, [sp, #4]
 .1ba0: mov r5, r0
 .1ba4: ldr r0, [r4]
 .1ba8: str r5, [sp]
 .1bac: bl _hwmem_uku_get_info
 .1bb0: ldr r3, [sp, #4]
 .1bb4: mov r0, r5
 .1bb8: str r3, [r6]
 .1bbc: add sp, sp, #16
 .1bc0: pop {r4, r5, r6, pc}
 .1bc4: andeq r3, r0, r4, asr #9
#endif

.globl ump_arch_export
ump_arch_export:
 .1bc8: mov r1, r0
 .1bcc: ldr r0, [pc, #4] /* ; .1bd8 <ump_arch_export+0x10> */
 .1bd0: ldr r0, [pc, r0]
 .1bd4: b _hwmem_uku_export
 .1bd8: andeq r3, r0, ip, ror r4
