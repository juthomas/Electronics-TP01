#ifndef __AVR_ATmega328P__
# define __AVR_ATmega328P__
# define F_CPU 16000000
#endif
#include <avr/io.h>

int main()
{
	// On met OC1A (PB1) en OUTPUT
	DDRB |= 1 << PINB1;
	// On met la frequence PWM sur 1Hz: 16MHz/(256 * 1Hz) = 62500
	ICR1 = F_CPU / 256 - 1;
	// On met le duty-cycle sur 10%: 62500 * 0.1 = 6250
	OCR1A = (F_CPU / 256 - 1) * 0.1;
	// On active le mode PWM sur OC1A (16.11.1)
	TCCR1A = (1 << COM1A1) | (1 << WGM11);
	// On active fast PWM et le prescaler sur 256 pour le timer 1 (16.11.2)
	TCCR1B = (1 << WGM13) | (1 << WGM12) | (1 << CS12);
	for(;;);
}