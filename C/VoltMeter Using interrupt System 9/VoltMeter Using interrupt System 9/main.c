/*
 * VoltMeter Using interrupt System 9.c
 *
 * Created: 3/8/2022 8:10:12 AM
 * Author : Madushan
 */ 

#include <avr/io.h>			// include input/output definition
#include <avr/interrupt.h>


int main(void)
{
    DDRB = DDRB | 0b00011111;		// config PB0-PB5 as outputs
	DDRC = DDRC & 0b11111110;		// config PC0 as input
	ADMUX = (ADMUX & 0b01111111) | 0b01000000;		// ref voltage to Avcc 5v
	ADMUX = ADMUX & 0b11111000;		// multiplexor to ADC0
		
	ADCSRA = ADCSRA | 0b00001000;		// adc interrupt enable
	ADCSRA = ADCSRA | 0b00000111;		// prescaler to 128
	ADCSRA = ADCSRA | 0b10000000;		// ADC enable
	sei();
	ADCSRA = ADCSRA | 0b01000000;		// start adc
	
    while (1) 
    {
		
    }
	return 0;
}

ISR(ADC_vect){
	float vIn = ADCW * 5.0 / 1024;
	PORTB = PORTB & 0b11100000;
	if(vIn > 4)
	PORTB = PORTB | 0b00011111;
		else if (vIn > 3)
	PORTB = PORTB | 0b00001111;
		else if (vIn > 2)
	PORTB = PORTB | 0b00000111;
		else if(vIn > 1)
	PORTB = PORTB | 0b00000011;
		else if(vIn > 0)
	PORTB = PORTB | 0b00000001;
	ADCSRA = ADCSRA | 0b01000000;		// restart adc
}

