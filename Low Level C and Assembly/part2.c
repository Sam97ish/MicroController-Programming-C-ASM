/*
 * Lab2-ALKAFAHJI.c
 *
 * Created: 9/29/2020 12:24:53 AM
 * Author : ALKHAFAJI
 */ 

#include <avr/io.h> 

int main(void)
{
    DDRA=0x00; //set data direction of PORTA to input
	DDRB=0xFF; //set data direction of PORTB to output
	PORTB = 0x00; //all LEDs are off.
	
    while (1) 
    {
		PINA ; //used as button using the O/I view.
		if(PINA != 0x00) //if any bit is high, we turn on all of PORTB LEDs.
		{
			PORTB = 0xFF; //set all LEDs to on if any pin is pressed.	
		}else{
			PORTB = 0x00; //set all LEDs to off if no pin is pressed.
		}
		
	}
}

