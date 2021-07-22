#include <Arduino.h>
/*
SanatBazar
Arduino Tutorial Series
Author: Davood Dorostkar
Website: www.sanatbazar.com

*/

#include <RF24.h>
RF24 wirelessSender(7, 8); // (CE , CSN) pins
const byte address[] = "00001";

void setup()
{
    Serial.begin(9600);
    wirelessSender.begin();
    Serial.println("Initializing the wireless... ");
    wirelessSender.setPALevel(RF24_PA_MIN);
    Serial.println("The Amplification is set to: " + String(wirelessSender.getPALevel()));
    wirelessSender.openWritingPipe(address);
    wirelessSender.stopListening();
    Serial.println("wireless initialized!");
}

void loop()
{
    char message[] = "I am sending something!";
    wirelessSender.write(&message, sizeof(message));
    delay(2000);
}
