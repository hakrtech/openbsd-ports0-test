/* -*- Mode: asm; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*-
 *
 * The contents of this file are subject to the Mozilla Public
 * License Version 1.1 (the "License"); you may not use this file
 * except in compliance with the License. You may obtain a copy of
 * the License at http://www.mozilla.org/MPL/
 * 
 * Software distributed under the License is distributed on an "AS
 * IS" basis, WITHOUT WARRANTY OF ANY KIND, either express or
 * implied. See the License for the specific language governing
 * rights and limitations under the License.
 * 
 * The Original Code is mozilla.org code.
 * 
 * The Initial Developer of the Original Code is Netscape
 * Communications Corporation. Portions created by Netscape are
 * Copyright (C) 2001 Netscape Communications Corporation. All
 * Rights Reserved.
 * 
 * Contributor(s): 
 *   Stuart Parmenter <pavlov@netscape.com>
 *   Chris Seawood <cls@seawood.org>
 */

/*
    Platform specific code to invoke XPCOM methods on native objects
    for sparcv9 Solaris.

    See the SPARC Compliance Definition (SCD) Chapter 3
    for more information about what is going on here, including
    the use of BIAS (0x7ff).
    The SCD is available from http://www.sparc.com/.
*/

        .global XPTC_InvokeByIndex
        .type   XPTC_InvokeByIndex, #function

/*
    XPTC_InvokeByIndex(nsISupports* that, PRUint32 methodIndex,
                   PRUint32 paramCount, nsXPTCVariant* params);
    
*/
XPTC_InvokeByIndex:
        save    %sp,-(128 + 64),%sp ! room for the register window and
                                    ! struct pointer, rounded up to 0 % 64
        sll     %i2,4,%l0           ! assume the worst case
                                    ! paramCount * 2 * 8 bytes
        cmp     %l0, 0              ! are there any args? If not,
        be      .invoke             ! no need to copy args to stack
         nop

        sub     %sp,%l0,%sp         ! create the additional stack space
        add     %sp,0x7ff+136,%o0   ! step past the register window, the
                                    ! struct result pointer and the 'this' slot
        mov     %i2,%o1             ! paramCount
        call    invoke_copy_to_stack
        mov     %i3,%o2             ! params

!
!   load arguments from stack into the outgoing registers
!   BIAS is 0x7ff (2047)
!

!   load the %o1..5 64bit (extended word) output registers registers 
        ldx     [%sp + 0x7ff + 136],%o1    ! %i1
        ldx     [%sp + 0x7ff + 144],%o2    ! %i2
        ldx     [%sp + 0x7ff + 152],%o3    ! %i3
        ldx     [%sp + 0x7ff + 160],%o4    ! %i4
        ldx     [%sp + 0x7ff + 168],%o5    ! %i5

!   load the even number double registers starting with %d2
        ldd     [%sp + 0x7ff + 136],%f2
        ldd     [%sp + 0x7ff + 144],%f4
        ldd     [%sp + 0x7ff + 152],%f6
        ldd     [%sp + 0x7ff + 160],%f8
        ldd     [%sp + 0x7ff + 168],%f10
        ldd     [%sp + 0x7ff + 176],%f12
        ldd     [%sp + 0x7ff + 184],%f14
        ldd     [%sp + 0x7ff + 192],%f16
        ldd     [%sp + 0x7ff + 200],%f18
        ldd     [%sp + 0x7ff + 208],%f20
        ldd     [%sp + 0x7ff + 216],%f22
        ldd     [%sp + 0x7ff + 224],%f24
        ldd     [%sp + 0x7ff + 232],%f26
        ldd     [%sp + 0x7ff + 240],%f28
        ldd     [%sp + 0x7ff + 248],%f30

!
!   calculate the target address from the vtable
!
.invoke:
        sll     %i1,3,%l0           ! index *= 8
!       add     %l0,16,%l0          ! there are 2 extra entries in the vTable (16bytes)
        ldx     [%i0],%l1           ! *that --> address of vtable
        ldx     [%l0 + %l1],%l0     ! that->vtable[index * 8 + 16] --> address

        jmpl    %l0,%o7             ! call the routine
        mov     %i0,%o0             ! move 'this' pointer to out register

        mov     %o0,%i0             ! propagate return value
        ret
        restore

        .size    XPTC_InvokeByIndex, .-XPTC_InvokeByIndex
