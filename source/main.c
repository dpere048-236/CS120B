/*	Author: dpere048
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF; //port A 8 pins = inputs
	DDRB = 0xFF; PORTB = 0x00; //portB 8 pins = outputs
				   // PortB output to 0x00
	unsigned char temp_input = 0x00;
    /* Insert your solution below */
    while (1) {
		temp_input = PINA; //portB 8 pins with values on port A 8 pins
		PORTB = temp_input;

    }
    return 1;
}
