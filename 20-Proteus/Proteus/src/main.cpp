#include <Arduino.h>
/*
SanatBazar
Arduino Turorial Series
Author: Davood Dorostkar
Website: www.sanatbazar.com

*/

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  for (int i = 0; i < 1000; i++)
  {
    delay(100);
    Serial.println(i);
  }
}