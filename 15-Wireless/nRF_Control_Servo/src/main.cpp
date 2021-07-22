#include <Arduino.h>
/*
SanatBazar
Arduino Tutorial Series
Author: Davood Dorostkar
Website: www.sanatbazar.com

*/

#include <RF24.h>
#define LEDpin 3
#define potentiometer A0
RF24 wireless(7, 8); // (CE , CSN) pins
const byte LEDAddress[] = "00001";
const byte servoAddress[] = "00002";
int servoStatus;
int LEDStatus;

void readWireless()
{
    wireless.startListening();
    wireless.read(&LEDStatus, sizeof(LEDStatus));
}

void writeWireless()
{
    wireless.stopListening();
    servoStatus = map(analogRead(potentiometer), 0, 1023, 0, 180);
    if (servoStatus < 10)
        servoStatus = 0;
    else if (servoStatus > 170)
        servoStatus = 180;
    wireless.write(&servoStatus, sizeof(servoStatus));
}

void setup()
{
    Serial.begin(9600);
    wireless.begin();
    Serial.println("Initializing the wireless... ");
    wireless.setPALevel(RF24_PA_MIN);
    wireless.openReadingPipe(1, LEDAddress);
    wireless.openWritingPipe(servoAddress);
    Serial.println("The Amplification is set to: " + String(wireless.getPALevel()));
    Serial.println("wireless initialized!");
    pinMode(LEDpin, OUTPUT);
}

void loop()
{
    delay(50);
    writeWireless();
    delay(50);
    readWireless();
    analogWrite(LEDpin, LEDStatus);
    Serial.println(LEDStatus);
}