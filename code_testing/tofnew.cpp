#include <VL6180X.h>
#include <Wire.h>

#define GPIO1 PB10
#define GPIO2 PA7
#define GPIO3 PB11


#define tofAddress1 43
#define tofAddress2 44
#define tofAddress3 45

VL6180X tof1;
VL6180X tof2;
VL6180X tof3;

int tof[4]; // Assuming you want to store data from both sensors

void tofSetup()
{
    pinMode(GPIO1, OUTPUT);
    pinMode(GPIO2, OUTPUT);
    pinMode(GPIO3, OUTPUT);

    digitalWrite(GPIO1, LOW);
    digitalWrite(GPIO2, LOW);
    digitalWrite(GPIO3, LOW);

    Wire.begin();

    digitalWrite(GPIO1, HIGH);
    delay(10);
    tof1.init();
    tof1.configureDefault();
    // tof1.startRangeContinuous(); // Uncomment this if you want continuous ranging
    tof1.setTimeout(10);
    tof1.setAddress(tofAddress1);

    digitalWrite(GPIO2, HIGH);
    delay(10);
    tof2.init();
    tof2.configureDefault();
    // tof2.startRangeContinuous(); // Uncomment this if you want continuous ranging
    tof2.setTimeout(10);
    tof2.setAddress(tofAddress2);

    digitalWrite(GPIO3, HIGH);
    delay(10);
    tof3.init();
    tof3.configureDefault();
    // tof2.startRangeContinuous(); // Uncomment this if you want continuous ranging
    tof3.setTimeout(10);
    tof3.setAddress(tofAddress3);
}

void tofStart()
{
    tof[0] = tof1.readRangeSingleMillimeters();
    tof[1] = tof2.readRangeSingleMillimeters();
    tof[2] = tof3.readRangeSingleMillimeters();
}

void printTof()
{
    Serial.print(tof[0]); // Changed from Serial2 to Serial
    Serial.print(", ");
    Serial.print(tof[1]); // Changed from tof[2] to tof[1]
    Serial.print(", "); // Added a newline to separate readings
    Serial.print(tof[2]); // Changed from tof[2] to tof[1]
    Serial.println(); // Added a newline to separate readings
}

void setup()
{
    Serial.begin(9600); // Initialize serial communication
    tofSetup();
}

void loop()
{
    tofStart();
    printTof();
   delay(50); // Delay for 1 second before taking the next reading
}
