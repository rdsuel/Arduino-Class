
// Defines which pin the LED is connected to.
int ledPin = 5;
// Used to track that current state of the LED.
bool ledState = LOW;

void setup() {
  // This function is executed once at startup.  
  
  // Configure the LED pin as an output.
  pinMode(ledPin, OUTPUT);

  // Set up the serial window for 9600 baud.
  Serial.begin(9600);
}

void loop() {
  // This loop is called repeatedly, so we will manage the blinking from here.
  
  // Toggle the LED.
  if (ledState == LOW)
  {
    ledState = HIGH;
  }
  else
  {
    ledState = LOW;
  }
  setLed(ledState);
  printLedState(ledState);
  
  // This delay will allow us to meet the 1Hz blink frequency (500ms on, 500ms off).
  delay(500);
}

void setLed(bool state)
{
  digitalWrite(ledPin, state);
}

void printLedState(bool state)
{
  // Create a string for sending to the serial window.
  String msg = "The LED state is:";
  msg = msg + String(state);
  Serial.println(msg);
}
  
