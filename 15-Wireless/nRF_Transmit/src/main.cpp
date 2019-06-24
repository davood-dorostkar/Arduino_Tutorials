#include <Arduino.h>

#include <nRF24L01.h>
#include <RF24.h>
RF24 wifiSender(7, 8);
const byte address[] = "00001";
const char amplifications[] = {RF24_PA_MIN, RF24_PA_LOW, RF24_PA_HIGH, RF24_PA_MAX};
int inputAmp=0;

const byte numChars = 32;
char receivedChars[numChars]; // an array to store the received data
// boolean newData = false;
int dataNumber = 0; // new for this version

int recvWithEndMarker()
{
    static byte ndx = 0;
    char endMarker = '\n';
    char rc;

    if (Serial.available() > 0)
    {
        rc = Serial.read();

        if (rc != endMarker)
        {
            receivedChars[ndx] = rc;
            ndx++;
            if (ndx >= numChars)
            {
                ndx = numChars - 1;
            }
        }
        else
        {
            receivedChars[ndx] = '\0'; // terminate the string
            ndx = 0;
            // newData = true;
            dataNumber = atoi(receivedChars);
        }
    }
}

int showNewNumber()
{

        dataNumber = 0;                   // new for this version
        dataNumber = atoi(receivedChars); // new for this version
        // Serial.print("This just in ... ");
        // Serial.println(receivedChars);
        // Serial.print("Data as Number ... "); // new for this version
        // Serial.println(dataNumber);          // new for this version
        // newData = false;
        return dataNumber;

}

void setup()
{
    Serial.begin(9600);
    // do
    // {
    //     Serial.println("Enter distance between wifi modules (from 0 to 3): ");
    //     if (Serial.available() > 0)
    //         inputAmp = Serial.read();
    // } while (inputAmp > 4 && inputAmp < 0);

        Serial.println("Enter distance between wifi modules (from 0 to 3): ");
        // recvWithEndMarker();
        inputAmp = recvWithEndMarker();


    Serial.println(inputAmp);
    wifiSender.begin();
    Serial.println("Initializing the wifi... ");
    wifiSender.openWritingPipe(address);
    wifiSender.setPALevel(amplifications[inputAmp]);
    Serial.println("The amplification is set to: " + String(wifiSender.getPALevel()));
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
