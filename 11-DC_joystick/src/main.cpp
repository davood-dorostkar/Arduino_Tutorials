#include <Arduino.h>

#define enableMotor1 5
#define input1Motor1 6
#define input2Motor1 7
#define input1Motor2 8
#define input2Motor2 9
#define enableMotor2 10
#define joystickX A0
#define joystickY A1

void setup()
{
  pinMode(enableMotor1, OUTPUT);
  pinMode(enableMotor2, OUTPUT);
  pinMode(input1Motor1, OUTPUT);
  pinMode(input1Motor2, OUTPUT);
  pinMode(input2Motor1, OUTPUT);
  pinMode(input2Motor2, OUTPUT);
  pinMode(joystickX, INPUT);
  pinMode(joystickY, INPUT);
}

void motor1ForwardDrive(int speed)
{
  analogWrite(enableMotor1, speed);
  digitalWrite(input1Motor1, HIGH);
  digitalWrite(input2Motor1, LOW);
}
void motor2ForwardDrive(int speed)
{
  analogWrite(enableMotor2, speed);
  digitalWrite(input1Motor2, HIGH);
  digitalWrite(input2Motor2, LOW);
}
void motor1BackwardDrive(int speed)
{
  analogWrite(enableMotor1, speed);
  digitalWrite(input1Motor1, LOW);
  digitalWrite(input2Motor1, HIGH);
}
void motor2BackwardDrive(int speed)
{
  analogWrite(enableMotor2, speed);
  digitalWrite(input1Motor2, LOW);
  digitalWrite(input2Motor2, HIGH);
}
void motor1Brake()
{
  digitalWrite(enableMotor1, HIGH);
  digitalWrite(input1Motor1, HIGH);
  digitalWrite(input2Motor1, HIGH);
}
void motor2Brake()
{
  digitalWrite(enableMotor2, HIGH);
  digitalWrite(input1Motor2, HIGH);
  digitalWrite(input2Motor2, HIGH);
}
void motionPlan(int speedMotor1, int speedMotor2)
{
  if (speedMotor1 > 550)
  {
    speedMotor1 = map(speedMotor1, 550, 1024, 0, 255);
    motor1ForwardDrive(speedMotor1);
  }
  else if (speedMotor1 < 460)
  {
    speedMotor1 = map(speedMotor1, 460, 0, 0, 255);
    motor1BackwardDrive(speedMotor1);
  }
  // else
  //   motor1Brake();
  if (speedMotor2 > 550)
  {
    speedMotor2 = map(speedMotor2, 550, 1024, 0, 255);
   motor2ForwardDrive(speedMotor2);
  }
  else if (speedMotor2 < 460)
  {
    speedMotor2 = map(speedMotor2, 460, 0, 0, 255);
    motor2BackwardDrive(speedMotor2);
  }
  // else
  //   motor2Brake();
}
void loop()
{
  int speedMotor1 = analogRead(joystickX);
  int speedMotor2 = analogRead(joystickY);
  motionPlan(speedMotor1, speedMotor2);
}