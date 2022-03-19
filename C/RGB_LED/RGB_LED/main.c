/*
 * RGB_LED.c
 *
 * Created: 3/17/2022 3:07:10 PM
 * Author : Madushan
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

int main(void)
{
	DDRB = DDRB | 0b0000111;
	DDRC = DDRC & 0b11111110;
	ADMUX = ADMUX & 0b11111000;		// ADC0
	ADMUX = (ADMUX & 0b01111111) | 0b01000000;		// ref voltage for 5V
	
	ADCSRA = ADCSRA | 0b00000111;		// prescale for F_CPU/128
	ADCSRA = ADCSRA | 0b10000000;		// enable ADC
	ADCSRA = ADCSRA | 0b00001000;		// enable ADC interrupt
	sei();
	ADCSRA = ADCSRA | 0b01000000;		// start ADC
	
    while (1) 
    {
		
    };
	return 0;
}

ISR(ADC_vect){
	
	float vIn = ADCW * 5.0 / 1024;
	PORTB = PORTB & 0b11111000;
	if(vIn > 2 )
		PORTB = PORTB | 0b00000001;
	else if(vIn > 1 )
		PORTB = PORTB | 0b00000010;
	else if(vIn > 0 )
		PORTB = PORTB | 0b00000100;
		
	ADCSRA = ADCSRA | 0b01000000;		// restart ADC
}


