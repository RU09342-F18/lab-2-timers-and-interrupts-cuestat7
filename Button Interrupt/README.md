# Button Interrupt
This section of the lab was done using the G2553 and FR2311. Throughout this report the functionality and description of the code are the exact same in the methods of completeing the task. However, the only difference between the two main.c files is the instantiation of the one input, further explained in valid inputs/outputs secion.
## Functionality
This program simply blinks a green LED. The LED's blinking is controlled by a button via a port 1 interrupt vector. When the button is pressed the LED is set, and cleared when the button is released. 

## Valid Inputs/Outputs
The input for the G2553 chip is button P1.3, meanwhile the input for the FR2311 is button P1.1. This is the difference in the code where the instantions of statements dependent on the button must be changed. The difference in syntax can be seen in the corresponding main.c's. The output for both chips is synonymous since the pinout is the same for the two LEDs. The LED should only blink when the coorsponding button is pressed.

## Description of code
To achieve desired functionality the port 1 interrupt vector was implemented to control the toggling of the on-board LEDs. Before the button is initially is pressed the interrupt is triggered on the rising edge. However, after the button is pressed and held the LED is turned on and now the interrupt is set to trigger on the falling edge. Setting the interrupt to trigger on the falling edge causes the LED to turn off at the moment the button is released.
