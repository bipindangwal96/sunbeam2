               ; ******************************************************
; ATMEGA32 Assembly Code Template
; DESD AUG19 @ Sunbeam Infotech
; ******************************************************

.include "C:\VMLAB\include\m32def.inc"

; Define here the variables
;
.def  led_data  =R23

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
	
	; PA --> LEDs
	
	; make Port as output
	LDI R24, 0xFF
	OUT DDRA, R24
	
	; load LED value
	LDI led_data, 0x55

loop:
	; write LED value on port
	OUT PORTA, led_data
	
	RCALL delay_sec	; 3 cycles

	; toggle led_data
	COM led_data
	
	RJMP loop

end:	RJMP end


delay_sec:
	; nested loop to calculate delay of 1 sec.
	; clock freq = 4 MHz
	LDI R18, 20		; 1 cycle
loop3:

	LDI R17, 200	; 1 cycle
loop2:
	
	LDI R16, 249	; 1 cycle
loop1:
	NOP				; 1 cycle	
	DEC R16			; 1 cycle
	BRNE loop1		; 2 cycles

	NOP				; 1 cycle	
	DEC R17			; 1 cycle
	BRNE loop2		; 2 cycles

	NOP				; 1 cycle	
	DEC R18			; 1 cycle
	BRNE loop3		; 2 cycles

	RET				; 4 cycles	

default_handler:
	RETI
	


