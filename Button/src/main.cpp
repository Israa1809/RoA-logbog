#include <Arduino.h>
#include <Button.h>

// put function declarations here:
int count = 0;
int buttonPin = D1;
bool _prevButtonState = false;

Button myButton(buttonPin, LOW);

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  myButton.setup(millis());
}

void loop()
{
  long now = millis();
  myButton.update(now);
  if (_prevButtonState != myButton.GetButtonState())
  {
    _prevButtonState = myButton.GetButtonState();
    if (_prevButtonState)
    {
      count++;
      Serial.println(count);
    }
  }
}