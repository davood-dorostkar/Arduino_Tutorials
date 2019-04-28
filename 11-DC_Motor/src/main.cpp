#include <Arduino.h>
#define potentiometerPin A0
#define enablePin 10
#define input1Pin 8
#define input2Pin 9

// void forwardTurn(uint8_t speed)
// {
//   digitalWrite(input1Pin, HIGH);
//   digitalWrite(input2Pin, LOW);
//   analogWrite(enablePin, speed);
// }

// void backwardTurn(uint8_t speed)
// {
//   digitalWrite(input1Pin, LOW);
//   digitalWrite(input2Pin, HIGH);
//   analogWrite(enablePin, speed);
// }

// int motorDrive(uint8_t speed)
// {
//   if (speed < 550 && speed > 470)
//     speed = 0;
//   else if (speed <= 470)
//   {
//     speed = map(speed, 0, 512, 255, 0);
//     forwardTurn(speed);
//   }
//   else
//   {
//     speed = map((speed - 512), 0, 512, 0, 255);
//     backwardTurn(speed);
//   }
// }

void setup()
{
  pinMode(enablePin, OUTPUT);
  pinMode(input1Pin, OUTPUT);
  pinMode(input2Pin, OUTPUT);
}

void loop()
{
  // uint8_t speed = analogRead(potentiometerPin);
  int speed=50;
  // motorDrive(speed);
  // forwardTurn(map(speed,0,1024,0,255));

  digitalWrite(input1Pin, HIGH);
  digitalWrite(input2Pin, LOW);
  analogWrite(enablePin, speed);
}