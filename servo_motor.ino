#include "sensorslab.h"
#include <Servo.h>

Servo myservo;

void servoMotorSetup() 
{
  myservo.attach(SERVO_PIN);
  myservo.write(90); // min = 0, max = 180*/
}


void servoMotorControl(int angle) 
{
  myservo.write(angle); // min = 0, max = 180
  /*myservo.write(90); // min = 0, max = 180*/
  /*delay(2000);*/
  /*myservo.write(0);*/
  /*delay(2000);*/
  /*myservo.write(180);*/
  /*delay(2000);*/
  /*myservo.write(0);*/
  /*delay(2000);*/
  }


int getServoAngle() 
{
  return myservo.read();
}
