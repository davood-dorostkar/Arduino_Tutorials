#include <Arduino.h>

#include <SoftwareSerial.h>

const byte rxPin = 2; // Wire this to Tx Pin of ESP8266
const byte txPin = 3; // Wire this to Rx Pin of ESP8266

// We'll use a software serial interface to connect to ESP8266
SoftwareSerial ESP8266 (rxPin, txPin);

void setup() {
  Serial.begin(9600);

  // You may need to uncomment this block for the first run:

//  ESP8266.begin(115200); // Change this to the factory baudrate used by ESP8266
//  delay(1000);
//  Serial.println("Setting BAUDRATE to 9600");
////  //  ESP8266.println("AT+CIOBAUD=9600"); // this was the old instruct
//  ESP8266.println("AT+UART_DEF=9600,8,1,0,0"); // this is the new instruct. this changes the baud rate to 9600 permanently. if you want to change it temporary: DEF=>CUR

  ESP8266.begin(9600);

}
bool okReceived = false;

void loop() {

  if (Serial.available() > 0)
  {
    String command = Serial.readStringUntil('\n');
    Serial.println("Command Sent: " + command);
    Serial.println();
    ESP8266.println(command);
  }

  int responseCounter = 0;
  if (ESP8266.available() > 0)
  {
    while (ESP8266.available() > 0)
    {
      if (responseCounter == 0)
      {
        Serial.println("Response Received:");
      }

      String response = ESP8266.readStringUntil('\n');
      Serial.println(response);
      responseCounter++;
    }
    Serial.println();
    Serial.println("============");
    Serial.println();
  }


}