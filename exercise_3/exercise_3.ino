int ledPin = 5;
int buttonPin = 3;
bool ledState = LOW;
bool buttonValue = LOW;
bool previousButtonValue = LOW;
unsigned long previousTime = 0;
int blinkRate = 500;
int pressCount = 0;
int analogPin = 0;
unsigned long previousAnalogTime = 0;
int analogValue;
unsigned char ledBrightness = 255;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
}

void loop() {

  blinkLed();
  
  detectButtonPress();
  
  readAnalogInput();
}

void readAnalogInput()
{
  // Calculate elapsed time using the millis() function.
  unsigned long elapsedTime;
  String displayMessage = "Analog Value: ";
  
  elapsedTime = millis() - previousAnalogTime;
  
  if (elapsedTime >= 200)
  {
    previousAnalogTime = millis();
    analogValue = analogRead(analogPin);
    Serial.println(String("Analog Value: ") + String(analogValue));
    
    ledBrightness = (unsigned char)(((unsigned long)analogValue * 255)/1023);
    Serial.println(String("Brightness:   ") + String((unsigned long)ledBrightness*100/255));
  }
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
      analogWrite(ledPin, ledBrightness);
    }
    else
    {
      ledState = LOW;
      analogWrite(ledPin, 0);
    }
  }
}
