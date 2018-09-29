//Tiernan Cuesta
//Version: 1
//Revised 9/28
//Lab 1: Button Interrupt with G2

#include <msp430.h>

    volatile unsigned int hertz = 1;

int main(void)
{
  WDTCTL = WDTPW + WDTHOLD;                 // Stop WDT

  BCSCTL3 = LFXT1S_2;                       // Forces ACLK to use internal oscillator
  TACTL = TASSEL_1 + MC_1;                  // Sets timer to ACLK source, and mode control to up
  CCTL0 = CCIE;                             // Enables CCR0 as the interrupt
  //CCR0 = ((32768/(hertz*3))-1);              // Sets interrupt
  CCR0 = 16384/hertz;
  P1DIR |= 0x01;                            // Set P1.0 to output direction
  P1DIR |= 0x40;                            // Set P1.6 to output direction
  P1OUT |= BIT0 + BIT6;                     // Initializes the LEDS on

 // __bis_SR_register(LPM0_bits + GIE);       // Enter LPM0 w/ interrupt

  __enable_interrupt();
}
#pragma vector=TIMER0_A0_VECTOR
__interrupt void Timer_A(void)

{
    P1OUT ^= 0x01;  // Toggles LED p1.0
    P1OUT ^= 0x40;  // Toggles LED p1.6
}
