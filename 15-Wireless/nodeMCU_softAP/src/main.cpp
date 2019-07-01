#include <Arduino.h>
/*
SanatBazar
Arduino Tutorial Series
Author: Davood Dorostkar
Website: www.sanatbazar.com

*/

#include <ESP8266WiFi.h>
String networkName = "NodeMCU";
String networkPassword = "12345678";

void setup()
{
  Serial.begin(115200);
  Serial.println();
  Serial.print("Configuring WiFi access point...");
  if (WiFi.softAP(networkName, networkPassword) == true)
  {
    IPAddress softAP = WiFi.softAPIP();
    Serial.println("Soft AP created successfully!");
    Serial.println("You can connect to the network using: ");
    Serial.println("network: " + networkName);
    Serial.println("Password: " + networkPassword);
    Serial.println("Host IP Address is: ");
    Serial.println(softAP);
    Serial.println();
  }
  else
  {
    Serial.println("Could not creat AP!");
  }
}

void loop()
{
  delay(1000);
  Serial.print("Number of connected devices (stations)");
  Serial.println(WiFi.softAPgetStationNum());
}