/*
SanatBazar
Arduino Turorial Series
Author: Davood Dorostkar
Website: www.sanatbazar.com

*/

#ifndef dcMotor_h
#define dcMotor_h

#if ARDUINO >= 100
    #include "Arduino.h"
#else
    #include "WProgram.h"
    #include "pins_arduino.h"
    #include "WConstants"
#endif

class dcMotor
{
private:
    uint8_t _input1Pin;
    uint8_t _input2Pin;
    uint8_t _enablePin;

public:
    dcMotor(uint8_t input1Pin, uint8_t input2Pin, uint8_t enablePin);
    void forwardTurn(uint8_t speed);
    void backwardTurn(uint8_t speed);
    void forwardSweep(int intervals);
    void backwardSweep(int intervals);
};

#endif