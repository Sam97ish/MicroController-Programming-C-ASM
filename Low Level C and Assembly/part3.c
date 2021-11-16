/*
 * Lab2-ALKAFAHJI.c
 *
 * Created: 9/29/2020 12:24:53 AM
 * Author : ALKHAFAJI
 */ 

#include <avr/io.h> 
#include <util/delay.h>

//#define F_CPU (1200000UL)
#define MS 500

int main(void)
{
	int count = 0;
	
    DDRA=0x00; //set data direction of PORTA to input (ring counter)
	DDRB=0xFF; //set data direction of PORTB to output
	PORTA = 0x00; //setting up the ring counter (low).
	
    while (1) 
    {
		
		
		PORTB = PORTA; //outputing the current tick of the counter to PORTB.
		
		PORTA = 1<<count; //ticking the ring counter to the right.
		
		count++; 
		
		if(count == 8){//when we reach the 8th bit we start over to simulate a circular counter.
			count = 0;
		}

		_delay_ms(MS);
		
	}
	
}

