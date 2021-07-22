#include <Arduino.h>
/*
SanatBazar
Arduino Turorial Series
Author: Davood Dorostkar
Website: www.sanatbazar.com
*/

#define stepPin 3
#define directionPin 2
#define stepsPerRevolution 200

void stepperRun(int steps, int speedRpm)
{
  if (steps < 0)
  {
    digitalWrite(directionPin, LOW);
    steps = abs(steps);
  }
  else
    digitalWrite(directionPin, HIGH);
  long fullStepTime = 1000000 * 60 / (stepsPerRevolution * speedRpm); // in microseconds
  for (int i = 0; i < steps; i++)
  {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(fullStepTime / 2);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(fullStepTime / 2);
  }
}

void setup()
{
  pinMode(stepPin, OUTPUT);
  pinMode(directionPin, OUTPUT);
}

void loop()
{
  for (int i = 1; i < 10; i++)
    stepperRun(stepsPerRevolution * i / 4, 15 * i);
  for (int i = 9; i > 0; i--)
    stepperRun(stepsPerRevolution * i / 4, 15 * i);
  delay(3000);
}