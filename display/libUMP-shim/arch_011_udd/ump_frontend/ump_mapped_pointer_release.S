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
 *	00001458 <ump_mapped_pointer_release>:
 *	    1458:       e5901004        ldr     r1, [r0, #4]
 *	    145c:       e92d4010        push    {r4, lr}
 *	    1460:       e3510000        cmp     r1, #0
 *	    1464:       e1a04000        mov     r4, r0
 *	    1468:       0a000002        beq     1478 <ump_mapped_pointer_release+0x20>
 *	    146c:       e5900014        ldr     r0, [r0, #20]
 *	    1470:       e5942008        ldr     r2, [r4, #8]
 *	    1474:       eb000201        bl      1c80 <ump_arch_unlock>
 *	    1478:       e3a03000        mov     r3, #0
 *	    147c:       e5843004        str     r3, [r4, #4]
 *	    1480:       e8bd8010        pop     {r4, pc}
 */


.globl ump_mapped_pointer_release
.text
.align 2
ump_mapped_pointer_release:
        ldr     r1, [r0, #4]
        push    {r4, lr}
        cmp     r1, #0
        mov     r4, r0
        beq	.out
        ldr     r0, [r0, #20]
        ldr     r2, [r4, #8]
        bl ump_arch_unlock
.out:
        mov     r3, #0
        str     r3, [r4, #4]
        pop     {r4, pc}
