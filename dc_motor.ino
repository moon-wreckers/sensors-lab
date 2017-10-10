#include "sensorslab.h"

void dcMotorSetup()
{
  pinMode(DC_MOTOR_EN, OUTPUT);
  pinMode(DC_MOTOR_1, OUTPUT);
  pinMode(DC_MOTOR_2, OUTPUT);
}

void dcMotorControl()
{
  Serial.println("Starting DC Motor Test");
  
  digitalWrite(DC_MOTOR_EN, HIGH);
  digitalWrite(DC_MOTOR_1, LOW);
  digitalWrite(DC_MOTOR_2, HIGH);
  delay(2000);
  
  digitalWrite(DC_MOTOR_EN, LOW);
  delay(500);
  
  digitalWrite(DC_MOTOR_EN, HIGH);
  digitalWrite(DC_MOTOR_1, HIGH);
  digitalWrite(DC_MOTOR_2, LOW);
  delay(2000);
  
  digitalWrite(DC_MOTOR_EN, LOW);
  delay(500);
  
  Serial.println("DONE!");
  
}
