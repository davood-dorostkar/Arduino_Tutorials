#include <Arduino.h>
/*
SanatBazar
Arduino Tutorial Series
Author: Davood Dorostkar
Website: www.sanatbazar.com

*/

#include <IPAddress.h>
#include <EtherCard.h>
#include <dht.h>
#define SS 10
#define dhtPin 2
static byte mymac[] = {0x74, 0x69, 0x69, 0x2D, 0x30, 0x31};
byte Ethernet::buffer[700];
const int dstPort PROGMEM = 1234;
const int srcport PROGMEM = 42;
uint8_t dstip[] = "192.168.1.138";
dht DHT22;
String temperature;
String humidity;

void udpSerialPrint(uint16_t dest_port, uint8_t src_ip[4], uint16_t src_port, const char *data, uint16_t len)
{
  IPAddress src(src_ip[0], src_ip[1], src_ip[2], src_ip[3]);

  ether.printIp("SRV: ", ether.hisip);
  Serial.print("dest_port: ");
  Serial.println(dest_port);
  Serial.print("src_port: ");
  Serial.println(src_port);

  Serial.print("src_ip: ");
  ether.printIp(src_ip);
  Serial.println("");
  Serial.println("data: ");
  Serial.println(data);
  Serial.print("Lenght: ");
  Serial.println(strlen(data));

  const char *t = temperature.c_str();
  const char *h = humidity.c_str();
  ether.sendUdp(t, sizeof(t), dest_port, src_ip, src_port);
  ether.sendUdp(h, sizeof(h), dest_port, src_ip, src_port);
}

void setup()
{
  Serial.begin(9600);
  Serial.println("\n[testDHCP]");
  Serial.print("MAC: ");
  for (byte i = 0; i < 6; ++i)
  {
    Serial.print(mymac[i], HEX);
    if (i < 5)
      Serial.print(':');
  }
  Serial.println();
  if (ether.begin(sizeof Ethernet::buffer, mymac, SS) == 0)
    Serial.println("Ethernet chip not responding");
  else if (!ether.dhcpSetup())
    Serial.println("failed to setup DHCP");
  else
  {
    Serial.println("Setting up DHCP ... ");
    ether.printIp("Module IP: ", ether.myip);
    ether.printIp("Netmask: ", ether.netmask);
    ether.printIp("GateWay IP: ", ether.gwip);
    ether.printIp("DNS IP: ", ether.dnsip);
  }
  ether.udpServerListenOnPort(&udpSerialPrint, srcport);
}

void loop()
{
  ether.udpServerPauseListenOnPort(srcport);
  DHT22.read(dhtPin);
  temperature = (String)DHT22.temperature;
  humidity = (String)DHT22.humidity;
  ether.udpServerListenOnPort(&udpSerialPrint, srcport);
  ether.packetLoop(ether.packetReceive());
}
