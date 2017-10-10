
void setup() 
{
  Serial.begin(9600);
  servoMotorSetup();
  dcMotorSetup();
}

void loop() 
{
  servoMotorControl();
  dcMotorControl();
  
  while(1);

}


