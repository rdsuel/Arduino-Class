int ledPin = 5;
int buttonPin = 3;
int knobPin = 0;
volatile bool buttonPressed = LOW;
int analogValue = 0;
int brightness = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);

  // Interrupt 1 is tied to pin 3 (our button pin) on the Uno.
  attachInterrupt(1, buttonChanged, CHANGE);

  Serial.begin(9600);
}

void loop() {
  analogValue = analogRead(knobPin);
  brightness = map(analogValue, 0, 1023, 0, 255);
  Serial.println(brightness);
  
  if(buttonPressed)
  {
    analogWrite(ledPin, brightness);
  }
  else
  {
    analogWrite(ledPin, 0);
  }
}

// This function is only called when the button changes.  It's not called repeatedly.
void buttonChanged(){
  buttonPressed = digitalRead(buttonPin);
  if(buttonPressed)
  {
    Serial.println("press");
  }
  else
  {
    Serial.println("release");
  }
}
