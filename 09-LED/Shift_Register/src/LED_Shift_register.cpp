#include <Arduino.h>
/*
SanatBazar
Arduino Turorial Series
Author: Davood Dorostkar
Website: www.sanatbazar.com

*/

int dataPin = 7;
int latchPin = 6;
int clockPin = 5;

void doShiftRegister(int LED)
{
  digitalWrite(clockPin, LOW);
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, LED);
  digitalWrite(latchPin, HIGH);
}

void setup()
{
  pinMode(dataPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
}

void loop()
{
  byte LED;
  for (int i = 0; i < 8; i++)
  {
    bitSet(LED, i);
    doShiftRegister(LED);
    delay(40);
  }
  for (int i = 0; i < 8; i++)
  {
    bitClear(LED, i);
    doShiftRegister(LED);
    delay(40);
  }
}