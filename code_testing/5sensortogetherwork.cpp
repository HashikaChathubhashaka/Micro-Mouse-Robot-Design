#include <Wire.h>
#include <VL6180X.h>

// Define instances for five VL6180X sensors
VL6180X sensor1;
VL6180X sensor2;
VL6180X sensor3;
VL6180X sensor4;
VL6180X sensor5;

// Variables to store distance measurements from each sensor
int s1_distance;
int s2_distance;
int s3_distance;
int s4_distance;
int s5_distance;

#define sensor1_xshut PB10
#define sensor2_xshut PA5
#define sensor3_xshut PA7
#define sensor4_xshut PA6
#define sensor5_xshut PB11

void setup()
{
  // Setting up pins for controlling sensor power
  pinMode(sensor1_xshut, OUTPUT);
  pinMode(sensor2_xshut, OUTPUT);
  pinMode(sensor3_xshut, OUTPUT);
  pinMode(sensor4_xshut, OUTPUT);
  pinMode(sensor5_xshut, OUTPUT);

  // Setting initial pin states to LOW
  digitalWrite(sensor1_xshut, LOW);
  digitalWrite(sensor2_xshut, LOW);
  digitalWrite(sensor3_xshut, LOW);
  digitalWrite(sensor4_xshut, LOW);
  digitalWrite(sensor5_xshut, LOW);

  // Wait for sensors to stabilize after power up
  delay(500);

  // Initialize the I2C communication
  Wire.begin();

  // Initialize serial communication for debugging
  Serial.begin(115200);

  // Initialization and configuration of each sensor
  digitalWrite(sensor1_xshut, HIGH); // Power up sensor 1
  delay(150);
  Serial.println("Sensor 1 done powering up");
  sensor1.init(true); // Initialize sensor 1
  Serial.println("Sensor 1 done initiating");
  delay(100);
  sensor1.setAddress((uint8_t)0x29); // Set sensor 1 address
  Serial.println("Sensor 1 done setting addressing");

  digitalWrite(sensor2_xshut, HIGH); // Power up sensor 2
  delay(150);
  sensor2.init(true); // Initialize sensor 2
  Serial.println("Sensor 2 done powering up");
  delay(100);
  sensor2.setAddress((uint8_t)0x30); // Set sensor 2 address
  Serial.println("Sensor 2 done setting addressing");

  // Similar setup for sensors 3 to 5
  digitalWrite(sensor3_xshut, HIGH); // Power up sensor 3
  delay(150);
  sensor3.init(true); // Initialize sensor 3
  Serial.println("Sensor 3 done powering up");
  delay(100);
  sensor3.setAddress((uint8_t)0x31); // Set sensor 3 address
  Serial.println("Sensor 3 done setting addressing");

  digitalWrite(sensor4_xshut, HIGH); // Power up sensor 4
  delay(150);
  sensor4.init(true); // Initialize sensor 4
  Serial.println("Sensor 4 done powering up");
  delay(100);
  sensor4.setAddress((uint8_t)0x32); // Set sensor 4 address
  Serial.println("Sensor 4 done setting addressing");

  digitalWrite(sensor5_xshut, HIGH); // Power up sensor 5
  delay(150);
  sensor5.init(true); // Initialize sensor 5
  Serial.println("Sensor 5 done powering up");
  delay(100);
  sensor5.setAddress((uint8_t)0x33); // Set sensor 5 address
  Serial.println("Sensor 5 done setting addressing");

  Serial.println("Addresses set");

  // Start continuous distance measurement for each sensor
  sensor1.startContinuous();
  sensor2.startContinuous();
  sensor3.startContinuous();
  sensor4.startContinuous();
  sensor5.startContinuous();
}

void readSensorDistances()
{
  // Read and print distance measurements from each sensor
  s1_distance = sensor1.readRangeContinuousMillimeters();
  Serial.print("s1 : ");
  Serial.print(s1_distance);

  s2_distance = sensor2.readRangeContinuousMillimeters();
  Serial.print("     s2: ");
  Serial.print(s2_distance);

  s3_distance = sensor3.readRangeContinuousMillimeters();
  Serial.print("     s3: ");
  Serial.print(s3_distance);

  s4_distance = sensor4.readRangeContinuousMillimeters();
  Serial.print("     s4: ");
  Serial.print(s4_distance);

  s5_distance = sensor5.readRangeContinuousMillimeters();
  Serial.print("     s5: ");
  Serial.println(s5_distance);
}

void loop()
{
  readSensorDistances();

  // Add a delay if needed between measurements
  delay(100);
}
