<<<<<<< HEAD
# Arduino-Class
This repo contains the class materials for the "Arduino Basics" class that I teach at General Electric. It will cover multiple examples intended to teach basic concepts needed to program for Arduinos. All examples are based on the Arduino Uno Rev 3. You can get a "clone" Uno R3 on Amazon for less than $15, here is an example: http://amzn.com/B00SZSFFY0.


## Arduino Software Reference 
We will be using the following Arduino Language Reference page extensively. It defines software structure, variables and functions needed to program for the Arduino.

https://www.arduino.cc/en/Reference/HomePage

<hr>

## Exercise 1: Blink an LED
Connect an LED and current limiting resistor (200 Ohm, blue resistor) to pin 5 of the Arduino Uno. Blink the LED at 1Hz (500ms on, 500ms off). Use a 'function' to perform the actual LED control.

### Concepts
Digital Outputs, Basic Timing, Functions

### Schematic
![Exercise 1](/schematics/exercise_1.png)

<hr>

## Exercise 2: Adjust blink rate with a button
Connect a push button to pin 3 of the Arduino Uno as shown in the schematic. Be sure to add a 10K pulldown resistor to the "arduino side" of the button so that the input is not floating when the button is not pressed(prevents false readings). 

1. Update the LED function to calculate elapsed time using the 'millis()' function instead of using 'delay(500);' in the main loop.

2. Add new code that prints "Press" and "Release" to the serial window each time the button is pressed/released.

3. Finally, modify the LED blink rate each time the button is pressed. The blink rates should match the following table, and after the 4th button press should wrap back around to a 500ms blink rate (as in exercise 1).

Press | Blink Rate (ms)|
--- | --- | --- |
1 | 400 |
2 | 300 |
3 | 200 |
4 | 100 |

### Concepts
Digital Inputs, Advanced Timing, Serial Window

### Schematic
![Exercise 2](/schematics/exercise_2.png)

<hr>

## Exercise 3: Adjust brightness with an analog knob
Connect a potentiometer (analog knob) to analog input 0 (AN0) as shown in the schematic. After connecting the knob, add the following code:

1. Read and print the analog input value to the Serial window every 1 second.

2. Convert the LED output to a PWM output and set the duty cycle (brightness) based on the value of the Analog input. The equation for scaling the brightness is as follows:

`ledBrightness = (unsigned char)(((unsigned long)analogValue * 255)/1023);`

### Concepts
Analog Inputs, PWM Outputs

### Schematic
![Exercise 3](/schematics/exercise_3.png)

<hr>

## Exercise 4: Control a servo with an analog knob
We will only be using the analog knob from the previous exercises. You can remove all components from the right side of your Arduino (button, led, resistors). Connect the servo to the Arduino as shown in the schematic below.

We could write the software to control the servo manually using very specific timing and digital output pulse widths. However, one of the great things about Arduino is that there is a very active community. Chances are, someone has already solved the problem you are trying to tackle. That is the case for servo control. In this example, we will be importing the "Servo" library to control our servo.

The goal of this exercise is to have the servo rotate along with the analog knob (turn knob left, servo goes left proportionally and vice-versa).

### Concepts
Using Libraries, Controlling Servo Motors

### Schematic
![Exercise 4](/schematics/exercise_4.png)

<hr>

## Exercise 5: Control a servo using your breath!
For this last exercise, we will connect a temperature sensor to the Arduino, display the temperature and relative humidity to the serial window, and control the servo when the temperature reaches certain thresholds. We will be working along with the following tutorial for the temp sensor: https://learn.adafruit.com/dht/connecting-to-a-dhtxx-sensor

1. Download the DHT temperature sensor library zip file from here: https://github.com/adafruit/DHT-sensor-library and save it to your desktop.

2. Import the temperature sensor library into the Arduino development environment using: "Sketch -> Include Library -> Add .ZIP Library...". Then select the zip file you downloaded in step 1.

3. Start a new project based on the DHT example: "File -> Examples -> DHT sensor library". 

4. Comment out '#define DHTTYPE DHT22' and uncomment '#define DHTTYPE DHT11', since we are using the DHT11 sensor.

5. Include the servo library '#include <Servo.h>'. Add the appropriate logic to turn the servo to 150 degrees when the temperature exceeds 80F. Add logic to return to 90 degrees when the temperature falls below 78F.

### Concepts
Importing 3rd Party Libraries, Interfacing with Temp/RH Sensors

### Schemtatic
![Exercise 5](/schematics/exercise_5.png)

<hr>

#### Thanks for looking ... hopefully you learned something new!

=======
# Arduino Class
Materials for my Arduino class taught at GE Appliances.
>>>>>>> b4b4b4d624a1a782e3ff71719fabe1e6a4d9a0f2
