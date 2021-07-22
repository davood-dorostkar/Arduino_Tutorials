#include <Arduino.h>
/*
SanatBazar
Arduino Turorial Series
Author: Davood Dorostkar
Website: www.sanatbazar.com

*/

#include <Servo.h>
Servo servo;
#define Pot A0

void setup()
{
  Serial.begin(9600);
  servo.attach(3);
}

void loop()
{
  int angle = analogRead(Pot);
  servo.write(map(angle, 0, 1023, 0, 180));
  Serial.println(servo.read());
}
