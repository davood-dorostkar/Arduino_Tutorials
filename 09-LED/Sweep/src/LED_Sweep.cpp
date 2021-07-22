#include <Arduino.h>
/*
SanatBazar
Arduino Turorial Series
Author: Davood Dorostkar
Website: www.sanatbazar.com

*/

int LED = 11;
float sweepTime = 2.0;                      // in seconds
float stepTime = sweepTime * 1000000 / 512; // in miliseconds

void setup()
{
  pinMode(LED, OUTPUT);
}

void loop()
{
  for (int i = 0; i < 255; i++)
  {
    analogWrite(LED, i);
    delayMicroseconds(stepTime);
  }
  for (int i = 255; i > 0; i--)
  {
    analogWrite(LED, i);
    delayMicroseconds(stepTime);
  }
  digitalWrite(LED, LOW);
  delay(2000);
}
