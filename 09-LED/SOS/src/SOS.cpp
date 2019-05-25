#include <Arduino.h>
/*
SanatBazar
Arduino Turorial Series
Author: Davood Dorostkar
Website: www.sanatbazar.com

*/

int LED = 12;
const int SOS[] = {100, 100, 100, 300, 300, 300, 100, 100, 100};
const int rest[] = {100, 100, 500, 300, 300, 500, 100, 100, 100};
const int blinks = sizeof(SOS) / sizeof(const int);
void setup()
{
  pinMode(LED, OUTPUT);
}

void loop()
{
  for (int i = 0; i < blinks; i++)
  {
    digitalWrite(LED, HIGH);
    delay(SOS[i]);
    digitalWrite(LED, LOW);
    delay(rest[i]);
  }
  digitalWrite(LED, LOW);
  delay(2000);
}
