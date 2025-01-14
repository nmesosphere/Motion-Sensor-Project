/*
 * main.c
 *
 * Created: 12/29/2024 6:59:53 PM
 *  Author: Nmesoma :)
 *
 * Microcontroller: ATMega328P (Miuzei)
 */ 

// NOTE:: This is simply a base; will be tested and improved with time. 

#include <stdio.h>
#include <avr/io.h>

int main(void)
{
	DDRD &= ~(1 << DDD3); // Sets pin 3 (PD3) of microcontroller to 'input'
	DDRD |= (1 << DDD7); // Sets pin 7 (PD7) of the microcontroller to 'output'
	
	// Initializes at 0 (no motion is detected). LED should be 'off'
	int motionDetected = 0;
	
    while(1)
    {
		motionDetected = (PIND & (1 << PIND3));
		if (motionDetected)
			{ 
				PORTD |= (1 << PORTD7); // Turns the LED light on 
				printf("Motion detected\n");
			} 
		else 
			{ PORTD &= ~(1 << PORTD7); } // Turns LED off
		
    }
}
