#include <Arduino.h>
/*
SanatBazar
Arduino Turorial Series
Author: Davood Dorostkar
Website: www.sanatbazar.com

*/

const int buzzerPin=9;
int duration=1000; //in miliseconds
int rest=2000; //in miliseconds

void setup(){
  pinMode(buzzerPin,OUTPUT);
}

void loop() {
  digitalWrite(buzzerPin,HIGH);
  delay(duration);
  digitalWrite(buzzerPin,LOW);
  delay(rest);
}
