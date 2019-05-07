#include <Arduino.h>
/*
SanatBazar
Arduino Turorial Series
Author: Davood Dorostkar
Website: www.sanatbazar.com

*/

#define trigger 2
#define echo 3
#define velocity 331.4+temperature*0.606+humidity*0.0124
#include <dht.h>
dht DHT;
#define DHT22_PIN 7

void setup() {
  Serial.begin(9600);
  pinMode(trigger,OUTPUT);
  pinMode(echo,INPUT);
}

void loop() {
  int t = DHT.read(DHT22_PIN);
  float temperature=DHT.temperature;
  float humidity=DHT.humidity;
  digitalWrite(trigger,LOW);
  delayMicroseconds(2);
  digitalWrite(trigger,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger,LOW);
  float time=pulseIn(echo,HIGH);
  float distance=((time/2)*velocity)*0.0001; //conversion to cm
  if (distance>=2 && distance<=400){
    Serial.print("Distance= ");
    Serial.println(distance);
  }
  else {
    Serial.println("Out of range");
  }
  delay(1000);
}
