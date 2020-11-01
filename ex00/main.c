#ifndef __AVR_ATmega328P__
# define __AVR_ATmega328P__
#endif
#include <avr/io.h>

int main()
{
	DDRB |= 1 << 1;
  TCCR1A = 0;
  TCCR1B = 0;

  OCR1A = 32250;
  // OCR1B = 50000;

//16.9.3   

  // section 15.9.2 prescaller a 256
  // TCCR1A |= 1 << COM1A1;
  //4 0 1 00 CTCOCR1AImmediateMAX
  TCCR1B = (1<<WGM12) |(1 << CS12);
  // 256 * 31250 = 8 000 000 soit 0.5sec vu que le quartz est a 16Mhz
  TCCR1A |= 1 << COM1A0;
  for(;;);
}