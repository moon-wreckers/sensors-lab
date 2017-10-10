#include "sensorslab.h"

int dc_len_of_period;                     // Microsecond
int dc_len_of_pulse;                      // Microsecond
int dc_len_of_pulse_start;                // Microsecond
int dc_len_of_pulse_end;                  // Microsecond
int dc_len_of_pulse_step;                 // Microsecond

int t1;                                   // Duty-cycle Variables (Microseconds)
int t2;                                   // Duty-cycle Variables (Microseconds)

enum Speed
{
  DC_SPEED_LOW, DC_SPEED_MEDIUM, DC_SPEED_HIGH 
};

void dcMotorSetup()
{
  pinMode(DC_MOTOR_EN, OUTPUT);
  pinMode(DC_MOTOR_1, OUTPUT);
  pinMode(DC_MOTOR_2, OUTPUT);
  
  dc_len_of_period = 25 * 1000;                      // Microsecond
  dc_len_of_pulse = 0;                               // Microsecond
  dc_len_of_pulse_start = 0.575 * 1000;              // Microsecond
  dc_len_of_pulse_end = 2.350 * 1000;                // Microsecond
  dc_len_of_pulse_step = 0.01 * 1000;                // Microsecond
}

void dcMotorSetSpeed()
{
  
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
