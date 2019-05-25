#include <Arduino.h>
/*
SanatBazar
Arduino Turorial Series
Author: Davood Dorostkar
Website: www.sanatbazar.com

*/

#include <Servo.h>
Servo servo1;
Servo servo2;
#define servo1Pin 5
#define servo2Pin 6
#define XJoystick A0
#define YJoystick A1
#define pushJoystick 7 // Use 10K Pullup resistor
#define LED 13

void setup()
{
  servo1.attach(servo1Pin);
  servo2.attach(servo2Pin);
  pinMode(pushJoystick, INPUT);
  pinMode(LED, OUTPUT);
}

void loop()
{
  int AngleX = map(analogRead(XJoystick), 0, 1023, 0, 180);
  int AngleY = map(analogRead(YJoystick), 0, 1023, 0, 180);
  servo1.write(AngleX);
  servo2.write(AngleY);
  digitalWrite(LED, !digitalRead(pushJoystick));
}
