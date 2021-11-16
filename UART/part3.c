/*
 * assignment3.c
 *
 * Created: 10/14/2020 12:21:03 PM
 * Author : ALKAHFAJI
 */ 


#include <avr/io.h>
#include <avr/interrupt.h>

int main(void) {
	EICRA |= 0x03; // Using rising edge.
	EIMSK |= 0x01; // INT0!
	
	// Set data direction for low nibble of PORTB and high nibble of PORTD
	DDRB = 0x0F;
	DDRD = 0xF0;
	
	// Resetting B and D to known values
	PORTB = 0x00;
	PORTD = 0x00;
	
	// // Set the global interrupt enable flag here!
	sei();
	
	while (1) {
		// Do nothing, the toggle is supposed to happen in the interrupt
	}
}

ISR (INT0_vect) {
	// your implementation here
	// XOR operator recommended
	PORTD ^= 0xF0;
	PORTB ^= 0x0F;
}
