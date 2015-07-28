
int ledPin = 5;
bool ledState = LOW;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  blinkLed();
  printLedState();
  
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

void printLedState()
{
  String msg = "The LED state is:";
  msg = msg + String(ledState);
  Serial.println(msg);
}
  
