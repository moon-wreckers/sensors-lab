#include "sensorslab.h"
#include <Servo.h>

Servo myservo;

void servoMotorSetup() 
{
  myservo.attach(PIN_SERVO);
}


void servoMotorControl() 
{
  myservo.write(90); // min = 0, max = 180
  delay(2000);
  myservo.write(0);
  delay(2000);
  myservo.write(180);
  delay(2000);
  myservo.write(0);
  delay(2000);
  }
void servoMotorStop() 
{
}
