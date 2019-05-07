#include <Arduino.h>
/*
SanatBazar
Arduino Turorial Series
Author: Davood Dorostkar
Website: www.sanatbazar.com


LCD Connections:
RS --> 2              RW  --> GND
E  --> 3              VSS --> GND
D4 --> 4              VDD --> +5V
D5 --> 5              V0  --> Potentiometer #1
D6 --> 6              A   --> Potentiometer #2
D6 --> 7              K   --> GND

*/

#include <LiquidCrystal.h>
#define RS 2
#define E  3
#define D4 4
#define D5 5
#define D6 6
#define D7 7
LiquidCrystal lcd(RS,E,D4,D5,D6,D7);

void setup() {
  lcd.begin(16, 2);
}

void loop() {
  lcd.clear();
  lcd.print("Hello world!");
  int minute=millis()/1000/60;
  lcd.setCursor(0, 1);
  if (minute<10) lcd.print("0");
  lcd.print(minute);
  lcd.setCursor(2, 1);
  lcd.print(":");
  int second=(millis()/1000)%60;
  lcd.setCursor(3, 1);
  if (second<10) lcd.print("0");
  lcd.print(second);
  delay(500);
}
