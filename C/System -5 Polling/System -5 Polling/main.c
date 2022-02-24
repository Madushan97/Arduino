/*
 * System -5 Polling.c
 *
 * Created: 2/22/2022 6:29:40 PM
 * Author : Madushan
 */ 

#include <avr/io.h>				// include input/output definitions
#define F_CPU 16000000UL		//define processor clock speed for delay.h
#include <util/delay.h>

int main(void)
{
	
	DDRB = DDRB | ((1<<DDB0) | (1<<DDB5));		// configure pb0, PB5 as output
	DDRD = DDRD & ~(1<<DDD2);					// CONFIGURE PD21 AS INPUT
	PORTD = PORTD | (1<<PORTD2);				// pull up pd2
    
    while (1) 
    {
		PORTB = PORTB ^ (1<<PORTB5);			// toggle the pb0
		_delay_ms(200);
		if ((PIND & (1<<PIND2)) == 0)
		{
			PORTB = PORTB ^ (1<<PORTB0);
			_delay_ms(200);
		}
			
    }
	return 0;
}


