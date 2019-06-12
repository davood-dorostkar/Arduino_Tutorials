#include <Arduino.h>
#include <SD.h>
#include <SPI.h>
#define SS 10

void setup()
{
  Serial.begin(9600);
  SD.begin(SS);
}

void loop()
{
  Serial.println("Insert your data");
  while (!Serial.available())
  {
  }
  char input = char(Serial.read());
  Serial.println(input);
  File inputData = SD.open("data.txt", FILE_WRITE);
  if (inputData)
    inputData.println(String(input));
  else
    Serial.println("No Card inserted");
  delay(1000);
}