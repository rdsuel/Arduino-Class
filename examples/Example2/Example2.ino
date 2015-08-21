int ledPin = 5;
int buttonPin = 3;
bool buttonValue = LOW;
bool previousButtonValue = LOW;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  buttonValue = digitalRead(buttonPin);

  // See if the button has changed.
  if (buttonValue != previousButtonValue)
  {
    previousButtonValue = buttonValue;
    if (buttonValue == HIGH)
    {
      digitalWrite(ledPin, HIGH);
      Serial.println("Press");
    }
    else
    {
      digitalWrite(ledPin, LOW);
      Serial.println("Release");
    }
  }

}
