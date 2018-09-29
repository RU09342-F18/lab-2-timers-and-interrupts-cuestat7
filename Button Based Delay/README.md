# Button Based Delay
This section of the lab was done using the G2553 and F5529. Throughout this report the functionality and description of the code are the exact same in the methods of completeing the task. However, the only difference between the two main.c files is the instantiation of the one input, further explained in valid inputs/outputs secion.
## Functionality
This program simply blinks a green LED. The LED's blinking is controlled by a button via a port 1 and TimerA interrupt vectors. Initially the LED is blinking at a rate set by TA0CCR0. When the cooresponding button is pressed, the LED will blink with a frequency proportional to that of the time the button is held down.

## Valid Inputs/Outputs
The input for the G2553 chip is button P1.3, meanwhile the input for the F5529 is button P1.1. This is the difference in the code where the instantions of statements dependent on the button must be changed. The difference in syntax can be seen in the corresponding main.c files. The output instantiation for both chips is synonymous since the pinout is the same for the two LEDs.

## Description of code
To achieve desired functionality the port 1 and TimerA interrupt vectors were implemented to control the toggling of the on-board LEDs. The buttons are enabled as the port 1 interrupts. Before the button is initially pressed the port 1 interrupt is triggered on the rising edge of a button press. At this rising edge the interrupt is triggered and a time stamp of TimerA is recorded. Also, at the moment the button is released another time stamp is recorded. The difference of these two time stamps is then assigned to TA0CCR0 which is the value the timer is counting up to. Now, the TimerA interrupt vector comes into play. As soon as the timer hits the new CCR0 the interrupt is triggered and causes the LED to blink with the same rate.
