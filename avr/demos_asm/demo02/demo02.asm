; ******************************************************
; ATMEGA32 Assembly Code Template
; DESD AUG19 @ Sunbeam Infotech
; ******************************************************

.include "C:\VMLAB\include\m32def.inc"

.DSEG
num1:		.BYTE	1
num2:		.BYTE	1
result:	.BYTE	1

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
	; num1 = 10
	LDI R16, 10
	STS num1, R16
	
	; num2 = 15
	LDI R17, 15
	STS num2, R17
	
	; r1 = num1
	LDS r1, num1
	; r2 = num2
	LDS r2, num2
	; r1 = r1 + r2
	ADD r1, r2
	
	; result = r1
	STS result, r1		
	
end:	RJMP end

default_handler:
	RETI
	

