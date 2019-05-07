#include <Arduino.h>
/*
SanatBazar
Arduino Turorial Series
Author: Davood Dorostkar
Website: www.sanatbazar.com

*/

byte soil = 13;
void setup() {
  pinMode(soil, INPUT);
  Serial.begin(9600);
}
void loop() {
  if (digitalRead(soil) == LOW) {
    Serial.println("Your plant is OK");
  }
  else {
    Serial.println("Your plant needs water");
  }
  delay(1000);
}
