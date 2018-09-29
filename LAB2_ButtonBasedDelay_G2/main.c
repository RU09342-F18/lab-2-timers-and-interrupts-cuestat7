//Tiernan Cuesta
//Version: 1
//Revised 9/28
//Lab 2: Button Based Delay with G2

#include <msp430.h>


    volatile unsigned int time = 0;
    volatile unsigned int time1 = 0;



int main(void)
{
  WDTCTL = WDTPW + WDTHOLD;                 // Stop WDT

  BCSCTL3 = LFXT1S_2;                       // Forces ACLK to use internal oscillator
  TA0CTL = TASSEL_1 + MC_1;                  // Sets timer to ACLK source, and mode control to up
  CCTL0 = CCIE;                             // Enables CCR0 as the interrupt
  TA0CCR0 = 10000;
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

    P1IFG &= ~BIT3;                             // P1.3 IFG cleared
    if(P1IES & BIT3)
    {

        time = TA0R;   // records the value of the timer
    }
    else
    {
        time1 = TA0R;
        TA0CCR0 = time1 - time;
    }

    P1IES ^= BIT3;
}

#pragma vector=TIMER0_A0_VECTOR
__interrupt void Timer_A(void)

{
    P1OUT ^= 0x01;  // Toggles LED p1.0

}


