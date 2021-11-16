/*
 * assignment3.c
 *
 * Created: 10/14/2020 12:21:03 PM
 * Author : ALKAHFAJI
 */ 

#include <stdlib.h>
#include <avr/io.h>      // Contains all the I/O Register Macros
#include <util/delay.h>  // Generates a Blocking Delay

#define F_CPU 4000000UL // Defining the CPU Frequency
#define USART_BAUDRATE 19200 // Desired Baud Rate
#define UBRR (((F_CPU / (USART_BAUDRATE * 16UL))) - 1)



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
	*c = UDR0 ; // put received data in character.
	
	PORTB = *c & 0x0F; //displaying lower nibble.
	PORTD = *c & 0xF0; //displaying upper nibble.
}


// takes in a character which it gives to the USART transmitter to be transmitted.                                                                    
void USART_Echo(char* c)
{
	while (( UCSR0A & (1<<UDRE0)) == 0) {}; // Do nothing until UDR is ready
	UDR0 = *c; //gives the char to UDR0 which transmits it.
}
int main(void) {
	
	//variable to store the character.
	char* character = malloc(sizeof(char)*100);
	
	USART_Init(); // initialize the connection.
	
	while (1) {
		
		USART_GetChar(character); //get the character from the receiver.
		USART_Echo(character); //sends it by giving it to the transmitter.
		
	}
	
	free(character);
}


