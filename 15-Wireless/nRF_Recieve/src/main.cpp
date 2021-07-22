#include <Arduino.h>
/*
SanatBazar
Arduino Tutorial Series
Author: Davood Dorostkar
Website: www.sanatbazar.com

*/

#include <RF24.h>
RF24 wirelessReciever(7, 8); // (CE , CSN) pins
const byte address[] = "00001";

void setup()
{
  Serial.begin(9600);
  wirelessReciever.begin();
  Serial.println("Initializing the wireless... ");
  wirelessReciever.setPALevel(RF24_PA_MIN);
  Serial.println("The Amplification is set to: " + String(wirelessReciever.getPALevel()));
  wirelessReciever.openReadingPipe(0, address);
  wirelessReciever.startListening();
  Serial.println("wireless initialized!");
}

void loop()
{
  if (wirelessReciever.available())
  {
    char message[32] = "";
    wirelessReciever.read(&message, sizeof(message));
    Serial.println(message);
  }
}