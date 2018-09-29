//Tiernan Cuesta
//Version: 1
//Revised 9/28
//Lab 2: Button Based Delay with F5529

#include <msp430.h>


    volatile unsigned int time = 0;
    volatile unsigned int time1 = 0;



int main(void)
{
  WDTCTL = WDTPW + WDTHOLD;                 // Stop WDT

  TA0CTL = TASSEL_1 + MC_1;                 // Sets timer to ACLK source, and mode control to up
  TA0CCTL0 = CCIE;                             // Enables CCR0 as the interrupt
  TA0CCR0 = 10000;                          // Sets an initial value for CCR0
  P1DIR |= 0x01;                            // Set P1.0 to output direction
  P1REN |= BIT1;                            // Enables the resistor or pull up or pull down
  P1OUT = BIT1;                             // Sets P1.3, button, to an input
  P1IE |= BIT1;                             // Enables the interrupt
  P1IES |= BIT1;                            // Sets interrupt to trigger on rising edge. (change | to & to have interrupt trigger on falling edge)
  P1IFG &= ~BIT1;

  __enable_interrupt();

}
#pragma vector=PORT1_VECTOR
__interrupt void Port_1(void)               // Button Interrupt

{

    P1IFG &= ~BIT1;                         // P1.3 IFG cleared
    if(P1IES & BIT1)                        // Executes if button is pressed
    {

        time = TA0R;                        // records the value of the timer at button press
    }
    else
    {
        time1 = TA0R;                       // records the value of the timer at button release
        TA0CCR0 = time1 - time;             // sets new value of CCR0
    }

    P1IES ^= BIT1;                          // toggles the button interrupt mode, rising/falling edge
}

#pragma vector=TIMER0_A0_VECTOR
__interrupt void Timer_A(void)              // Timer A interrupt

{
    P1OUT ^= 0x01;                          // Toggles LED p1.0

}
