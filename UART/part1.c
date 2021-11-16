/*
 * assignment3.c
 *
 * Created: 10/14/2020 12:21:03 PM
 * Author : ALKAHFAJI
 */ 

#include <avr/io.h>


int main(void)
{
	DDRB = 0x0F; //lower nibble of PORTB is output.
	DDRD = 0xF0; //upper nibble of PORTD is output.
	
    
    while (1) 
    {
		PORTB = 0x09; //lower nibble 1001.
		PORTD = 0x90; //upper nibble 1001.
    }
}
