#include <Arduino.h>
/*
SanatBazar
Arduino Tutorial Series
Author: Davood Dorostkar
Website: www.sanatbazar.com

*/

#include <SoftwareSerial.h>
#define RX 2
#define TX 3
SoftwareSerial esp8266(RX, TX);

void setup()
{
  Serial.begin(115200);
  esp8266.begin(115200);
}

void loop()
{
  Serial.println("Please enter your AT command: ");
  while (!Serial.available())
  {
  }
  if (Serial.available() > 0)
  {
    String command = Serial.readStringUntil('\n');
    Serial.println("Entered Command: " + command);
    esp8266.println(command);
  }
  int counter = 0;
  if (esp8266.available() > 0)
  {
    while (esp8266.available() > 0)
    {
      if (counter == 0)
      {
        Serial.println("Recieved Response: ");
      }
      String response = esp8266.readStringUntil('\n');
      Serial.println(response);
      Serial.println();
      counter++;
    }

    Serial.println("===========================");
    Serial.println();
  }
}
