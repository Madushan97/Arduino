/*
 * System 8.c
 *
 * Created: 3/9/2022 5:33:50 PM
 * Author : Madushan
 */ 

#include <avr/io.h>


int main(void)
{
   DDRB = DDRB | 0b00011111;		//config PB0-PB5
   DDRC = DDRC & 0b11111110;		// config A0 as input
   
   ADMUX = ( ADMUX & 0b01111111 ) | 0b01000000;		// set Vref to 5V
   ADMUX = ADMUX & 0b11111000;		// multiplex PC0 as analog input channel ADC0
   
   ADCSRA = ADCSRA | 0b00000111;		// select prescaler to 128
   ADCSRA = ADCSRA | 0b10000000;		// enable ADC
   
    while (1) 
    {
		ADCSRA = ADCSRA | 0b01000000;		// ADC start
		while (ADCSRA & 0b01000000);	//poll till adc over
		float vIn = ADCW * 5.0 / 1024;
		PORTB = PORTB | 0b11100000;		// turn off all LEDs
		if (vIn > 4)
			PORTB = PORTB | 0b00011111;
		else if (vIn > 3)
			PORTB = PORTB | 0b00001111;
		else if (vIn > 2)
			PORTB = PORTB | 0b00000111;
		else if (vIn > 1)
			PORTB = PORTB | 0b00000011;
		else if (vIn > 0)
			PORTB = PORTB | 0b00000001;
    }
	return 0;
}

