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
@ write a function to add two numbers.
@ write a function to add three numbers.

.global main
.type main, %function
main: 
	push {lr}

	mov r5, #10
	mov r6, #20
	mov r7, #30

	@ r4 = add_two(r5, r6);
	mov r0, r5
	mov r1, r6
	bl add_two
	mov r4, r0

	@ r4 = add_three(r5, r6, r7);
	mov r0, r5
	mov r1, r6
	mov r2, r7
	bl add_three
	mov r4, r0

	@r5=3
	@while(r5 <= 7)
	@{
	@	r4 = fact(r5);
	@	r5 = r5 + 2;
	@}

	mov r5, #3
numloop:
	cmp r5, #7
	bgt numloopend

	mov r0, r5
	bl fact
	mov r4, r0

	add r5, #2
	b numloop
numloopend:

	pop {lr}
	mov pc, lr


.global add_two
.type add_two, %function
add_two:

	add r0, r1

	mov pc, lr

.global add_three
.type add_three, %function
add_three:
	push {lr}

	@r0 = add_two(r0, r1);
	bl add_two

	@r0 = add_two(r0, r2);
	mov r1, r2
	bl add_two

	pop {lr}
	mov pc, lr


.global fact
.type fact, %function
fact:
	push {lr}
	push {r4-r5}
	
	mov r5, r0
	mov r0, #1
	mov r4, #1
loop:
	cmp r4, r5
	bgt loopend

	mul r0, r0, r4
	
	add r4, #1
	b loop
loopend:

	pop {r4-r5}
	pop {lr}
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

