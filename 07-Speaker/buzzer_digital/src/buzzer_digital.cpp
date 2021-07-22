#include <Arduino.h>
/*
SanatBazar
Arduino Turorial Series
Author: Davood Dorostkar
Website: www.sanatbazar.com

*/

const int buzzerPin=9;
unsigned int frequency=500; // in Hertz
int duration=1000; //in miliseconds
int rest=2000; //in miliseconds

void setup(){
  pinMode(buzzerPin,OUTPUT);
}

void loop() {
  buzzer(buzzerPin,frequency,duration);
  delay(rest);
}

void buzzer(int buzzerPin,int frequency,int duration){
  unsigned long cycles=frequency*duration;
  unsigned int period=1000000/frequency; //in microseconds
  for(int i=0;i<cycles;i++){
    digitalWrite(buzzerPin,HIGH);
    delayMicroseconds(period/2);
    digitalWrite(buzzerPin,LOW);
    delayMicroseconds(period/2);
  }
}
