#include <avr/io.h>			// include IO definitions
#define F_CPU 16000000UL	// define CPU clock speed for delay.h
#include <util/delay.h>		//include definition of _delay_ms()

int main(void)
{
   
    DDRB = DDRB|1<<DDB5;		//SET BIT 0 OF DDRB & CONFIGURE AS OUTPUT
	while(1) {
		
		PORTB = PORTB | 1<<DDB5;	//set bit 0 of DDRB
		_delay_ms(200);
		PORTB = PORTB & ~(1<<PORTB5);
		_delay_ms(200);
	}
	return 0;
}

