#include <Arduino.h>
/*
SanatBazar
Arduino Turorial Series
Author: Davood Dorostkar
Website: www.sanatbazar.com

*/

const int buzzerPin=9;
float maxFrequency=2500; // in Hertz
float minFrequency=200;
float duration=3000; // in miliseconds
float timeStep=1; //in miliseconds
int rest=2000; // in miliseconds

#define frequencydelta (maxFrequency-minFrequency)
#define frequencyStep timeStep*frequencydelta/(duration/2)

void setup(){

}

void loop(){
  for(float i=minFrequency;i<maxFrequency;i+=frequencyStep)
  {
    tone(buzzerPin,i);
    delay(timeStep);
  }
  for(float i=maxFrequency;i>minFrequency;i-=frequencyStep)
  {
    tone(buzzerPin,i);
    delay(timeStep);
  }
  noTone(buzzerPin);
  delay(rest);
}
