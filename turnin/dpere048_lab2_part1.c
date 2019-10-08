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
	DDRB = 0xFF; PORTB = 0x00; //portB 8 pins = outputs, sets to 0s
	unsigned char tmpB = 0x00; //temp vriable for B
	unsigned char tmpA = 0x00; //temp variable for A
    /* Insert your solution below */
    while (1) {
		//Read input
		tmpA = PINA &0x03; //pins on A set to 0000 0011
		//Perform Computation
		//if PA0 Is 1 and PA1 is 1, set PB0 = 1, else = 0
		if (tmpA == 0x03) { //TRUE IF PA1PA0 = 11
			tmpB = (tmpB & 0xFE) | 0x01; //tmpB to bbbbbbb0, PB0 = 1
						    // clears rightmost bit, then sets to 1
		} else {
			tmpB = (tmpB & 0xFE) | 0x00; // Sets tmpB to bbbbbbb0
							 // (clear rightmost bit, then set to 0)
 		}			
		// 3) Write output
		PORTB = tmpB;
    }
    return 0;
}
