/*
 * System2 in label constatnt.c
 *
 * Created: 2/19/2022 12:09:22 PM
 * Author : Madushan
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>


int main(void)
{

int delay(void){
	asm(	"DELAY : LDI R16,41\n"
			"LOOP1 : LDI R17,255\n"
			"LOOP2 : LDI R18,255\n"
			"LOOP3 : DEC R18\n"
			"BRNE LOOP3\n"
			"DEC R17\n"
			"BRNE LOOP2\n"
			"DEC R16\n"
			"BRNE LOOP1\n"
			"JMP DELAY\n"
		);
return 0;
}

    DDRB = DDRB | (1<<DDB0);
    while (1) 
    {
		PORTB = PORTB | (1<<DDB0);
		delay();
		PORTB = PORTB & ~(1<<DDB0);
		delay();
    }

}
