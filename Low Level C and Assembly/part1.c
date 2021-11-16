/*
 * Lab2-ALKAFAHJI.c
 *
 * Created: 9/29/2020 12:24:53 AM
 * Author : ALKHAFAJI
 */ 

#include <avr/io.h> 


int main(void)
{
	 
    DDRA=0xFF; //set data direction of PORTA to output
    while (1) 
    {
		//1010 1010
		PORTA=0xAA;
	}
}
