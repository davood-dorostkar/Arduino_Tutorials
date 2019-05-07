#include <Arduino.h>
/*
SanatBazar
Arduino Turorial Series
Author: Davood Dorostkar
Website: www.sanatbazar.com

*/

#define XJoystick A0
#define YJoystick A1
#define pushJoystick 7 // Use 10K Pullup resistor
#define LED 13

void setup(){
  pinMode(pushJoystick,INPUT);
  pinMode(LED,OUTPUT);
  Serial.begin(9600);
}

void loop(){
  int AngleX=map(analogRead(XJoystick),0,1023,-90,90);
  int AngleY=map(analogRead(YJoystick),0,1023,-90,90);
  digitalWrite(LED,!digitalRead(pushJoystick));
  Serial.print("Angle of X is= ");
  Serial.println(AngleX);
  Serial.print("Angle of Y is= ");
  Serial.println(AngleY);
  Serial.println("");
  delay(200);
}
