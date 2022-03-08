/*
 * System 8.c
 *
 * Created: 3/7/2022 10:20:06 AM
 * Author : Madushan
 */ 

#include <avr/io.h>

int main(void)
{
    DDRB = DDRB | 0b00111111;		// configure PB0 to PB5 as outputs
	DDRC = DDRC & 0b11111110;		// A0 as input
	ADMUX = (ADMUX & 0b01111111) | 0b01000000;	// config reference voltage to 5V
	ADMUX = ADMUX & 0b11111000;				// configure ADC0
	
	ADCSRA = ADCSRA | 0b00000111;			// set prescaler to 128
	ADCSRA = ADCSRA | 0b10000000;			// enable ADC
	
    while (1) 
    {
		ADCSRA = ADCSRA | 0b01000000;		// start ADC
		while(ADCSRA & 0b01000000);			// poll until ADC over
		float vIn = ADCW * 5.0/1024;
		PORTB = PORTB & 0b11100000;		// turn off all the LEDs		
		if(vIn > 4) {
			PORTB = PORTB | 0b00011111;		// turn on PB0-PB5
    } else if(vIn > 3) {
			PORTB = PORTB | 0b00001111;		// turn on PB0-PB4
	} else if(vIn > 2){
			PORTB = PORTB | 0b00000111;		// turn on PB0-PB3
	} else if(vIn >1){
			PORTB = PORTB | 0b00000011;
	} else if(vIn > 0){
			PORTB = PORTB | 0b00000001;		// only PB0
	}
	return 0;
}
	}

