#include "sensorslab.h"

int rot_pot_angle=0;

byte state =0;
int readgate = 0;
long lastDebounceTime = 0;  // the last time the output pin was toggled
long debounceDelay = 300;    // the debounce time; increase if the output flickers

void setup() 
{
  Serial.begin(9600);
  pinMode(BUTTON_PIN, INPUT);

  slotSensorSetup();
  rotPotSensorSetup();
  servoMotorSetup();
  dcMotorSetup();

  /*setDesiredPosition(720);*/
  
  attachInterrupt(0, stateButtonInterrupt, RISING);

  delay(5000);
}

void loop() 
{
  
  // ABDUL MOEED TESTING FUNCTIONS:----------------------------
  //servoMotorControl();
  //dcMotorControl(DC_SPEED_LOW);
  //dcMotorControl(DC_SPEED_HIGH);
  
  //flexSensorControl();
 
  switch(state){
  case 0: //Servo motor
    servoMotorControl();
  break;
  case 1: //Stepper motor
    stepperMotorControl();
  break;
  case 2: //DC motor
    dcMotorTestFunc(); 
  /*while(1){*/
    pidControl();
  /*}*/
  break;
  }
    
  sendStateData();
  getDUICommands();
  
  //MATHEW TESTING FUNCTIONS:----------------------------------
  //while(1){
    //slotSensorControl(); 
    //rot_pot_angle = rotPotSensorControl();
  //printEncoderPosition();

}

void sendStateData(){}
void getDUICommands(){}


void stateButtonInterrupt() {

    if (!readgate && (millis() - lastDebounceTime) > debounceDelay) {
        lastDebounceTime = millis();
        readgate=1;

        state = (state+1)%3;
        Serial.print("State is now: ");
        Serial.println(state);

        dcMotorStop();
        stepperMotorStop();
        servoMotorStop();

    }  
}


