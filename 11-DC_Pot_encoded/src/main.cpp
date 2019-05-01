#include <Arduino.h>

#define potentiometerPin A0
#define enablePin 10
#define input1Pin 8
#define input2Pin 9
#define encoderPinA 2
#define encoderPinB 3
volatile int encoderPosition = 0;
float encoderAngle = 0.0;

void forwardTurn(int speed)
{
  digitalWrite(input1Pin, HIGH);
  digitalWrite(input2Pin, LOW);
  analogWrite(enablePin, speed);
}

void backwardTurn(int speed)
{
  digitalWrite(input1Pin, LOW);
  digitalWrite(input2Pin, HIGH);
  analogWrite(enablePin, speed);
}

void motorDrive(int speed)
{
  if (speed < 550 && speed > 470)
    speed = 0;
  else if (speed <= 470)
  {
    speed = map(speed, 0, 512, 255, 0);
    forwardTurn(speed);
  }
  else
  {
    speed = map((speed - 512), 0, 512, 0, 255);
    backwardTurn(speed);
  }
}

void doEncoderA()
{
  if (digitalRead(encoderPinA) == HIGH)
  {

    if (digitalRead(encoderPinB) == LOW)
      encoderPosition++; // CW
    else
      encoderPosition--; // CCW
  }
  else
  {
    if (digitalRead(encoderPinB) == HIGH)
      encoderPosition++; // CW
    else
      encoderPosition--; // CCW
  }
}
void doEncoderB()
{
  if (digitalRead(encoderPinB) == HIGH)
  {
    if (digitalRead(encoderPinA) == HIGH)
      encoderPosition++; // CW
    else
      encoderPosition--; // CCW
  }
  else
  {
    if (digitalRead(encoderPinA) == LOW)
      encoderPosition++; // CW
    else
      encoderPosition--; // CCW
  }
}

void setup()
{
  Serial.begin(9600);
  pinMode(enablePin, OUTPUT);
  pinMode(input1Pin, OUTPUT);
  pinMode(input2Pin, OUTPUT);
  pinMode(encoderPinA, INPUT);
  pinMode(encoderPinB, INPUT);
  attachInterrupt(digitalPinToInterrupt(2), doEncoderA, CHANGE);
  attachInterrupt(digitalPinToInterrupt(3), doEncoderB, CHANGE);
}

void loop()
{
  int speed = analogRead(potentiometerPin);
  motorDrive(speed);
  // There is 4 pulses per step
  // Encoder has 334 steps per revolution
  // Gearbox ratio is 1:25
  encoderAngle = (encoderPosition / 4) * (360 / 334) / 25;
  Serial.print("Angle= ");
  Serial.print(encoderPosition);
  Serial.println(" deg");
}