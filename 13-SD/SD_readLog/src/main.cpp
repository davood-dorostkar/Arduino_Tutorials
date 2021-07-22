#include <Arduino.h>
/*
SanatBazar
Arduino Tutorial Series
Author: Davood Dorostkar
Website: www.sanatbazar.com

*/

#include <SD.h>
#include <SPI.h>
#define SS 10
File weather;

void setup()
{
  Serial.begin(9600);
  SD.begin(SS);
  weather = SD.open("weather.txt");
  while (weather.available())
  {
    Serial.write(weather.read());
  }
  weather.close();
}

void loop()
{
}