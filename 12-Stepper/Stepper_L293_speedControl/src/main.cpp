#include <Arduino.h>
/*
SanatBazar
Arduino Turorial Series
Author: Davood Dorostkar
Website: www.sanatbazar.com
*/

#include <Stepper.h>
#define stepsPerRevolution 200
// Coil#1: Red-Green
// Coil#2: Yellow-Blue
#define redWire 2
#define greenWire 3
#define yellowWire 4
#define blueWire 5
Stepper driveCW(stepsPerRevolution, redWire, greenWire, yellowWire, blueWire);

void setup()
{
  driveCW.setSpeed(60);
}

void loop()
{
  driveCW.step(stepsPerRevolution);
  delay(1000);
  driveCW.step(-stepsPerRevolution);
  delay(1000);
}