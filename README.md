# On-Demand-Traffic-Light-Control

1- System Description:
The system is an on-demand traffic light control which simulates the
traffic lights from the real life with an added component which is a button to prioritize the crossing of the pedestrians waiting.

2- System Design:
The system consists of:
• ATMEGA32
• 2 Green LEDs
• 2 Yellow LEDs
• 2 Red LEDs
• 6 300 Ohm Resistors
• 1 10k Ohm Resistor
• 1 Push Button
We have 6 LEDs (3 for the Cars & 3 for the Pedestrians) each “3”pair consists of 1 Green led, 1 Yellow led and 1 Red led each one connected to a port in the ATMEGA32 Microcontroller.To enable the Pedestrians movement we have a push button connected to Interrupt 0 pin.

3- System Constraints:
The system is triggered by a press of a button, A single short press is more than enough to enable the pedestrian’s mode.
By knowing that let’s dive into system constraints:
• Double button presses: when this is the case, the pedestrian mode will be enabled after the first press and the second press will have no impact at all.
• Long button press: when making a long press, there won’t be any changes in the modes and all will remain in the normal mode.
