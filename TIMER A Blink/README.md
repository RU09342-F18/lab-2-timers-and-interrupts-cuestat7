# Timer A Blink
This section of the lab was done using the G2553 and P401R. Throughout this report the functionality and description of the code are the exact same in the methods of completeing the task. However, the main difference between the two programs are the syntax involved with the timer interrupt.
## Functionality
This program simply blinks a green LED. The LED's blinking is controlled by the TimerA interrupt vector. The frequency of the LED can be changed by changing the value of the volatile unsigned integer 'hertz.' 
## Valid Inputs/Outputs
There are no inputs for this program however, the frequency of the LED can be changed by internally altering the value of the 'hertz' integer. The only output being the LED, which should blink at this said frequency.

## Description of code
To achieve desired functionality the TimerA interrupt vector was implemented to control the toggling of the on-board LEDs. The timer clock source used is ACLK, with a frequency of 32,768 Hz, counting in up mode. The timer register CCR0 holds the cycles in which the LED will be blinking. When the timer reaches CCR0 then the LED will toggle via a timer interrupt.
