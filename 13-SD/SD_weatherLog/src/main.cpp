#include <Arduino.h>
/*
SanatBazar
Arduino Turorial Series
Author: Davood Dorostkar
Website: www.sanatbazar.com

*/

#include <SD.h>
#include <SPI.h>
#define SS 10
#include <dht.h>
dht DHT;
#define DHT11_PIN 7
File weatherLog;
void timer(int seconds)
{
  int elapsedSeconds = 0;
  unsigned long previousTime = 0;
  unsigned long currentTime = millis();
  while (elapsedSeconds < seconds)
  {
    // if ((unsigned long)(currentTime - previousTime) >= 1000)
    //   elapsedSeconds++;
    elapsedSeconds = currentTime / 1000;
    Serial.println(elapsedSeconds);
    Serial.println(currentTime);
    Serial.println(previousTime);
  }
  Serial.println("returned");
  return;
}

void setup()
{
  Serial.begin(9600);
  SD.begin(SS);
}

void loop()
{
  DHT.read11(DHT11_PIN);
  weatherLog = SD.open("weatherLog.txt", FILE_WRITE);
  weatherLog.println(String(DHT.temperature) + "," + String(DHT.humidity));
  weatherLog.close();
  Serial.println(String(DHT.temperature) + "," + String(DHT.humidity));
  // timer(2);
  delay(3000);
  weatherLog = SD.open("weatherLog.txt");
  Serial.println(weatherLog.read());
  weatherLog.close();
}