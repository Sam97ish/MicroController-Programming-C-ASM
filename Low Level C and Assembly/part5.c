/*
 * Lab2-ALKAFAHJI.c
 *
 * Created: 9/29/2020 12:24:53 AM
 * Author : ALKHAFAJI
 */ 

#include <avr/io.h> 
#include <time.h>
#include <avr/eeprom.h>

int main(void)
{	
	//using the eeprom to provide a different seed each time.
	if(eeprom_read_byte((uint8_t*)20) == 0){
		eeprom_write_byte ((uint8_t *)20,1); 
	}
	int seed = eeprom_read_byte((uint8_t*)20);
	srand(time((time_t)seed));//sets the seed according to sys time in seconds.
	seed++;
	eeprom_update_byte((uint8_t*)20,seed);
	
    DDRA=0x00; //set data direction of PORTA to input
	DDRB=0xFF; //set data direction of PORTB to output

	
    while (1)
    {
		int pressed = PINA&1; //checking the button if pressed in O/I view.
		if(pressed){
			int num = rand();
			PORTB = num % 6 + 1; //(1-6)
		}
	    
    }

}


