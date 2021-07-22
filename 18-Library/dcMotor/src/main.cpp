/*
SanatBazar
Arduino Turorial Series
Author: Davood Dorostkar
Website: www.sanatbazar.com

*/

#include <dcMotor.h>
#define enablePin 10
#define input1Pin 9
#define input2Pin 8
dcMotor dc(input1Pin, input2Pin, enablePin);

void setup()
{
}

void loop()
{
  dc.forwardSweep(30);
  dc.backwardSweep(30);
  delay(2000);
}