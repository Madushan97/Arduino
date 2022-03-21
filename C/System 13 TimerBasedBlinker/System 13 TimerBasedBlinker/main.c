/*
 * System 13 TimerBasedBlinker.c
 *
 * Created: 3/21/2022 7:35:00 AM
 * Author : Madushan
 */ 

#include <avr/io.h>

int main(void)
{
   DDRB = DDRB | 0b00100000;		// configure PB5 as output
   
   TCCR1B =TCCR1B | 0b00000011;		// select clock source as T1 and prescale to 64
   TCNT1 = 15536;					// set timer to 15536
      
    while (1) 
    {
		if ( TIFR1 & 0b00000001 )
		{
			PORTB = PORTB ^ 0b00100000;
			TCNT1 = 15536;
			TIFR1 = TIFR1 | 0b00000001;
		}
    }
	return 0;
}

