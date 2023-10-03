// Define motor control pins
#define motorRA1 PB9 // Input 1 for motor driver
#define motorRA2 PA3 // Input 2 for motor driver

//eft motor control pins (commented out)
#define motorLB1 PB8
#define motorLB2 PA12

void setup() {
  // Set motor control pins as outputs
  pinMode(motorRA1, OUTPUT);
  pinMode(motorRA2, OUTPUT);
  
  // Left motor control pins (commented out)
  pinMode(motorLB1, OUTPUT);
  pinMode(motorLB2, OUTPUT);
}

void loop() {
  // Forward direction (motor rotates clockwise)
  digitalWrite(motorRA1, HIGH);
  digitalWrite(motorRA2, LOW);

  // Left motor control (commented out)
  digitalWrite(motorLB1, HIGH);
  digitalWrite(motorLB2, LOW);

  delay(2000); // Run forward for 2 seconds

  // Stop the motors
  digitalWrite(motorRA1, LOW);
  digitalWrite(motorRA2, LOW);

  // Left motor control (commented out)
  digitalWrite(motorLB1, LOW);
  digitalWrite(motorLB2, LOW);

  delay(2000);

  // Reverse direction (motor rotates counterclockwise)
  digitalWrite(motorRA1, LOW);
  digitalWrite(motorRA2, HIGH);

  // Left motor control (commented out)
  digitalWrite(motorLB1, LOW);
  digitalWrite(motorLB2, HIGH);

  delay(2000); // Run in reverse for 2 seconds

  // Stop the motors
  digitalWrite(motorRA1, LOW);
  digitalWrite(motorRA2, LOW);

  // Left motor control (commented out)
  digitalWrite(motorLB1, LOW);
  digitalWrite(motorLB2, LOW);

  delay(2000);
}




