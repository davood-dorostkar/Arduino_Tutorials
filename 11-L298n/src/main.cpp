#include <Arduino.h>

#define enablePin 10
#define input1Pin 8
#define input2Pin 9

void setup()
{
  pinMode(enablePin, OUTPUT);
  pinMode(input1Pin, OUTPUT);
  pinMode(input2Pin, OUTPUT);
}

void loop()
{
    digitalWrite(enablePin,HIGH);
    digitalWrite(input1Pin,HIGH);
    digitalWrite(input2Pin,LOW);
}