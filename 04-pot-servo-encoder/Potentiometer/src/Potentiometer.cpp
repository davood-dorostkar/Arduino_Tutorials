#include <Arduino.h>
/*
SanatBazar
Arduino Turorial Series
Author: Davood Dorostkar
Website: www.sanatbazar.com

*/

void setup() {
  Serial.begin(9600);
}

void loop() {
  int Potentiometer=analogRead(A0);
  Potentiometer=map(Potentiometer,0,1023,0,100);
  Serial.print("Rotation percentage ");
  Serial.println(Potentiometer);
}
