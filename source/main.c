/*	Author: David Perez dpere048@ucr.edu
 *  Partner(s) Name: 
 *	Lab Section: 022
 *	Assignment: Lab2 #  Exercise #2c
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
	DDRC = 0xFF; PORTC = 0x00; //pC 8 pins = outputs, set to 0s
//	unsigned char tmpB = 0x00; //temp vriable for B
	unsigned char tmpA = 0x00; //variable for A
	unsigned char cntavail = 0x00; //temp variable for number of places available
    /* Insert your solution below */
    while (1) {
		//Read input
	//	tmpA = PINA &0x03; //pins on A set to 0000 0011
		tmpA = PINA &0x0F; //pins on A set to 0000 1111	
	//Perform Computation
		
	//part 1 IF PA0 Is 1 and PA1 is 1, set PB0 = 1, else = 0
	//part 2 if PA3A2A1A0 = 	
	if (tmpA == 0x01 || tmpA == 0x02 || tmpA == 0x04 || tmpA == 0x08  ) { //TRUE IF PA3210 =1111
			cntavail = 3; //cntavail in binary to bbbb 0011
	} else if(tmpA == 0x09 || tmpA == 0x06 || tmpA == 0x0A || tmpA == 0x03 || tmpA == 0x0C || tmpA == 0x05){
			cntavail = 2;
	} else if(tmpA == 0x0E || tmpA == 0x00 || tmpA == 0x00 || tmpA == 0x00 ){
			cntavail = 1;
	} else if(tmpA == 0x0F){
			cntavail = 128 ;// portc7 =1 if full
	} else{
		cntavail = 4;
}
PORTC = cntavail; //sets pins on C which are outputs, to variable cnt avail			
    }
    return 0;
}
