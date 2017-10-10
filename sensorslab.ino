/*#include "servo_motor.h"*/

#define SERVO_PIN  8
void setup() 
{
  Serial.begin(9600);
  pinMode(SERVO_PIN, OUTPUT);
  servo_motor_setup();
}

void loop() 
{

servo_motor_control();
 Serial.println("Done!");
 Serial.println();
pid_control();
 
 while(1);

}


