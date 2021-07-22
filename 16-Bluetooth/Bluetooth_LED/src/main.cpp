#include <Arduino.h>
/*
SanatBazar
Arduino Tutorial Series
Author: Davood Dorostkar
Website: www.sanatbazar.com

*/

#include <SoftwareSerial.h>
#define ledPin 5
int lastState = 0;
SoftwareSerial bluetooth(2, 3);

void setup()
{
  Serial.begin(38400);
  bluetooth.begin(38400);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, lastState);
}

void loop()
{
  if (bluetooth.available() > 0)
  {
    int message = bluetooth.read();
    message -= 48;
    if (message != lastState)
    {
      digitalWrite(ledPin, message);
      lastState = message;
    }
  }
}
