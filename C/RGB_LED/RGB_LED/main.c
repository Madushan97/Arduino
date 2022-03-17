/*
 * RGB_LED.c
 *
 * Created: 3/17/2022 3:07:10 PM
 * Author : Madushan
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>

int main(void)
{
    DDRB = DDRB | 0b0000111;
	
    while (1) 
    {
		PORTB = PORTB | 0b00000001;
		_delay_ms(200);
		PORTB = PORTB & 0b11111110;
		_delay_ms(200);
		PORTB = PORTB | 0b00000010;
		_delay_ms(200);
		PORTB = PORTB & 0b11111101;
		_delay_ms(200);
		PORTB = PORTB | 0b00000100;
		_delay_ms(200);
		PORTB = PORTB & 0b11111011;
		_delay_ms(200);
    };
}

