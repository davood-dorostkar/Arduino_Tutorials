#include <Arduino.h>
#include <dht.h>
#include <SPI.h>
#include <SD.h>


int DHTPIN = 7;
const int chipSelect = 10;
unsigned long Secs=0;
dht DHT;


void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  Serial.print("Initializing SD card...");

  // see if the card is present and can be initialized:
  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    // don't do anything more:
    return;
  }
  Serial.println("card initialized.");
}

void loop() {
  // make a string for assembling the data to log:
  String dataString = "";
  int h = DHT.humidity;
  // Read temperature as Celsius (the default)
  int t = DHT.temperature; //true : fahrenheit   false:celsius
  unsigned long Secs=millis();

  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  File dataFile = SD.open("temp.txt", FILE_WRITE);

  // if the file is available, write to it:
  if (dataFile) {
    dataFile.println(String(Secs)+","+String(h)+","+String(t));
    dataFile.close();
    // print to the serial port too:
    Serial.println(String(Secs)+","+String(h)+","+String(t));
    delay(6000);
  }
  // if the file isn't open, pop up an error:
  else {
    Serial.println("error opening datalog.txt");
  }
}
