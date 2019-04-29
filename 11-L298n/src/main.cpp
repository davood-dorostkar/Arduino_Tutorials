#include <Arduino.h>

#define enablePin 10
#define input1Pin 8
#define input2Pin 9

void setup()
{
  pinMode(enablePin, OUTPUT);
  pinMode(input1Pin, OUTPUT);
  pinMode(input2Pin, OUTPUT);
Serial.begin(9600);  
}

void loop()
{
  for (int i = 0; i < 255; i++)
  {
    analogWrite(enablePin,i);
    digitalWrite(input1Pin,HIGH);
    digitalWrite(input2Pin,LOW);
    Serial.println(i);
    delay(30);
  }
  for (int i = 255; i > 0; i--)
  {
    analogWrite(enablePin,i);
    digitalWrite(input1Pin,HIGH);
    digitalWrite(input2Pin,LOW);
    Serial.println(i);
    delay(30);
  }
    delay(2000);
}