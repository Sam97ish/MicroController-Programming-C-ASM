/*
 * assignment3.c
 *
 * Created: 10/14/2020 12:21:03 PM
 * Author : ALKAHFAJI
*/


#define F_CPU 4000000UL // Defining the CPU Frequency
#define USART_BAUDRATE 19200 // Desired Baud Rate
#define UBRR (((F_CPU / (USART_BAUDRATE * 16UL))) - 1)

#include <stdlib.h>
#include <stdio.h>
#include <avr/io.h>      // Contains all the I/O Register Macros
#include <util/delay.h>  // Generates a Blocking Delay
#include <avr/eeprom.h>
#include <time.h>

int counter = 0;
int stop = 0;

// initializes the USART connection.                                                                    
void USART_Init()
{
	//lower nibble set to output
	DDRB = 0x0F;
	PORTB = 0x0F;
	//upper nibble set to output
	DDRD = 0xF0;
	PORTD = 0xF0;
	
	// Set Baud Rate
	UBRR0H = UBRR >> 8; //set to zero by default.
	UBRR0L = UBRR; // setting the lower nibble ( to approx 12).
	
	// Enable Receiver and Transmitter
	UCSR0B = (1<<RXEN0) | (1<<TXEN0);
}


// checks the USART if data has been received and outputs it to PORTD_HIGH and PORTB_LOW                                                                   
void USART_GetChar(char* c)
{
	
	while (( UCSR0A & (1<<RXC0)) == 0) {}; // Do nothing until data have been received
	
	c[counter] = UDR0 ; // put received data in character.
	
	if(c[counter] == '\n'){
		stop = !stop;
	}
	
	counter++;
	
	PORTB = *c & 0x0F; //displaying lower nibble so that we know the program has started.
	PORTD = *c & 0xF0; //displaying upper nibble so that we know the program has started.
}


// takes in a character which it gives to the USART transmitter to be transmitted.                                                                     
void USART_Char(char* c)
{
	while (( UCSR0A & (1<<UDRE0)) == 0) {}; // Do nothing until UDR is ready
	UDR0 = *c; //gives the char to UDR0 which transmits it.
}

//sends a string through the transmitter letter by letter.
void USART_SendString(char * str) {
	while (*str) {
		USART_Char(str++);
	}
}


int main(void) {
	
	//using the eeprom to provide a different seed each time.
	if(eeprom_read_byte((uint8_t*)20) == 0){
		eeprom_write_byte ((uint8_t *)20,1);
	}
	int seed = eeprom_read_byte((uint8_t*)20);
	srand(time((time_t)seed));//sets the seed according to sys time in seconds.
	seed++;
	eeprom_update_byte((uint8_t*)20,seed);
	
	
	USART_Init(); // initialize the connection.
	
	
	while (1) {
		
		//variable to store the character received.
		char* character = malloc(sizeof(char)*20);
		
		while(!stop){
			
			USART_GetChar(character); //get the characters from the receiver.
		
		}
		
		if(character[0] == 'r' && character[1] == '\r' && character[2] == '\n')
		{
			int num = rand() % 6 + 1; //generating a random number.
			
			//converting it to string.
			char str[16];
			itoa(num, str, 10);
			
			//sending the string through the transmitter.
			USART_SendString(str);
			
			stop = !stop;
			counter = 0;
			free(character);
			
		}else{
			char* fail = " \n That's not an r fam \n";
			USART_SendString(fail);
			stop = !stop;
			counter = 0;
			free(character);
		}
		
	}
}
