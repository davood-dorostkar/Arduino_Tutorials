#include <Arduino.h>
/*
SanatBazar
Arduino Turorial Series
Author: Davood Dorostkar
Website: www.sanatbazar.com

*/

#define encoderPinA 2
#define encoderPinB 3
volatile  int encoderPosition = 0 ;
float angle = 0.0 ;

void setup() {
  pinMode (encoderPinA , INPUT ) ;
  pinMode (encoderPinB , INPUT ) ;
  attachInterrupt( digitalPinToInterrupt(2) , doEncoderA , CHANGE) ;
  attachInterrupt ( digitalPinToInterrupt(3) , doEncoderB , CHANGE) ;
  Serial.begin (9600) ;
}

void loop() {
  // Encoder has 100 steps per revolution.
  // 4 pulses form a step.
  angle = (encoderPosition / 4) * (360 / 100);
  Serial.print("Angle= ");
  Serial.print(angle) ;
  Serial.println(" deg");
}

void doEncoderA () {
  if (digitalRead( encoderPinA ) == HIGH) {

    if (digitalRead( encoderPinB ) == LOW) {
      encoderPosition++ ; // CW
    }
    else {
      encoderPosition-- ; // CCW
    }
  }
  else {
    if (digitalRead( encoderPinB ) == HIGH) {
      encoderPosition++ ; // CW
    }
    else {
      encoderPosition-- ; // CCW
    }
  }
}
void doEncoderB ( ) {
  if (digitalRead( encoderPinB ) == HIGH) {
    if (digitalRead( encoderPinA ) == HIGH) {
      encoderPosition++ ; // CW
    }
    else {
      encoderPosition-- ; // CCW
    }
  }
  else {
    if (digitalRead( encoderPinA ) == LOW) {
      encoderPosition++ ; // CW
    }
    else {
      encoderPosition-- ; // CCW
    }
  }
}
