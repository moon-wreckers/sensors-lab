
int rot_pot_angle=0;

void setup() 
{
  Serial.begin(9600);
  slotSensorSetup();
  rotPotSensorSetup();
  servoMotorSetup();
  dcMotorSetup();
}

void loop() 
{
  servoMotorControl();
  dcMotorControl(0);
  
  while(1){
    slotSensorControl(); 
    rot_pot_angle = rotPotSensorControl();
  
  };

}

