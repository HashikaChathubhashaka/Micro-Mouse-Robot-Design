#include "VL6180X.h"
#include <Arduino.h>
#include <Wire.h>

// Define motor pins
#define motorLA1 PB9
#define motorLA2 PA3
#define motorRA1 PB8
#define motorRA2 PA12

// Define TOF sensor pins and addresses
#define GPIO1 PB10
#define GPIO2 PA7
#define GPIO3 PB11
#define tofAddress1 43
#define tofAddress2 44
#define tofAddress3 45

VL6180X tof1;
VL6180X tof2;
VL6180X tof3;

// Motor PWM parameters
int leftBase = 100;
int rightBase = 100;
int leftPwm = 150;
int rightPwm = 150;

void setup() {
  // Initialize TOF sensors
  Wire.begin();
  tofSetup();

  // Set motor control pins as outputs
  pinMode(motorLA1, OUTPUT);
  pinMode(motorLA2, OUTPUT);
  pinMode(motorRA1, OUTPUT);
  pinMode(motorRA2, OUTPUT);

  // Initialize Serial for debugging (optional)
  Serial.begin(9600);
}

void loop() {
  int distance1 = tof1.readRangeSingleMillimeters();
  int distance2 = tof2.readRangeSingleMillimeters();
  int distance3 = tof3.readRangeSingleMillimeters();

  // Implement your wall-following logic here
  // Adjust motor control functions accordingly based on sensor readings

  // Example: If the robot detects an obstacle on the left, turn right
  if (distance1 > 180) {
    forward();
    delay(800);
    brake(); // Corrected typo from "brake()" to "brake()"
    delay(500);
    turnRight();
  }
  // Example: If the robot is far from the wall on the right, turn left
  else if (distance3 > 180) {
    forward();
    delay(800);
    brake(); // Corrected typo from "brake()" to "brake()"
    delay(500);
    turnLeft();
  }
  // Example: If no obstacle detected, move forward
  else {
    forward();
  }

  // Print sensor readings for debugging (optional)
  Serial.print("Distances: ");
  Serial.print(distance1);
  Serial.print(" | ");
  Serial.print(distance2);
  Serial.print(" | ");
  Serial.println(distance3);

  // Add a delay to control the loop rate
  // delay(100);
}

void leftForward() {
  digitalWrite(motorLA1, HIGH);
  digitalWrite(motorLA2, LOW);
}

void leftReverse() {
  digitalWrite(motorLA1, LOW);
  digitalWrite(motorLA2, HIGH);
}

void leftBrake() {
  digitalWrite(motorLA1, LOW);
  digitalWrite(motorLA2, LOW);
}

void leftForwardBase() {
  digitalWrite(motorLA1, LOW);
  analogWrite(motorLA2, leftBase);
}

// void leftReverseBase() {
//   analogWrite(motorLA1, leftBase);
//   digitalWrite(motorLA2, LOW);
// }

void rightForward() {
  digitalWrite(motorRA1, HIGH);
  digitalWrite(motorRA2, LOW);
}

void rightReverse() {
  digitalWrite(motorRA1, LOW);
  digitalWrite(motorRA2, HIGH);
}

void rightBrake() {
  digitalWrite(motorRA1, LOW);
  digitalWrite(motorRA2, LOW);
}

void rightForwardBase() {
  digitalWrite(motorRA1, LOW);
  analogWrite(motorRA2, rightBase);
}

// void rightReverseBase() {
//   analogWrite(motorRA1, rightBase);
//   digitalWrite(motorRA2, LOW);
// }

void writePwm() {
  analogWrite(motorLA1, leftPwm);
  analogWrite(motorRA1, rightPwm);
}

void writeBasePwm() {
  analogWrite(motorLA1, leftBase);
  analogWrite(motorRA1, rightBase);
}

void forward() {
  leftForward();
  rightForward();
  writePwm();
}

void reverse() {
  leftReverse();
  rightReverse();
}

void brake() {
  leftBrake();
  rightBrake();
}

void forwardBase() {
  leftForward();
  rightForward();
  writeBasePwm();
}

// void reverseBase() {
//   leftReverse();
//   rightReverse();
//   writeBasePwm();
// }

void turnRight() {
  leftForward();
  rightReverse();
  writeBasePwm();
}

void turnLeft() {
  leftReverse();
  rightForward();
  writeBasePwm();
}

void tofSetup() {
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
  // tof1.startRangeContinuous(); // Uncomment this if you want continuous
  // ranging
  tof1.setTimeout(10);
  tof1.setAddress(tofAddress1);

  digitalWrite(GPIO2, HIGH);
  delay(10);
  tof2.init();
  tof2.configureDefault();
  // tof2.startRangeContinuous(); // Uncomment this if you want continuous
  // ranging
  tof2.setTimeout(10);
  tof2.setAddress(tofAddress2);

  digitalWrite(GPIO3, HIGH);
  delay(10);
  tof3.init();
  tof3.configureDefault();
  // tof2.startRangeContinuous(); // Uncomment this if you want continuous
  // ranging
  tof3.setTimeout(10);
  tof3.setAddress(tofAddress3);
}
