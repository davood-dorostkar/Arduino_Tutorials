/*
SanatBazar
Arduino Turorial Series
Author: Davood Dorostkar
Website: www.sanatbazar.com

*/

#include "dcMotor.h"

dcMotor::dcMotor(uint8_t input1Pin, uint8_t input2Pin, uint8_t enablePin)
{
    pinMode(input1Pin, OUTPUT);
    pinMode(input2Pin, OUTPUT);
    pinMode(enablePin, OUTPUT);
    _input1Pin = input1Pin;
    _input2Pin = input2Pin;
    _enablePin = enablePin;
}

void dcMotor::forwardTurn(uint8_t speed)
{
    digitalWrite(_input1Pin, HIGH);
    digitalWrite(_input2Pin, LOW);
    analogWrite(_enablePin, speed);
}

void dcMotor::backwardTurn(uint8_t speed)
{
    digitalWrite(_input1Pin, LOW);
    digitalWrite(_input2Pin, HIGH);
    analogWrite(_enablePin, speed);
}

void dcMotor::forwardSweep(int intervals)
{
    for (int i = 0; i < 255; i++)
    {
        forwardTurn(i);
        delay(intervals);
    }
    for (int i = 255; i > 0; i--)
    {
        forwardTurn(i);
        delay(intervals);
    }
}

void dcMotor::backwardSweep(int intervals)
{
    for (int i = 0; i < 255; i++)
    {
        backwardTurn(i);
        delay(intervals);
    }
    for (int i = 255; i > 0; i--)
    {
        backwardTurn(i);
        delay(intervals);
    }
}