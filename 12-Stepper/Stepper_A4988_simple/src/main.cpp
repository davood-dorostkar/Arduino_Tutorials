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
  stepperRun(stepsPerRevolution, 20);
  delay(1000);
  stepperRun(-stepsPerRevolution, 20);
  delay(1000);
  stepperRun(2 * stepsPerRevolution, 60);
  delay(1000);
  stepperRun(-2 * stepsPerRevolution, 60);
  delay(1000);
}