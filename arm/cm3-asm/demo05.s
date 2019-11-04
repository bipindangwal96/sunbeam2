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
@ int num1 = 10;
num1:	.word 10

@ int num2 = 20;
num2:	.word 20

@ int res = 0;
res:	.word 0

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
@ addition of two global variables (LDR / STR)

.global main
.type main, %function
main:          

	@ load value of num1 in r1
	ldr r7, =num1			@ r7 = &num1;
	ldr r1, [r7]			@ r1 = *r7

	@ load value of num2 in r2
	ldr r7, =num2			@ r7 = &num2;
	ldr r2, [r7]			@ r2 = *r7

	@ add r1 & r2 and get result in r0
	add r0, r1, r2

	@ store r0 in res
	ldr r7, =res			@ r7 = &res;
	str r0, [r7]			@ *r7 = r0; 
		
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

