#include <Arduino.h>
/*
SanatBazar
Arduino Turorial Series
Author: Davood Dorostkar
Website: www.sanatbazar.com

*/

#include <Servo.h>
Servo servo;
void setup(){
  servo.attach(3);
}
void loop() {
  for (int i = 0; i < 180; i++) {
    servo.write(i);
  }
  delay(2000);
  for (int i = 180; i < 0; i--) {
    servo.write(i);
  }
  delay(2000);
}
