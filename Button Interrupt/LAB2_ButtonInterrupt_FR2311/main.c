//Tiernan Cuesta
//Version: 1
//Revised 9/28
//Lab 1: Button Interrupt with G2

#include <msp430.h>

int main(void)
{
  WDTCTL = WDTPW + WDTHOLD;                 // Stop WDT
  P1DIR |= 0x01;                            // Set P1.0 to output direction
  P1REN |= BIT1;                            // Enables the resistor or pull up
  P1OUT = BIT1;                             // Sets P1.3, button, to an input
  P1IE |= BIT1;                             // Enables the interrupt
  P1IES &= BIT1;                            // Sets interrupt to trigger on rising edge. (change | to & to have interrupt trigger on falling edge)
  P1IFG &= ~BIT1;                           // clears interrupt flag
 // __bis_SR_register(LPM0_bits + GIE);     // Enter LPM0 w/ interrupt

  __enable_interrupt();
}
#pragma vector=PORT1_VECTOR
__interrupt void Port_1(void)

{
    P1OUT ^= 0x01;  // Toggles LED p1.0
    P1IFG &= ~BIT1; // Clear interrupt flag
    P1IES ^= BIT1; // Sets interrupt to trigger on falling edge
}
