/*
 * CounterBasedTrigger.c
 *
 * Created: 3/19/2022 7:03:37 PM
 * Author : Madushan
 */ 

#include <avr/io.h>

int main(void)
{
   
   DDRB = DDRB | 0b00100000;		// configure PB5 as Output
   DDRD = DDRD & 0b11101111;		// configure PD4 as Input   
   PORTD = PORTD | 0b00010000;		// pull-up PD4 (T0-8bit)   
   TCCR0B = TCCR0B | 0b00000110;	// select clock source as T0
   TCNT0 = 0;
   
    while (1) 
    {
		if(TCNT0 >= 5)
		{
			PORTB = PORTB ^ 0b00100000;		// toggle PB5
			TCNT0 = 0;
		}
	}
	return 0;
}

