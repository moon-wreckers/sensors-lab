#include "sensorslab.h"


void dcMotorSetup()
{
  pinMode(DC_MOTOR_EN, OUTPUT);
  pinMode(DC_MOTOR_1, OUTPUT);
  pinMode(DC_MOTOR_2, OUTPUT);
}

void dcMotorControl(int dc_speed)
{
  Serial.println("Starting DC Motor Test");
  
  analogWrite(DC_MOTOR_EN, dc_speed);
  digitalWrite(DC_MOTOR_1, LOW);
  digitalWrite(DC_MOTOR_2, HIGH);
  delay(2000);
  
  digitalWrite(DC_MOTOR_EN, LOW);
  delay(500);
  
  analogWrite(DC_MOTOR_EN, dc_speed);
  digitalWrite(DC_MOTOR_1, HIGH);
  digitalWrite(DC_MOTOR_2, LOW);
  delay(2000);
  
  analogWrite(DC_MOTOR_EN, LOW);
  delay(500);
  
  Serial.println("DONE!");
  
}

