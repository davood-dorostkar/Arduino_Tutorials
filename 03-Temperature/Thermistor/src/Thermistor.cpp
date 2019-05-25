#include <Arduino.h>
/*
SanatBazar
Arduino Turorial Series
Author: Davood Dorostkar
Website: www.sanatbazar.com

*/

#include <math.h>
float A = 0.001125308852122;
float B = 0.000234711863267;
float C = 0.000000085663516;
void setup() {
  Serial.begin(9600);
}

void loop() {
  float volt = analogRead(A0);
  volt = map(volt, 0, 1023, 0, 5);
  float thermistorR = 10000 * (5.0 / volt - 1); //Voltage to resistance conversion
  float ln_R = log(thermistorR);
  float temp = 1 / (A + B * ln_R + C * pow(ln_R, 3) ); //Steinhart–Hart equation
  temp-=273.15;
  Serial.print("Temperature= ");
  Serial.println(temp);
  delay(1000);
}
