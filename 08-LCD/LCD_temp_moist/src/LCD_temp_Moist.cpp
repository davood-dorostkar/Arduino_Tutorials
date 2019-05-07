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

#include <dht.h>
dht DHT;
#define DHT11_PIN 8

#include <LiquidCrystal.h>
#define RS 2
#define E  3
#define D4 4
#define D5 5
#define D6 6
#define D7 7
LiquidCrystal lcd(RS,E,D4,D5,D6,D7);

void setup(){
  lcd.begin(16, 2);
}
void loop()
{
  int t = DHT.read11(DHT11_PIN);
  lcd.setCursor(0,0);
  lcd.print("Temp = ");
  lcd.print((int)DHT.temperature);
  lcd.print(" C");
  lcd.setCursor(0,1);
  lcd.print("Humidity = ");
  lcd.print((int)DHT.humidity);
  lcd.print(" %");
  delay(2000);
}
