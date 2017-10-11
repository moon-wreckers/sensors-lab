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
<<<<<<< HEAD
  
  // ABDUL MOEED TESTING FUNCTIONS:----------------------------
  //servoMotorControl();
  //dcMotorControl(DC_SPEED_LOW);
  //dcMotorControl(DC_SPEED_HIGH);
  
  flexSensorControl();
=======
  servoMotorControl();
  dcMotorControl(0);
  
  while(1){
    slotSensorControl(); 
    rot_pot_angle = rotPotSensorControl();
>>>>>>> ad5f08bc4641c563e6e91b19bdd9fa7a360ff1a0
  
  //dcMotorTestFunc(); 
  //printEncoderPosition();

}
<<<<<<< HEAD
=======

>>>>>>> ad5f08bc4641c563e6e91b19bdd9fa7a360ff1a0
