#include <Arduino.h>

#define enablePin 10
#define input1Pin 9
#define input2Pin 8

void forwardTurn(uint8_t speed)
{
  digitalWrite(input1Pin, HIGH);
  digitalWrite(input2Pin, LOW);
  analogWrite(enablePin, speed);
}

void backwardTurn(uint8_t speed)
{
  digitalWrite(input1Pin, LOW);
  digitalWrite(input2Pin, HIGH);
  analogWrite(enablePin, speed);
}

void setup()
{
  pinMode(enablePin, OUTPUT);
  pinMode(input1Pin, OUTPUT);
  pinMode(input2Pin, OUTPUT);
}

void loop()
{
  for (int i = 0; i < 255; i++)
  {
    forwardTurn(i);
    delay(30);
  }
  for (int i = 255; i > 0; i--)
  {
    forwardTurn(i);
    delay(30);
  }
    for (int i = 0; i < 255; i++)
  {
    backwardTurn(i);
    delay(30);
  }
  for (int i = 255; i > 0; i--)
  {
    backwardTurn(i);
    delay(30);
  }
  delay(2000);
}