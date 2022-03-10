/*
 * LDR_Sensor.c
 *
 * Created: 3/10/2022 9:36:26 PM
 * Author : Madushan
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

int main(void)
{
    DDRB = DDRB | 0b00000001;		// config PB0 as output
	DDRC = DDRC & 0b11111110;		// config PC0 as input
	
	ADMUX = (ADMUX & 0b01111111) | 0b01000000;		// reference voltage to 5V
	ADMUX = ADMUX & 0b11111000;		// multiplex PC0 as analog input channel ADC0
	
	ADCSRA = ADCSRA | 0b00000111;		// select prescale as F_CPU/128
	ADCSRA = ADCSRA | 0b10000000;		// ADC enable
	ADCSRA = ADCSRA | 0b00001000;		// enable ADC interrupt
	
	sei();
	ADCSRA = ADCSRA | 0b01000000;		// start ADC	
	
    while (1) 
    {
    }
	return 0;
}

ISR(ADC_vect){
	float vIn = ADCW * 5.0 / 1024;
	
	
	if(vIn > 1){
		PORTB = PORTB & 0b11111110;		// turn off the led
	} else{
		PORTB = PORTB | 0b00000001;		// turn on the led
	}
	ADCSRA = ADCSRA | 0b01000000;		// restart ADC
}

