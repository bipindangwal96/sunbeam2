; ******************************************************
; ATMEGA32 Assembly Code Template
; DESD AUG19 @ Sunbeam Infotech
; ******************************************************

.include "C:\VMLAB\include\m32def.inc"

.DSEG
arr: 	.BYTE 5

.CSEG

; Define here the variables
;
.def  temp  =r16

; Define here Reset and interrupt vectors, if any
;
.ORG 0000
	JMP main			 ;0
	JMP default_handler	 ;1
	JMP default_handler  ;2
	JMP default_handler  ;3
	JMP default_handler  ;4
	JMP default_handler  ;5
	JMP default_handler  ;6
	JMP default_handler  ;7
	JMP default_handler  ;8
	JMP default_handler  ;9
	JMP default_handler  ;10
	JMP default_handler  ;11
	JMP default_handler  ;12
	JMP default_handler  ;13
	JMP default_handler  ;14
	JMP default_handler  ;15
	JMP default_handler  ;16
	JMP default_handler  ;17
	JMP default_handler  ;18
	JMP default_handler  ;19
	JMP default_handler  ;20
	
main:
	; write data into the array.
	; read data from the array and sum it.
	
	LDI R16, 10 	; load val in array
	LDI R17, 10		; adding 10 into R16
	LDI R18, 0		; loop var 0 to 4

	; X = arr
	LDI XL, LOW(arr)
	LDI XH, HIGH(arr)
	
wr_loop:
	CPI R18, 5				; if R18 >= 5
	BRSH wr_loop_end     ;		goto wr_loop_end

	ST X+, R16           ; R16 = *(X++);
	ADD R16, R17         ; R16 = R16 + 10

	INC R18              ; R18++
	RJMP wr_loop         ; repeat wr_loop
wr_loop_end:		

	CLR R0					; R0 = 0
	LDI R18, 0				; loop var 0 to 4
rd_loop:
	CPI R18, 5				; if R18 >= 5
	BRSH rd_loop_end     ;		goto wr_loop_end

	LD R1, -X				; R1 = *(--X)
	ADD R0, R1				; R0 = R0 + R1

	INC R18              ; R18++
	RJMP rd_loop         ; repeat wr_loop
rd_loop_end:		
	
end:	RJMP end

default_handler:
	RETI
	

