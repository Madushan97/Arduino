/*
 * system 2 in bit-wises hift.c
 *
 * Created: 2/19/2022 12:03:38 PM
 * Author : Madushan
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>

int main(void)
{
    
	DDRB = DDRB | (1<<0);
    while (1) 
    {
		PORTB = PORTB | (1<<0);
		_delay_ms(200);
		PORTB = PORTB & ~(1<<0);
		_delay_ms(200);
    }
return 0;
}

