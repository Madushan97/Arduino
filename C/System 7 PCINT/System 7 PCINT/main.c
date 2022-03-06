/*
 * System 7 PCINT.c
 *
 * Created: 3/6/2022 7:18:38 PM
 * Author : Madushan
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/interrupt.h>

int main(void)
{
    DDRB = DDRB | ((1<<DDB5)|(1<<DDB0));
	DDRD = DDRD & ~(1<<DDD2);
	PORTD = PORTD | (1<<PORTD2);
	PCICR = PCICR | (1<<PCIE2);		// enable PORTD interrupts
	PCMSK2 = PCMSK2 | (1<<PCINT18);	// enable pin change interrupt on PD2
	sei();
	
    while (1) 
    {
		PORTB = PORTB ^ (1<<PORTB);
		_delay_ms(200);
    }
	return 0;
}

ISR(PCINT2_vect){
	if(( PIND & (1<<PIND2)) == 0 ){
		PORTB = PORTB ^ (1<<PORTB0);	
	}
}

