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
//Creating object for clockwise rotation
Stepper driveCW(stepsPerRevolution, redWire, greenWire, yellowWire, blueWire);
//Creating object for counter-clockwise rotation
Stepper driveCCW(stepsPerRevolution, greenWire, redWire, yellowWire, blueWire);

void setup()
{
  driveCW.setSpeed(15);
}
void loop()
{
  driveCW.step(stepsPerRevolution);
  delay(1000);
  driveCCW.step(stepsPerRevolution);
  delay(1000);
}