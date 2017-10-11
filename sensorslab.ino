#include "sensorslab.h"

int rot_pot_angle=0;

void setup() 
{
  Serial.begin(9600);
  slotSensorSetup();
  rotPotSensorSetup();
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
  
  //flexSensorControl();
  
  
  //MATHEW TESTING FUNCTIONS:----------------------------------
  //while(1){
    //slotSensorControl(); 
    //rot_pot_angle = rotPotSensorControl();
  
  dcMotorTestFunc(); 
  //printEncoderPosition();

}
