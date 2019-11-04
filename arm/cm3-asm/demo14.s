/* *************************************************************************
**  Target      : Cortex-M3
**  Environment : GNU Tools
**  Micro-Controller : LM3SXXXX *************************************************************************
*/
.syntax unified

.global pfnVectors
.global Default_Handler
.global _start
.equ Top_Of_Stack, 0x20004000    /* end of 16K RAM */

.global sdata
.global edata
.global etext
.global sbss
.global ebss

.section .vectors
vectors:
	.word Top_Of_Stack          @ msp = 0x20004000
	.word _start                @ Starting Program address
	.word Default_Handler	    @ NMI_Handler
	.word Default_Handler	    @ HardFault_Handler
	.word Default_Handler	    @ MemManage_Handler
	.word Default_Handler	    @ BusFault_Handler
	.word Default_Handler	    @ UsageFault_Handler
	.word 0                     @ 7
	.word 0                     @ To
	.word 0                     @ 10 
	.word 0                     @ Reserved
	.word Default_Handler	    @ SVC_Handler
	.word Default_Handler	    @ DebugMon_Handler
	.word 0                     @ Reserved
	.word Default_Handler	    @ PendSV_Handler
	.word Default_Handler	    @ SysTick_Handler
	.word Default_Handler	    @ IRQ_Handler
	.word Default_Handler	    @ IRQ_Handler

.section .rodata


.section .data


.section .bss


.section .text
.thumb
/**
 * This is the code that gets called when the processor first
 * starts execution following a reset. 
*/
.type _start, %function
_start:                              @ _start label is required by the linker

	//init .data section
	ldr r7, =etext
	ldr r6, =sdata
	ldr r5, =edata
	mov r4, #0
data_init:
	cmp r6, r5
	beq data_init_end
	ldrb r4, [r7], #1
	strb r4, [r6], #1
	b data_init
data_init_end:

	//clear .bss section
	ldr r6, =sbss
	ldr r7, =ebss
	mov r4, #0
bss_init:
	cmp r6, r7
	beq bss_init_end
	strb r4, [r6], #1
	b bss_init
bss_init_end:

	bl main
	stop:   b stop

/***************************************************************/
.global main
.type main, %function
main:     

	@ saturated maths
	mov r0, #10
	usat r1, #5, r0, lsl #1		@ r1 = MIN(r0 * 2, 31) --> 20 (q=0)
	usat r1, #5, r0, lsl #2		@ r1 = MIN(r0 * 4, 31) --> 31 (q=1)

	@ simd instructions (not supported in cm3)
	@ldr r1, =0x11223344
	@ldr r2, =0x44332211
	@qadd8 r0, r1, r2


	@ rev instruction
	ldr r0, =0x11223344
	rev r1, r0					@ r1 -- 0x44332211

	@ sign extend
	ldr r0, =0x55AA8765
	sxtb r1, r0			@ last byte of r0 -- 0110 0101
						@ new value of r1 will be -- 0x00000065
	sxth r2, r0			@ last 2 bytes of r0 -- 1000 0111 0110 0101
						@ new value of r2 will be -- 0xffff8765
	uxth r3, r0			@ new value of r3 will be -- 0x00008765

	@ to get result of ADC
	@ ldr r7, =ADGDR
	@ ldr r6, [r7]
	ldr r6, =0x11223344 	@ assume value of ADGDR is 0x11223344
	ubfx r0, r6, #4, #12	@ new val of r6 will be = 0x0334

	@ make bits [15:8] of r1 as 0x12
	ldr r1, =0x11223344
	bfc r1, #8, #16			@ r1 will be 0x11000044
	mov r0, 0x12
	bfi r1, r0, #8, #16		@ r1 will be 0x11001244
                         
	mov pc, lr
/***************************************************************/

/**
 * This is the code that gets called when the processor receives an
 * unexpected interrupt.  This simply enters an infinite loop,preserving
 * the system state for examination by a debugger.
 *
*/
.type Default_Handler, %function
Default_Handler:
	halt:
		b halt
.end

