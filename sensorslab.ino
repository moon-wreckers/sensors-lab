
void setup() 
{
  Serial.begin(9600);
  slotSensorSetup();
  servoMotorSetup();
  dcMotorSetup();
}

void loop() 
{
  servoMotorControl();
  dcMotorControl();
  
  while(1){
    slotSensorControl(); 
  
  };

}

:kjkjj
