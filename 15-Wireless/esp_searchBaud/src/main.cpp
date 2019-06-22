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
const long baud[10] = {300, 1200, 2400, 4800, 9600, 19200, 38400, 57600, 74880, 115200};

void setup()
{
  Serial.begin(9600);
  for (int i = 0; i < 10; i++)
  {
    long newbaud = baud[i];
    Serial.println("checking new baud: " + (String)newbaud);
    // Serial.println(newbaud);
    esp8266.begin(newbaud);
    delay(1000);
    esp8266.println("AT");
    if (esp8266.available())
    {
      while (esp8266.available())
      {
        String answer = esp8266.readString();
        if (answer == "OK")
        {
          Serial.println("found the right baud: " + newbaud);
        }
        else
          Serial.println("The answer was: " + answer);
      }
    }
    delay(1000);
    Serial.println();
  }
}

void loop()
{
}