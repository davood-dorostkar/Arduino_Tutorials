#include <Arduino.h>
/*
SanatBazar
Arduino Tutorial Series
Author: Davood Dorostkar
Website: www.sanatbazar.com

*/

#include <SoftwareSerial.h>
#define ledPin 5
int state = 0;
SoftwareSerial bluetooth(2, 3);

void setup()
{
  Serial.begin(9600);
  bluetooth.begin(9600);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, state);
}

void loop()
{
  if (bluetooth.available() > 0)
  {
    int message = bluetooth.read();
    message -= 48;
    if (message != state)
    {
      state = message;
      digitalWrite(ledPin, state);
    }
  }
}
