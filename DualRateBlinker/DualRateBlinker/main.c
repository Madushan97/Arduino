#include <avr/io.h>						//define io definitions
#define F_CPU 16000000UL				//define CPU clock speed for delay.h
#include <util/delay.h>					

int main(void)
{
	DDRB = DDRB | (1<<4) ;			//CONFIGURE PB5 AS OUTPUT
	DDRB = DDRB & ~(1<<0);			//CONFIGURE PB0 AS INPUT
	PORTB = PORTB | (1<<0);			//pull up pb0
   
    while (1) 
    {
		PORTB = PORTB ^ (1<<4);		// toggle pb4
		
		if (PINB & (1<<0))			//checking 0bit of PINB is high or not
		{
			_delay_ms(500);			// if the button is not pressed wait 500 milliseconds
		} else {
			_delay_ms(200);			// if the button is pressed wait 200 milliseconds
		}
		
	}
	return 0;
}

