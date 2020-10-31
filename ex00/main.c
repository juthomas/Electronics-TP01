#ifndef __AVR_ATmega328P__
# define __AVR_ATmega328P__
#endif
#include <avr/io.h>

int main()
{
  TCCR1A = 0;
  TCCR1B = 0;
  TCCR1B |= 1 << CS12;
  OCR1A = 62500;
  TCCR1A |= 1 << COM1A0;
	DDRB = 1 << 1;
  for(;;);
}