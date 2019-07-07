#include <Arduino.h>
/*
SanatBazar
Arduino Tutorial Series
Author: Davood Dorostkar
Website: www.sanatbazar.com

*/

#include <SoftwareSerial.h>
SoftwareSerial bluetooth(2, 3); // RX | TX
 
void setup()
{
  Serial.begin(38400);
  bluetooth.begin(38400);
  Serial.println("Enter AT commands!");
}
 
void loop()
{
  if (bluetooth.available())
    Serial.write(bluetooth.read());
  if (Serial.available())
    bluetooth.write(Serial.read());
}