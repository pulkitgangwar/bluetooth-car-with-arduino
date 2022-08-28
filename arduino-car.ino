#include <AFMotor.h>

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

char cmd;

void moveForward()
{
    motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor3.run(FORWARD);
    motor4.run(FORWARD);
}
void moveBackward()
{
    motor1.run(BACKWARD);
    motor2.run(BACKWARD);
    motor3.run(BACKWARD);
    motor4.run(BACKWARD);
}
void moveLeft()
{
    motor1.run(FORWARD);
    motor2.run(BACKWARD);
    motor3.run(BACKWARD);
    motor4.run(FORWARD);
}
void moveRight()
{
    motor1.run(BACKWARD);
    motor2.run(FORWARD);
    motor3.run(FORWARD);
    motor4.run(BACKWARD);
}

void releaseMotors()
{

    motor1.run(RELEASE);
    motor2.run(RELEASE);
    motor3.run(RELEASE);
    motor4.run(RELEASE);
}

void setMotorSpeed(int maxSpeed)
{

    motor1.setSpeed(maxSpeed);
    motor2.setSpeed(maxSpeed);
    motor3.setSpeed(maxSpeed);
    motor4.setSpeed(maxSpeed);
}

void setCommandToMotor()
{
    if (cmd == 'F' || cmd == '1')
    {
        moveForward();
    }
    else if (cmd == 'B' || cmd == '2')
    {
        moveBackward();
    }
    else if (cmd == 'L' || cmd == '3')
    {
        moveLeft();
    }
    else if (cmd == 'R' || cmd == '4')
    {
        moveRight();
    }
    else if (cmd == 'S' || cmd == '5')
    {
        releaseMotors();
    }
}

void setup()
{
    Serial.begin(9600);
    setMotorSpeed();
}

void loop()
{
    if (Serial.available())
    {
        cmd = Serial.read();
    }

    setCommandToMotor();
}