#include <Arduino.h>
/*
SanatBazar
Arduino Turorial Series
Author: Davood Dorostkar
Website: www.sanatbazar.com

*/

#define buzzerPin 9

#define e4 329.63 // define note pitches
#define d4s 311.13
#define b3 246.94
#define d4 293.66
#define c4 261.63
#define a3 220
#define d3 146.83
#define f3 174.61
#define a3s 233.08
#define g3 196
#define f4 349.23
#define e3 164.81

float tempo = 150;
#define beat 60000 / tempo

// describing music notes

float notes[] = {e4, d4s, e4, d4s, e4, b3, d4, c4, a3, d3, f3, a3, b3, f3, a3s, b3, c4,
                 e4, d4s, e4, d4s, e4, b3, d4, c4, a3, d3, f3, a3, b3, f3, c4, b3, a3,
                 b3, c4, d4, e4, g3, f4, e4, d4, e3, e4, d4, c4, d3, d4, c4, b3, e4,
                 d4s, e4, d4s, e4, b3, d4, c4, a3, d3, f3, a3, b3, f3, a3, b3, c4, e4,
                 d4s, e4, d4s, e4, b3, d4, c4, a3, d3, f3, a3, b3, f3, c4, b3, a3};

float durations[] = {3, 3, 3, 3, 3, 3, 3, 3, 1, 3, 3, 3, 1, 3, 3, 3, 1, 3, 3, 3, 3, 3, 3,
                     3, 3, 1, 3, 3, 3, 1, 3, 3, 3, 1, 3, 3, 3, 1, 3, 3, 3, 1, 3, 3, 3, 1,
                     3, 3, 3, 1, 3, 3, 3, 3, 3, 3, 3, 3, 1, 3, 3, 3, 1, 3, 3, 3, 1, 3, 3,
                     3, 3, 3, 3, 3, 3, 1, 3, 3, 3, 1, 3, 3, 3, 1};

int rests[] = {350, 350, 350, 350, 350, 400, 400, 400, 1000, 350, 400, 400, 1000, 400,
               400, 400, 1300, 400, 400, 400, 400, 400, 400, 400, 400, 1000, 400, 400,
               400, 1000, 400, 400, 400, 1000, 400, 400, 400, 1000, 400, 400, 400, 1000,
               400, 400, 400, 1000, 400, 400, 400, 1400, 400, 350, 350, 350, 350, 400,
               400, 400, 1000, 350, 400, 400, 1000, 400, 400, 400, 1300, 400, 400, 400,
               400, 400, 400, 400, 400, 1000, 400, 400, 400, 1000, 400, 400, 400, 1000};

void setup()
{
  pinMode(buzzerPin, OUTPUT);
}

void loop()
{
  for (int i = 0; i < (sizeof(notes) / sizeof(double)); i++)
  {
    tone(buzzerPin, notes[i], beat / durations[i]);
    delay(rests[i] * (100 / tempo));
  }
  delay(5000);
}