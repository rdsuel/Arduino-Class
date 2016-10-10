int ledPin = 5;
int buttonPin = 3;
volatile bool buttonValue = LOW;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  // Interrupt 1 is tied to pin 3 (our button pin) on the Uno.
  attachInterrupt(1, buttonChanged, CHANGE);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(ledPin, buttonValue);
}

// This function is only called when the button changes.  It's not called repeatedly.
void buttonChanged(){
  buttonValue = digitalRead(buttonPin);
  if(buttonValue)
  {
    Serial.println("press");
  }
  else
  {
    Serial.println("release");
  }
}
