int ledPin = 5;
int buttonPin = 3;
bool ledState = LOW;
bool buttonValue = LOW;
bool previousButtonValue = LOW;
unsigned long previousTime = 0;
int blinkRate = 500;
int pressCount = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
}

void loop() {

  blinkLed();
  
  detectButtonPress();
}

void detectButtonPress()
{
  buttonValue = digitalRead(buttonPin);
  
  if (buttonValue != previousButtonValue)
  {
    previousButtonValue = buttonValue;
    if (buttonValue == HIGH)
    {
      Serial.println("Press");
      // Increment the press count and update the blink rate.
      pressCount++;
      updateBlinkRate();
    }
    else
    {
      Serial.println("Release");
    }
  }
}

void updateBlinkRate()
{
  switch (pressCount)
  {
    case 1:
      blinkRate = 400;
      break;
    case 2:
      blinkRate = 300;
      break;
    case 3:
      blinkRate = 200;
      break;
    case 4:
      blinkRate = 100;
      break;
    default:
      blinkRate = 500;
      pressCount = 0;
      break;
  }
  Serial.println(blinkRate);
}

void blinkLed()
{
  // Calculate elapsed time using the millis() function.
  unsigned long elapsedTime;
  
  elapsedTime = millis() - previousTime;
  
  // Blink the LED the desired time (ms) has elapsed.
  if (elapsedTime > blinkRate)
  {  
    // Store the previous time so we can detect the next timeout.
    previousTime = millis();
    
    // Toggle the led.
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
}
