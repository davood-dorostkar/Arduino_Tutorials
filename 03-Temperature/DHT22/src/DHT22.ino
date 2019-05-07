/*
SanatBazar
Arduino Turorial Series
Author: Davood Dorostkar
Website: www.sanatbazar.com

*/

#include <dht.h>
dht DHT;
#define DHT22_PIN 7

void setup(){
  Serial.begin(9600);
}

void loop()
{
  int t = DHT.read(DHT22_PIN);
  Serial.print("Temperature = ");
  Serial.print(DHT.temperature);
  Serial.print(" C");
  Serial.print(" ---- ");
  Serial.print("Humidity = ");
  Serial.print(DHT.humidity);
  Serial.println(" %");
  delay(2000);
}
