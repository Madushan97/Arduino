/*
 * System 12 counterBasedTriggerUsingInterrupts.c
 *
 * Created: 3/20/2022 6:20:45 PM
 * Author : Madushan
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

int main(void)
{
    
	DDRB = DDRB | 0b00100000;		// config PB5 as output
	DDRD = DDRD & 0b11101111;		// config Pd4 as Input
	PORTD = PORTD | 0b00010000;		// pull - up PD4
	
	TCCR0B = TCCR0B | 0b00000110;	// clock source as T0
	TCNT0 = 251;
	TIMSK0 = TIMSK0 | 0b00000001;	// enable timer overflow interrupt T0
	sei();
	
    while (1) 
    {
    }
	return 0;
}

ISR(TIMER0_OVF_vect){
	PORTB = PORTB ^ 0b00100000;		// toggle PB5
	TCNT0 = 251;
}
