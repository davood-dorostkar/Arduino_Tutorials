#include <Arduino.h>
#include <Keypad.h>
#define rowNumbers 4
#define columnNumbers 4
byte rowPins[rowNumbers] = {2, 3, 4, 5};
byte colPins[columnNumbers] = {6, 7, 8, 9};

char keys[rowNumbers][columnNumbers] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}};
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, rowNumbers, columnNumbers);

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  char pressedKey = keypad.getKey();
  if (pressedKey)
    Serial.println(pressedKey);
}