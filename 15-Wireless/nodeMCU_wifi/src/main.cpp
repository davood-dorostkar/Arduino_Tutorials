#include <Arduino.h>
#include <ESP8266WiFi.h>
/*
SanatBazar
Arduino Tutorial Series
Author: Davood Dorostkar
Website: www.sanatbazar.com

*/

void setup()
{
  delay(1000);
  Serial.begin(115200);
  WiFi.begin("SanatBazzar", "********");
  Serial.print("Connecting ");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(1000);
  }
  Serial.println();
  Serial.println("Connected Successfully!");
  Serial.print("Module's IP: ");
  Serial.println(WiFi.localIP());
}

void loop()
{
}