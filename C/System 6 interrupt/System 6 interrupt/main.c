/*
 * System 6 interrupt.c
 *
 * Created: 2/28/2022 12:09:40 PM
 * Author : Madushan
 */ 

#include <avr/io.h>			// include IO definitions
#define F_CPU 16000000UL	// define cpu clock speed for delay.h()
#include <util/delay.h>		// include definition of delay.h()
#include <avr/interrupt.h>	// include definitions of interrupt

int main(void)
{
	DDRB = DDRB | 0b00100001;		// declare PB5 and PB0 as output
	DDRD = DDRD & 0b11111011;		// declare PD2 as input
	PORTD = PORTD | 0b00000100;		// pull up PD2
	EICRA = (EICRA & 0b11111110) | 0b00000010;		// enable external interrupt on INT0 pin and falling edge
	EIMSK = EIMSK | 0b00000001;		// enable external interrupt mast register
	sei();		// enable global interrupt
   
    while (1) 
    {
		PORTB = PORTB ^ 0b00100000;		// toggle PB5
		_delay_ms(2000);		// wait 2s
    }	
	return 0;
}

ISR(INT0_vect){
	PORTB = PORTB ^ 0b00000001;		// toggle PB0
}
