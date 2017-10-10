#include "sensorslab.h"

int servo_len_of_period;                     // Microsecond
int servo_len_of_pulse;                      // Microsecond
int servo_len_of_pulse_start;                // Microsecond
int servo_len_of_pulse_end;                  // Microsecond
int servo_len_of_pulse_step;                 // Microsecond


void servoMotorSetup() 
{
  pinMode(SERVO_PIN, OUTPUT);
  servo_len_of_period = 25 * 1000;                      // Microsecond
  servo_len_of_pulse = 0;                               // Microsecond
  servo_len_of_pulse_start = 0.575 * 1000;              // Microsecond
  servo_len_of_pulse_end = 2.350 * 1000;                // Microsecond
  servo_len_of_pulse_step = 0.01 * 1000;                // Microsecond
}


void servoMotorControl() 
{
  Serial.println("Starting Servo Motor Test");

  while (servo_len_of_pulse < servo_len_of_pulse_end)
  {
    digitalWrite(SERVO_PIN, HIGH);

    delayMicroseconds(servo_len_of_pulse);

    digitalWrite(SERVO_PIN, LOW);

    delayMicroseconds(servo_len_of_period - servo_len_of_pulse); 

    servo_len_of_pulse += servo_len_of_pulse_step;

    //Serial.print("lenMicroSecondsOfPulse: ");
    //Serial.println(servo_len_of_pulse);
  }
  
  Serial.println("Done!");
}
