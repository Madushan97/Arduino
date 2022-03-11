/*
 * Light Meter_LDR.c
 *
 * Created: 3/11/2022 12:38:55 AM
 * Author : Madushan
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

int main(void)
{
   DDRB = DDRB | 0b00001111;		// config PB0-PB5 as outputs
   DDRC = DDRC & 0b11111110;		// config A0/PC0 as input
   
   ADMUX = (ADMUX & 0b01111111) | 0b01000000;		// config Vref to 5V
   ADMUX = ADMUX & 0b11111000;		// multiplex PC0 as analog input channel ADC0
   
   ADCSRA = ADCSRA | 0b00000111;	// select prescaler F_CPU/128
   ADCSRA = ADCSRA | 0b10000000;	// enable ADC   
   ADCSRA = ADCSRA | 0b00001000;	// enable ADC interrupt
   sei();
   ADCSRA = ADCSRA | 0b01000000;	// start ADC   
   
    while (1) 
    {
    }
	return 0;
}

ISR(ADC_vect){
	float vIn = ADCW * 5.0 / 1024;
	PORTB = PORTB & 0b11110000;		// turn off LEDs
	
	if(vIn > 3.00)
		PORTB = PORTB | 0b00001111;
	else if(vIn > 2.00)
		PORTB = PORTB | 0b00000111;
	else if(vIn > 1.00)
		PORTB = PORTB | 0b00000011;
	else if(vIn > 0)
		PORTB = PORTB | 0b00000001;
	ADCSRA = ADCSRA | 0b01000000;	// restart ADC   
}

