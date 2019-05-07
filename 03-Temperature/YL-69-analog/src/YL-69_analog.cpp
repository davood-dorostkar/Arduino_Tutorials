#include <Arduino.h>
/*
SanatBazar
Arduino Turorial Series
Author: Davood Dorostkar
Website: www.sanatbazar.com

*/

#define soilPin A0
void setup()
{
  Serial.begin(9600);
}
void loop()
{
  int dryThreshold = 10;
  int moistureValue = analogRead(soilPin);
  moistureValue = map(moistureValue, 0, 1023, 100, 0);
  Serial.print("Soil Moisture is= ");
  Serial.print(moistureValue);
  Serial.print(" %");
  if (moistureValue > dryThreshold)
  {
    Serial.println(", Your plant is OK");
  }
  else
  {
    Serial.println(", Your plant needs water");
  }
  // delay(1000);
}
