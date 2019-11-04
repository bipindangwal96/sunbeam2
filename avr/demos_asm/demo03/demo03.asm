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
	; read SREG (mem addr 0x5F) into R2 using LDS
	LDS R2, 0x005F
	; read SREG into R1 using IN
	IN R1, SREG
	
	; RAM last address is 2143 (M32) (32 + 64 + 2048)

	; set SP using STS
	LDI R16, HIGH(2143)
	STS 0x005E, R16
	LDI R17, LOW(2143)
	STS 0x005D, R17
	
	; RAMEND is AVR assembler macro that represent
	; last address of RAM based on selected controller

	; set SP using OUT
	LDI R18, HIGH(RAMEND)
	OUT SPH, R18
	LDI R19, LOW(RAMEND)
	OUT SPL, R19

	LDI R20, 10
	PUSH R20
	LDI R20, 11
	PUSH R20
		
end:	RJMP end

default_handler:
	RETI
	

