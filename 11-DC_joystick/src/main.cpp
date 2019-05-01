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

void goAhead() {
  digitalWrite(enableMotor1,HIGH);
  digitalWrite(input1Motor1,HIGH);
  digitalWrite(input2Motor1,LOW);

  digitalWrite(enableMotor2,HIGH);
  digitalWrite(input1Motor2,HIGH);
  digitalWrite(input2Motor2,LOW);
}



  }
  driveAmplitude= map(driveAmplitude,0,1024,0,255);
  turnAmplitude= map(turnAmplitude,0,1024,0,255);

}
void loop()
{
  uint16_t driveAmplitude = analogRead(joystickX);
  uint16_t turnAmplitude = analogRead(joystickY);

}