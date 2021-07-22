#include <Arduino.h>
/*
SanatBazar
Arduino Turorial Series
Author: Davood Dorostkar
Website: www.sanatbazar.com

*/

#define trigger 2
#define echo 3

void setup()
{
  Serial.begin(9600);
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
}

void loop()
{
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  float time = pulseIn(echo, HIGH);
  float velocity = 334;
  float distance = ((time / 2) * velocity) * 0.0001; // conversion to cm
  if (distance >= 2 && distance <= 400)
  {
    Serial.print("Distance= ");
    Serial.println(distance);
  }
  else
  {
    Serial.println("Out of range");
  }
  delay(1000);
}
