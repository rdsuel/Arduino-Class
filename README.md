# Arduino-Class
This repo contains the class materials for the "Arduino Basics" class that I teach at General Electric. It will cover multiple examples intended to teach basic concepts needed to program for Arduinos.

## Arduino Software Reference 
We will be using the following Arduino Language Reference page extensively. It defines software structure, variables and functions needed to program for the Arduino.

https://www.arduino.cc/en/Reference/HomePage

## Exercise 1: Blink an LED

### Concepts
Digital Outputs, Basic Timing, Functions

### Schematic
![Exercise 1](/schematics/exercise_1.png)

### Details
Connect an LED and current limiting resistor (200 Ohm, blue resistor) to pin 5 of the Arduino Uno. Blink the LED at 1Hz (500ms on, 500ms off). Use a 'function' to perform the actual LED control.


## Exercise 2: Adjust blink rate with a button

### Concepts
Digital Inputs, Advanced Timing, Serial Window

### Schematic
![Exercise 2](/schematics/exercise_2.png)

### Details
Connect a push button to pin 4 of the Arduino Uno as shown in the schematic. Be sure to add a 10K pulldown resistor to the pin 4 side of the button so that the input is not floating (prevents false readings). 

1. Update the LED function to calculate elapsed time using the 'millis()' function instead of using 'delay(500);' in the main loop.

2. Add new code that prints "Press" and "Release" to the serial window each time the button is pressed/released.

3. Finally, modify the LED blink rate each time the button is pressed. The blink rates should match the following table, and after the 4th button press should wrap back around to a 500ms blink rate (as in exercise 1).

Press | Blink Rate (ms)|
--- | --- | --- |
1 | 400 |
2 | 300 |
3 | 200 |
4 | 100 |


## Exercise 3: Adjust brightness with an analog knob

### Concepts
Analog Inputs, PWM Outputs

### Schematic
![Exercise 3](/schematics/exercise_3.png)

### Details
Connect a potentiometer (analog knob) to analog input 0 (AN0) as shown in the schematic. After connecting the knob, add the following code:

1. Print the analog input value to the Serial window every 1 second.

2. Conver the LED output to a PWM output and set the duty cycle (brightness) based on the value of the Analog input. The equation for scaling the brightness is as follows:

`brightness = (analogValue * 255)/1023;`



