#ifndef __AVR_ATmega328P__
# define __AVR_ATmega328P__
#endif
#include <avr/io.h>

int main()
{
  // pinMode(9, OUTPUT);                               // Set digital pin 9 (D9) to an output
  DDRB |= 1 << 1;
  TCCR1A = (1 << COM1A1) |  (1 << WGM11);                // Enable the PWM output OC1A on digital pins 9
  TCCR1B = (1 << WGM13) | (1 << WGM12) | (1 << CS12);     // Set fast PWM and prescaler of 256 on timer 1
  ICR1 = 62500;                                     // Set the PWM frequency to 1Hz: 16MHz/(256 * 1Hz) - 1 = 62499
  OCR1A = 6250;                                     // Set the duty-cycle to 10%: 62499
  for(;;);
}