#ifndef __AVR_ATmega328P__
# define __AVR_ATmega328P__
#endif
#include <avr/io.h>

int main()
{
  DDRB |= 1 << 1;                                       // (OC1A PB1) on met OC1A en OUTPUT
  TCCR1A = (1 << COM1A1) |  (1 << WGM11);                // On active le mode PWM sur OC1A (16.11.1)
  TCCR1B = (1 << WGM13) | (1 << WGM12) | (1 << CS12);     // On active fast PWM et le prescaler sur 256 pour le timer 1 (16.11.2)
  ICR1 = 62500;                                     // On met la frequence PWM sur 1Hz: 16MHz/(256 * 1Hz) = 62500
  OCR1A = 6250;                                     // On met le duty-cycle sur 10%: 62500 * 0.1 = 6250
  for(;;);
}