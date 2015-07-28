#include <Servo.h>

Servo servo;
int servoPin = 5;
int analogPin = 0;
int analogValue;

void setup() {
  servo.attach(servoPin);
}

void loop() {
  analogValue = analogRead(analogPin);
  analogValue = map(analogValue, 0, 1023, 179, 0);
  servo.write(analogValue);
  delay(15);
}
