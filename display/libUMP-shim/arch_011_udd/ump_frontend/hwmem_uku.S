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
.globl _hwmem_uku_open
.text
.align 2
_hwmem_uku_open:
 .1d20: push {r4, lr}
 .1d24: subs r4, r0, #0
 .1d28: beq .1d4c
 .1d2c: ldr r0, [pc, #32]
 .1d30: mov r1, #2
 .1d34: add r0, pc, r0
 .1d38: bl open@plt
 .1d3c: cmn r0, #1
 .1d40: strne r0, [r4]
 .1d44: movne r0, #0
 .1d48: pop {r4, pc}
 .1d4c: mvn r0, #0
 .1d50: pop {r4, pc}
 .1d54: andeq r1, r0, r0, lsl #21
#endif

.globl _hwmem_uku_close
_hwmem_uku_close:
 .1d58: push {r4, lr}
 .1d5c: subs r4, r0, #0
 .1d60: beq .1d84
 .1d64: ldr r0, [r4]
 .1d68: cmn r0, #1
 .1d6c: popeq {r4, pc}
 .1d70: bl close@plt
 .1d74: mvn r3, #0
 .1d78: mov r0, #0
 .1d7c: str r3, [r4]
 .1d80: pop {r4, pc}
 .1d84: mvn r0, #0
 .1d88: pop {r4, pc}


.globl _hwmem_uku_allocate
_hwmem_uku_allocate:
 .1d8c: cmn r0, #1
 .1d90: mov r2, r1
 .1d94: bxeq lr
 .1d98: movw r1, #22273 /* ; 0x5701 */
 .1d9c: movt r1, #16400 /* ; 0x4010 */
 .1da0: b ioctl@plt

.globl _hwmem_uku_release
_hwmem_uku_release:
 .1da4: cmn r0, #1
 .1da8: mov r2, r1
 .1dac: bxeq lr
 .1db0: movw r1, #22275 /* ; 0x5703 */
 .1db4: b ioctl@plt

.globl _hwmem_uku_import
_hwmem_uku_import:
 .1db8: cmn r0, #1
 .1dbc: mov r2, r1
 .1dc0: bxeq lr
 .1dc4: movw r1, #22283 /* ; 0x570b */
 .1dc8: b ioctl@plt

.globl _hwmem_uku_export
_hwmem_uku_export:
 .1dcc: cmn r0, #1
 .1dd0: mov r2, r1
 .1dd4: bxeq lr
 .1dd8: movw r1, #22282 /*; 0x570a */
 .1ddc: b ioctl@plt

.globl _hwmem_uku_map
_hwmem_uku_map:
 .1de0: cmn r0, #1
 .1de4: mov ip, r0
 .1de8: push {r4, lr}
 .1dec: moveq r0, r0
 .1df0: sub sp, sp, #8
 .1df4: mov r4, r1
 .1df8: beq .1e18
 .1dfc: mov r1, r2
 .1e00: mov r0, #0
 .1e04: mov r2, #3
 .1e08: mov r3, #1
 .1e0c: str ip, [sp]
 .1e10: str r4, [sp, #4]
 .1e14: bl mmap@plt
 .1e18: add sp, sp, #8
 .1e1c: pop {r4, pc}

.globl _hwmem_uku_unmap
_hwmem_uku_unmap:
 .1e20: b munmap@plt

.globl _hwmem_uku_set_sync_domain
_hwmem_uku_set_sync_domain:
 .1e24: cmn r0, #1
 .1e28: mov r2, r1
 .1e2c: bxeq lr
 .1e30: movw r1, #22277 /* ; 0x5705 */
 .1e34: movt r1, #16412 /* ; 0x401c */
 .1e38: b ioctl@plt

.globl _hwmem_uku_set_cpu_domain
_hwmem_uku_set_cpu_domain:
 .1e3c: cmn r0, #1
 .1e40: mov r2, r1
 .1e44: bxeq lr
 .1e48: movw r1, #22276 /* ; 0x5704 */
 .1e4c: movt r1, #16412 /* ; 0x401c */
 .1e50: b ioctl@plt

.globl _hwmem_uku_pin
_hwmem_uku_pin:

 .1e54: cmn r0, #1
 .1e58: mov r2, r1
 .1e5c: bxeq lr
 .1e60: movw r1, #22278 /* ; 0x5706 */
 .1e64: movt r1, #49160 /* ; 0xc008 */
 .1e68: b ioctl@plt

.globl _hwmem_uku_unpin
_hwmem_uku_unpin:
 .1e6c: cmn r0, #1
 .1e70: mov r2, r1
 .1e74: bxeq lr
 .1e78: movw r1, #22279 /* ; 0x5707 */
 .1e7c: b ioctl@plt

.globl _hwmem_uku_set_access
_hwmem_uku_set_access:
 .1e80: cmn r0, #1
 .1e84: mov r2, r1
 .1e88: bxeq lr
 .1e8c: movw r1, #22280 /* ; 0x5708 */
 .1e90: movt r1, #16396 /* ; 0x400c */
 .1e94: b ioctl@plt

.globl _hwmem_uku_get_info
_hwmem_uku_get_info:
 .1e98: cmn r0, #1
 .1e9c: mov r2, r1
 .1ea0: bxeq lr
 .1ea4: movw r1, #22281 /* ; 0x5709 */
 .1ea8: movt r1, #49168 /* ; 0xc010 */
 .1eac: b ioctl@plt
