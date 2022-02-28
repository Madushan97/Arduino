;
; dualrateblibker in ASM.asm
;
; Created: 2/26/2022 10:48:34 AM
; Author : Madushan
;


; Replace with your application code

SBI DDRB, 0		//SET PB0 AS OUTPUT
CBI DDRD, 2		//CLEAR PD2 AND CONFIG AS INPUT
SBI DDRD, 2		//PULLUP PD2

START : SBIC PORTD,2
		SBI PORTB, 0
		CALL DELAY
		CALL DELAY
		CBI PORTB, 0
		CALL DELAY
		CALL DELAY
		JMP ENDIF

ENDIF : SBI PORTB, 0
		CALL DELAY
		CBI PORTB, 0
		CALL DELAY

		JMP START

DELAY : LDI R16, 10
LOOP1 : LDI R17, 255
LOOP2 : LDI R18, 255
LOOP3 : DEC R18
		BRNE LOOP3
		DEC R17
		BRNE LOOP2
		DEC R16
		RET
		