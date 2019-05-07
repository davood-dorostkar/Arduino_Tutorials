#include <Arduino.h>
/*
SanatBazar
Arduino Turorial Series
Author: Davood Dorostkar
Website: www.sanatbazar.com

*/

#define servo 3
void setup(){
  pinMode(servo,OUTPUT);
}
void loop() {
  for (int i = 0; i < 255; i++) {
    analogWrite(servo,i);
  }
  delay(2000);
  for (int i = 255; i < ; i--) {
    analogWrite(servo,i);
  }
  delay(2000);
}
