#define motorRA1 PB9 // Input 1 for motor driver
#define motorRA2 PB8 // Input 2 for motor driver

//eft motor control pins (commented out)
#define motorLB1 PB1
#define motorLB2 PA3

int leftBase = 100;
int rightBase = 100;
int leftPWM = 150;
int rightPWM = 150;

void setup() {
  // Set motor control pins as outputs
  pinMode(motorRA1, OUTPUT);
  pinMode(motorRA2, OUTPUT);
  
  // Left motor control pins (commented out)
  pinMode(motorLB1, OUTPUT);
  pinMode(motorLB2, OUTPUT);
}

void loop()
{
  turnLeft();
  delay(2000);
  // brakeNo();
  // delay(2000);


  // reverse();
  // delay(3000);
  // brake();
  
  // forwardBase();
  // delay(3000);
  // brake();
  // reverseBase();
  // delay(3000);
  // brake();
  // turnRight();
  // delay(3000);
  // brake();
  // turnLeft();
  // delay(3000);
  // brake();
  

}

void forward()
{
    digitalWrite(motorRA1,LOW);
    analogWrite(motorRA2,rightPWM);
    digitalWrite(motorLB1,LOW);
    analogWrite(motorLB2,leftPWM);
}

void reverse()
{
    analogWrite(motorRA1,rightPWM);
    digitalWrite(motorRA2,LOW);
    analogWrite(motorLB1,leftPWM);
    digitalWrite(motorLB2,LOW);
}

void brake()
{
    digitalWrite(motorRA1, HIGH);
    digitalWrite(motorRA2, HIGH);
    digitalWrite(motorLB1, HIGH);
    digitalWrite(motorLB2, HIGH);
    delay(100);
}

void brakeNo()
{
    
    digitalWrite(motorRA1, HIGH);
    digitalWrite(motorRA2, HIGH);
    digitalWrite(motorLB1, HIGH);
    digitalWrite(motorLB2, HIGH);
    //delay(100);
}

void forwardBase()
{
    digitalWrite(motorRA1,LOW);
    analogWrite(motorRA2,rightBase);
    digitalWrite(motorLB1,LOW);
    analogWrite(motorLB2,leftBase);
}

void reverseBase()
{
    analogWrite(motorRA1,rightBase);
    digitalWrite(motorRA2,LOW);
    analogWrite(motorLB1,leftBase);
    digitalWrite(motorLB2,LOW);
}

void turnRight()
{
    analogWrite(motorRA1,rightBase);
    digitalWrite(motorRA2,LOW);
    digitalWrite(motorLB1,LOW);
    analogWrite(motorLB2,leftBase);
}

void turnLeft()
{
    digitalWrite(motorRA1,LOW);
    analogWrite(motorRA2,rightBase);
    analogWrite(motorLB1,leftBase);
    digitalWrite(motorLB2,LOW);
}