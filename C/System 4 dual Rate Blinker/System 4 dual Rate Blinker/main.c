/*
 * System 4 dual Rate Blinker.c
 *
 * Created: 2/20/2022 9:03:00 AM
 * Author : Madushan
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>

int main(void)
{
    DDRB = DDRB | (1<<0);	// set pb0 as output
	DDRB = DDRB & ~(1<<1);	// clear pb1 and configure as input
	PORTB = PORTB | (1<<1);	//pull up pb1
    while (1) 
    {
		PORTB = PORTB ^ (1<<0);
		
		if(PINB & (1<<1)){
			_delay_ms(500);
		}
		else
			_delay_ms(200);
    }
	return 0;
}

