//Tiernan Cuesta
//Version: 1
//Revised 9/28
//Lab 1: Button Interrupt with G2

#include <msp430.h>

int main(void)
{
  WDTCTL = WDTPW + WDTHOLD;                 // Stop WDT
  P1DIR |= 0x01;                            // Set P1.0 to output direction
  P1REN |= BIT3;                            // Enables the resistor or pull up or pull down
  P1OUT = BIT3;                             // Sets P1.3, button, to an input
  P1IE |= BIT3;                             // Enables the interrupt
  P1IES |= BIT3;                            // Sets interrupt to trigger on rising edge. (change | to & to have interrupt trigger on falling edge)
  P1IFG &= ~BIT3;
 // __bis_SR_register(LPM0_bits + GIE);       // Enter LPM0 w/ interrupt

  __enable_interrupt();
}
#pragma vector=PORT1_VECTOR
__interrupt void Port_1(void)

{
    P1OUT ^= 0x01;  // Toggles LED p1.0
    P1IFG &= ~BIT3; // Clear interrupt flag
    P1IES ^= BIT3; // Sets
}


