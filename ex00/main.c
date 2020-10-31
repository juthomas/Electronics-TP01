#include <avr/io.h>

int main()
{
	DDRB |= 1 << 1;
	
	TCCR1A = 0;
  	TCCR1B = 0;
  	TCCR1B |= 1 << CS12; // 256 * 31250 = 8 000 000 soit 0.5sec vu que le quartz est a 16Mhz
  	OCR1A = 31250; // Here we tell that whenever Timer1 gets to 62500 it does something
  	
	
	TCCR1A |= 1 << COM1A0; // Here we tell that it have to be in Compare Match and toogle 0C1A (our LED).

	for(;;);
}