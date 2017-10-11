#include "sensorslab.h"

void setup() 
{
  Serial.begin(9600);
  slotSensorSetup();
  servoMotorSetup();
  dcMotorSetup();
  
  delay(5000);
}

void loop() 
{
  
  // ABDUL MOEED TESTING FUNCTIONS:----------------------------
  //servoMotorControl();
  //dcMotorControl(DC_SPEED_LOW);
  //dcMotorControl(DC_SPEED_HIGH);
  
  flexSensorControl();
  
  //dcMotorTestFunc(); 
  //printEncoderPosition();

}
