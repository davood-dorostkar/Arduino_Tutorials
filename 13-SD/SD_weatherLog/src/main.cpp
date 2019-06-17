#include <Arduino.h>
/*
SanatBazar
Arduino Tutorial Series
Author: Davood Dorostkar
Website: www.sanatbazar.com

*/

#include <SD.h>
#include <SPI.h>
#define SS 10
#include <dht.h>
dht DHT;
#define DHT11_PIN 7
File weather;
#define minute 60000UL

void setup()
{
  Serial.begin(9600);
  SD.begin(SS);
}

void loop()
{
  if (SD.exists("weather.txt"))
  {
    SD.remove("weather.txt");
  }
  DHT.read11(DHT11_PIN);
  weather = SD.open("weather.txt", FILE_WRITE);
  weather.println(String(DHT.temperature) + ";" + String(DHT.humidity));
  weather.close();
  Serial.println(String(DHT.temperature) + ";" + String(DHT.humidity));
  delay(1 * minute);
}