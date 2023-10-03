
void forward()
{
    digitalWrite(motorRA1,LOW);
    analogWrite(motorRA2,rightPwm);
    digitalWrite(motorLB1,LOW);
    analogWrite(motorLB2,leftPwm);
}

void reverse()
{
    analogWrite(motorRA1,rightPwm);
    digitalWrite(motorRA2,LOW);
    analogWrite(motorLB1,leftPwm);
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

void rightReverseBase()
{
    analogWrite(motorRA1,rightBase);
    digitalWrite(motorRA2,LOW);
}

void rightForwardBase()
{
    digitalWrite(motorRA1,LOW);
    analogWrite(motorRA2,rightBase);
}

void leftForwardBase()
{
    digitalWrite(motorLB1,LOW);
    analogWrite(motorLB2,leftBase);
}

void leftReverseBase()
{
    analogWrite(motorLB1,leftBase);
    digitalWrite(motorLB2,LOW);
}

void rightForward()
{
    digitalWrite(motorRA1,LOW);
    analogWrite(motorRA2,rightPwm);
}

void rightReverse()
{
    analogWrite(motorRA1,rightPwm);
    digitalWrite(motorRA2,LOW);
}

void leftForward()
{
    digitalWrite(motorLB1,LOW);
    analogWrite(motorLB2,leftPwm);
}

void leftReverse()
{
    analogWrite(motorLB1,leftPwm);
    digitalWrite(motorLB2,LOW); 
}


