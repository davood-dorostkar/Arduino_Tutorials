#include <Arduino.h>

#include <nRF24L01.h>
#include <RF24.h>
RF24 wifiSender(7, 8);
const byte address[] = "00001";
String amplifications[] = {"RF24_PA_MIN", "RF24_PA_LOW", "RF24_PA_HIGH", "RF24_PA_MAX"};
int ampState = 0;

void setup()
{
    Serial.begin(9600);
    wifiSender.begin();
    Serial.println("Initializing the wifi... ");
    Serial.println(amplifications[ampState]);
    wifiSender.setPALevel(amplifications[ampState]);
    Serial.println("The Amplification is set to: " + String(amplifications[ampState]));
    wifiSender.openWritingPipe(address);
    wifiSender.stopListening();
    Serial.println("wifi initialized!");
}

void loop()
{
    while (!Serial.available())
    {
    }
    String message = Serial.readStringUntil("\n");
    // const char message[] = String(message);
    wifiSender.write(&message, sizeof(message));
    delay(2000);
}
