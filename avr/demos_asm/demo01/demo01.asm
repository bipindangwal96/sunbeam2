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
	LDI R16, 10			; R16 = 10
	LDI R17, 15       ; R17 = 15
	ADD R16, R17      ; R16 = R16 + R17
	MOV R2, R16       ; R2 = R16
		
	LDI R18, 10			; R18 = 10
	LDI R19, 15       ; R19 = 15
	SUB R18, R19		; R18 = R18 - R19
	MOV R3, R18       ; R3 = R18
	
	LDI R20, 10			; R20 = 10
	LDI R21, 15       ; R21 = 15
	MUL R20, R21		; R0,R1 = R20 * R21	
	
end:	RJMP end

default_handler:
	RETI
	

