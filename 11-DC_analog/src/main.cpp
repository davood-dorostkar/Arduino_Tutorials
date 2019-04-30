#include <Arduino.h>

#define motorPin 9

void setup()
{
  pinMode(motorPin, OUTPUT);
}

void loop()
{
  for (int i = 0; i < 255; i++)
  {
    analogWrite(motorPin, i);
    delay(30);
  }
  for (int i = 255; i > 0; i--)
  {
    analogWrite(motorPin, i);
    delay(30);
  }
  delay(2000);
}