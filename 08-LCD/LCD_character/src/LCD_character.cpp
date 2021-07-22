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
D7 --> 7              K   --> GND

*/

#include <LiquidCrystal.h>
#define RS 2
#define E  3
#define D4 4
#define D5 5
#define D6 6
#define D7 7
LiquidCrystal lcd(RS,E,D4,D5,D6,D7);

// Definitions of characters:

byte smiley[] = {
  B00000,
  B00000,
  B01010,
  B00000,
  B10001,
  B01110,
  B00000,
  B00000
};
byte diamond[] = {
  0,
  4,
  10,
  17,
  10,
  4,
  0,
  0
};
byte arrow[] = {
  B00100,
  B01110,
  B11111,
  B00100,
  B00100,
  B00100,
  B00100,
  B00100
};
byte newShape[] = {
  B11111,
  B10001,
  B10001,
  B00100,
  B00100,
  B10001,
  B10001,
  B11111
};
byte sandglass[] = {
  0x1F,
  0x0E,
  0x04,
  0x04,
  0x04,
  0x04,
  0x0E,
  0x1F
};

void setup() {
  lcd.createChar(0, smiley);
  lcd.createChar(1, arrow);
  lcd.createChar(2, newShape);
  lcd.createChar(3, sandglass);
  lcd.createChar(4, diamond);
  lcd.begin(16, 2);
}

void loop() {
  int numberOfCharacters=0;
  lcd.clear();
  lcd.setCursor(0,0);
  for (int i=0; i<32; i++){
    if (numberOfCharacters==16) {
      lcd.setCursor(0,1);
    }
    lcd.write(byte(i%5));
    numberOfCharacters++;
    delay(1000);
  }
}
