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
  int temp = analogRead(A0);
  Serial.print("Temperature= ");
  Serial.print(temp);
  Serial.println(" C");
  delay(1000);
}
