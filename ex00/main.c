#include <avr/io.h>

int main()
{
	DDRB |= 1 << 1;
	
	TCCR1A = 0;
  	TCCR1B = 0;
  	TCCR1B |= 1 << CS12;  // 256 prescaler
  	OCR1A = 62500;
  	
	
	TCCR1A |= 1 << COM1A0; // Toggle pin OC1A (9)
	//TCCR1A |= COM1A1; // Toggle pin OC1A (9)

	//TCCR1B = (1 << CS11);  //Prescale clock by 8

	for(;;);
}