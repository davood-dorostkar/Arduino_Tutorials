#include <Arduino.h>
/*
SanatBazar
Arduino Tutorial Series
Author: Davood Dorostkar
Website: www.sanatbazar.com

*/

#include <RF24.h>
RF24 wifiSender(7, 8); // (CE , CSN) pins
const byte address[] = "00001";

void setup()
{
    Serial.begin(9600);
    wifiSender.begin();
    Serial.println("Initializing the wifi... ");
    wifiSender.setPALevel(RF24_PA_MIN);
    Serial.println("The Amplification is set to: " + String(wifiSender.getPALevel()));
    wifiSender.openWritingPipe(address);
    wifiSender.stopListening();
    Serial.println("wifi initialized!");
}

void loop()
{
    char message[] = "I am sending something!";
    wifiSender.write(&message, sizeof(message));
    delay(2000);
}
