; ******************************************************
; ATMEGA32 Assembly Code Template
; DESD AUG19 @ Sunbeam Infotech
; ******************************************************

.include "C:\VMLAB\include\m32def.inc"

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
	; setup SP to end of stack
	LDI R22, LOW(RAMEND)
	OUT SPL, R22
	LDI R22, HIGH(RAMEND)
	OUT SPH, R22
	
	LDI R16, 12
	LDI R17, 23
	
	; R20 = add_two(R16, R17)
	MOV R0, R16
	MOV R1, R17
	RCALL add_two
	MOV R20, R0
	
end:	RJMP end


; add_two is a func taking two ints (R0 & R1)
; addition result is returned (R0)
add_two:
	ADD R0, R1
	RET	


default_handler:
	RETI
	

