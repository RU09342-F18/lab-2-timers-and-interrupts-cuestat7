
//Tiernan Cuesta
//Version: 1
//Revised 9/28
//Lab 2: TimerA Interrupt with G2
#include "msp.h"

    volatile unsigned int hertz = 1;

int main(void)
{
  WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;       // Disable watchdog timer
  TA0CTL = TASSEL_1 + MC_1;                         // Sets timer to ACLK source, and mode control to up
  TA0CCTL0 = CCIE;                                  // Enables CCR0 as the interrupt
  TA0CCR0 = 32768/hertz;                            // Sets interrupt
  P1DIR |= 0x01;                                    // Set P1.0 to output direction
  P1DIR |= 0x40;                                    // Set P1.6 to output direction

  NVIC->ISER[0] = 1 << ((TA0_0_IRQn) & 31);         // Set TimerA0_0 as interrupt

  __enable_irq();                                   //enables use of timer interrupt
}

  void TA0_0_IRQHandler(void)                       // Interrupt when Timer hits TA1CCR0
  {
     TIMER_A0->CCTL[0] &= ~TIMER_A_CCTLN_CCIFG;     // clear interrupt flag
      P1OUT ^= BIT0;                                // P1.0 red LED toggle
  }
