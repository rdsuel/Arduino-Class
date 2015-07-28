# Arduino-Class
This repo contains the class materials for the "Arduino Basics" class that I teach at General Electric. It will cover multiple examples intended to teach basic concepts needed to program for Arduinos.

## Arduino Software Reference 
We will be using the following Arduino Language Reference page extensively. It defines software structure, variables and functions needed to program for the Arduino.

https://www.arduino.cc/en/Reference/HomePage

## Exercise 1: Blink an LED

### Concepts
Digital Outputs, Timing, Serial Window, Functions

### Schematic
![Exercise 1](/schematics/exercise_1.png)

### Details
Connect an LED and current limiting resistor (200 Ohm, blue resistor) to pin 5 of the Arduino Uno. Blink the LED at 1Hz (500ms on, 500ms off). Use functions to encapsulate functionality where possible.

## Exercise 2: Add a button

### Concepts
Digital Inputs

### Schematic
![Exercise 2](/schematics/exercise_2.png)

### Details
Connect a push button to pin 4 of the Arduino Uno as shown in the schematic. Be sure to add a 10K pulldown resistor to the pin 4 side of the button so that the input is not floating (prevents false readings). 

Update the code so that each button press adjusts the blink rate as follows (On time = Blink Rate, Off time = Blink Rate):

Press | Blink Rate (ms)|
--- | --- | --- |
1 | 400 |
2 | 300 |
3 | 200 |
4 | 100 |

