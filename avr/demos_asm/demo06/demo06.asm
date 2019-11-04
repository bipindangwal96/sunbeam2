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
	; R6 / R17 = R0 and R16 % R17 = R1		
	LDI R16, 23
	LDI R17, 5
	
	CLR R0			; R0 = 0
	MOV R1, R16		; R1 = R16

div:	
	SUB R1, R17		; R1 = R1 - R17
	INC R0         ; R0++
	CP R1, R17		; if R1 < R17
	BRLO div_end   ;		goto div_end
	RJMP div       ; else continue div
div_end:		
	
end:	RJMP end

default_handler:
	RETI
	

