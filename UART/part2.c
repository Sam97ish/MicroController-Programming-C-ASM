/*
 * assignment3.c
 *
 * Created: 10/14/2020 12:21:03 PM
 * Author : ALKAHFAJI
 */ 


#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRB = 0x0F; //lower nibble of PORTB is output.
	DDRD = 0xF0; //upper nibble of PORTD is output.
	
	PORTB = 0x00;
    
    while (1) 
    {
		int bitofD = PIND >> 2;
		int counter = 0b00010000;
		while(bitofD){
			counter = counter >> 1;
			PORTB |= counter;
			_delay_ms(500);
		}

    }
}

