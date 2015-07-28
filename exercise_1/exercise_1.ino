
int ledPin = 5;
bool ledState = LOW;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {

  blinkLed();
 
  delay(500);
}

void blinkLed()
{
    if (ledState == LOW)
    {
      ledState = HIGH;
    }
    else
    {
      ledState = LOW;
    }
    digitalWrite(ledPin, ledState);
}
  
