/*
 * CounterBasedTrigger- counts 5 presses using sys 11.c
 *
 * Created: 3/20/2022 9:37:24 AM
 * Author : Madushan
 */ 

#include <avr/io.h>


int main(void)
{
    DDRB = DDRB | 0b00100000;		// config PB5 as output
	DDRD = DDRD & 0b11101111;		// config PD4 as input	
	PORTD = PORTD | 0b00010000;		// pull-up PD4	
	TCCR0B = TCCR0B | 0b00000110;	// clock source as external
	TCNT0 = 251;
	
    while (1) 
    {
		if( TIFR0 & 0b00000001 ){
			PORTB = PORTB ^ 0b00100000;		// toggle PB5
			TCNT0 = 251;
			TIFR0 = TIFR0 | 0b00000001;		// clear the timer 0 overflow bit
		}
		
    }
	return 0;
}

