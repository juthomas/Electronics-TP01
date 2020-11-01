#include <avr/io.h>

int main()
{
	DDRB |= 1 << 1;
	TCCR1A = 0;
  	TCCR1B = 0;
	OCR1A = 32550;
  	TCCR1B |= (1<<WGM12)|(1<<CS12); // We get the CTC Mode that clear the timer on compare match
  	
	TCCR1A |= 1 << COM1A0;
	 // Here we tell that it have to be in Compare Match and toogle 0C1A (our LED).

	for(;;);
}