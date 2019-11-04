; ******************************************************
; ATMEGA32 Assembly Code Template
; DESD AUG19 @ Sunbeam Infotech
; ******************************************************

.include "C:\VMLAB\include\m32def.inc"

.DSEG
; Define here the variables
;
num:	.BYTE	1


.CSEG

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
	; num = 12 (using STS)
	LDI R16, 12
	STS num, R16
		
	; increment a global variable using LD & ST.		
	; X = &num
	LDI XL, LOW(num)
	LDI XH, HIGH(num)
	
	; R0 = *X;
	LD R0, X
	; R0++;
	INC R0
	; *X = R0;
	ST X, R0
	
end:	RJMP end

default_handler:
	RETI
	

