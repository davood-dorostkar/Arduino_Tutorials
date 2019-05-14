#include <Arduino.h>
/*
SanatBazar
Arduino Turorial Series
Author: Davood Dorostkar
Website: www.sanatbazar.com

*/

#define bluePin 5
#define greenPin 6
#define redPin 7

void RGB(int blue, int green, int red)
{
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}

void setup()
{
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop()
{
  RGB(0, 0, 0);
  delay(1000);
  for (int i = 0; i < 255; i++)
  {
    RGB(i, 0, 0);
    delay(10);
  }
  for (int i = 0; i < 255; i++)
  {
    RGB(255, i, 0);
    delay(10);
  }
  for (int i = 0; i < 255; i++)
  {
    RGB(255, 255, i);
    delay(10);
  }
  delay(1000);
}