#include <Arduino.h>
/*
SanatBazar
Arduino Tutorial Series
Author: Davood Dorostkar
Website: www.sanatbazar.com

*/

#include <RF24.h>
#include <Servo.h>
#define servoPin 3
#define potentiometer A0
RF24 wireless(7, 8); // (CE , CSN) pins
Servo servoMotor;
const byte LEDAddress[] = "00001";
const byte servoAddress[] = "00002";
int servoStatus;
int LEDStatus;

void readWireless()
{
  wireless.startListening();
  wireless.read(&servoStatus, sizeof(servoStatus));
}

void writeWireless()
{
  wireless.stopListening();
  LEDStatus = map(analogRead(potentiometer), 0, 1023, 0, 255);
  if (LEDStatus<10)
    LEDStatus=0;
  wireless.write(&LEDStatus, sizeof(LEDStatus));
}

void setup()
{
  Serial.begin(9600);
  wireless.begin();
  Serial.println("Initializing the wireless... ");
  wireless.setPALevel(RF24_PA_MIN);
  wireless.openReadingPipe(1, servoAddress);
  wireless.openWritingPipe(LEDAddress);
  Serial.println("The Amplification is set to: " + String(wireless.getPALevel()));
  Serial.println("wireless initialized!");
  servoMotor.attach(servoPin);
}

void loop()
{
  delay(50);
  writeWireless();
  delay(50);
  readWireless();
  servoMotor.write(servoStatus);
  Serial.println(servoStatus);
}