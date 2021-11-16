/*
 * Lab2-ALKAFAHJI.c
 *
 * Created: 9/29/2020 12:24:53 AM
 * Author : ALKHAFAJI
 */ 

#include <avr/interrupt.h>
#include <avr/io.h> 
#include <util/delay.h>

#define F_CPU (1200000UL)
#define MS 500

int isStopped = 0; //bool for interrupt control

ISR (INT0_vect){

	isStopped = !isStopped; //negating the boolean.

}

int main(void)
{
	int count = 0;
	
    DDRA=0x00; //set data direction of PORTA to input
	DDRB=0xFF; //set data direction of PORTB to output
	
	EICRA=0x01;   //Any edge of INT0 generates asynchronously an interrupt request.
	EIMSK=0x01;   //unmasking INT0.
	sei();   //enable the global interrupt enable bit
	
	PORTA = 0x00; //setting up the ring counter.
	
    while (1) 
    {
		//any change in the LSB of PIND will cause an interrupt.
		
		
		
		if(!isStopped){
			
			PORTB = PORTA; //outputting the current tick of the counter to PORTB.
					
			PORTA = 1<<count; //ticking the ring counter to the right.
					
			count++;
			_delay_ms(MS);
		}

		
		if(count == 8){
			count = 0;
		}

		
	}
	
}
