; ******************************************************
; ATMEGA32 Assembly Code Template
; DESD AUG19 @ Sunbeam Infotech
; ******************************************************

.include "C:\VMLAB\include\m32def.inc"

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

str:	.DB "SUNBEAM"

num:	.DW 100
	
main:
	LDI ZL, LOW(str*2)
	LDI ZH, HIGH(str*2)

loop:	
	LPM R0, Z+
	
	MOV R16, R0
	CPI R16, 0
	BRNE loop
			
	
end:	RJMP end

default_handler:
	RETI
	
