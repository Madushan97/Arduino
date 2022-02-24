#include <avr/io.h>			// include IO definitions
#define F_CPU 16000000UL	// define clock speed for delay.h
#include <util/delay.h>		// include definition of _delay_ms()

int main(void)
{
	
	DDRB = DDRB | 0b00000001;	//set ddrb 5th bit and config as output
	  
    while (1) 
    {
		PORTB = PORTB | 0b000000001;	//set portb 5th bit and state high(+5v)
		_delay_ms(200);
		PORTB = PORTB & 0b111111110;	//clear portb 5th bit and state low
		_delay_ms(200);
    }
	return 0;
}

