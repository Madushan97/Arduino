/*
 * Assignment 1.c
 *
 * Created: 2/26/2022 11:49:26 PM
 * Author : Madushan
 */ 

#include <avr/io.h>		// include IO definitions
#define F_CPU 16000000UL	// define cpu clock speed for delay.h
#include <util/delay.h>		// include delay.h()

int main(void)
{
   DDRB = DDRB | 0b00011111 ;		//define pb0 to pb5 as output
  
    while (1) 
    {
		for(int i=0;i<=4;i++){
			PORTB = PORTB ^ (1<<i);
			_delay_ms(100);
			PORTB = PORTB & ~(1<<(i));
			_delay_ms(100);
			if(i==4){
				for (int j=4;j>=0;j--)
				{
					PORTB = PORTB ^ (1<<j);
					_delay_ms(100);
					PORTB = PORTB & ~(1<<(j));
					_delay_ms(100);
				}
			}
		}		
    }
	return 0;
}

