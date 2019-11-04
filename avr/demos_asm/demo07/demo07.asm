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
	; collatz conjure
	LDI R16, 5
	MOV R0, R16			; 1st term R0 = R16
	LDI R21, 1

loop:	
	CP R0, R21			; if R0==1
	BREQ loop_end		; 		goto loop_end
	LDI R22, 1
	AND R22, R0			; R0 is even or odd
	BREQ even			; if even (Z=1), go to even
odd:	
	MOV R1, R0			; R1 = R0
	LSL R1				; R1 = R1 << 1
	ADD R0, R1			; R0 = R0 + R1
	INC R0				; R0++
	RJMP loop			; repeat loop	
even:
	LSR R0				; R0 = R0 >> 1	
	RJMP loop			; repeat loop
loop_end:			
	
end:	RJMP end

default_handler:
	RETI
	

