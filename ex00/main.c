#ifndef __AVR_ATmega328P__
# define __AVR_ATmega328P__
#endif
#include <avr/io.h>

int main()
{
	// On met OC1A (PB1) en OUTPUT
	DDRB |= 1 << 1;
	// On met le timer sur 500ms: 16MHz/(256 * 0.5) = 31250
	OCR1A = 31250;
	// On met le prescaler sur 256 pour le timer 1 (16.11.2)
	TCCR1B = (1 << WGM12) |(1 << CS12);
	// On Toggle OC1A a chaque fois que le timer a match (Table 16-1)
	TCCR1A = 1 << COM1A0;
	for(;;);
}