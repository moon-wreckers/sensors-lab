#include "sensorslab.h"

int rot_pot_angle=0;

int state =0;
int readgate = 0;
long lastDebounceTime = 0;  // the last time the output pin was toggled
long debounceDelay = 300;    // the debounce time; increase if the output flickers

int slot_sensor_value =0;
int rot_pot_value = 0;
int flex_sensor_value =0;
int ir_sensor_value =0;

int servo_motor_angle = 0;
int stepper_motor_output = 0;
int dc_motor_encoder = 0;
int dc_motor_voltage = 0;


int control=0;
int commanded_vel=0;


void setup() 
{
  Serial.begin(9600);
  Serial.println("Beginning Setup");


  pinMode(BUTTON_PIN, INPUT);

  slotSensorSetup();
  rotPotSensorSetup();
  servoMotorSetup();
  dcMotorSetup();

  /*setDesiredPosition(720);*/
  
  attachInterrupt(0, stateButtonInterrupt, RISING);

  delay(3000);
  Serial.println("Ending Setup");
  Serial.setTimeout(100);
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
    servoMotorControl(control);
  break;
  case 1: //Stepper motor
    stepperMotorControl(control);
  break;
  case 2: //DC motor
    /*dcMotorTestFunc(); */
  /*while(1){*/
    /*pidControl();*/
  /*}*/
  break;
  }
    
  sendStateData();
  getDUICommands();
  
  //MATHEW TESTING FUNCTIONS:----------------------------------
  //while(1){ slotSensorControl(); 
    //rot_pot_angle = rotPotSensorControl();
  
  //printEncoderPosition();
  Serial.print("state: ");
  Serial.println(state);

}


void getDUICommands()
{
    String inString;
    if (Serial.available() > 0) {
        inString = Serial.readString(); 
    }
    char command = inString.charAt(0);
    String data = inString.substring(1); 
    switch(command){
    case 's':
       state = data.toInt();
    break;
    case 'a':
        command = data.toInt();
    break;
    case 'v':
        commanded_vel = data.toInt();
    break;
    }
}

void sendStateData(){

String output="";
output+="sb";
output+=String(state);
output+="rp";
output+=String(rot_pot_value);
output+="bb";
output+=String(flex_sensor_value);
output+="ir";
output+=String(ir_sensor_value);
output+="ss";
output+=String(slot_sensor_value);
output+="sv";
output+=String(servo_motor_angle);
output+="st";
output+=String(stepper_motor_output);
output+="sv";
output+=String(servo_motor_angle);
output+="dc";
output+=String(dc_motor_encoder);
output+="dv";
output+=String(dc_motor_voltage);

/*Serial.println(output);*/
}


void stateButtonInterrupt() {

    if (!readgate && (millis() - lastDebounceTime) > debounceDelay) {
        lastDebounceTime = millis();
        readgate=1;

        state = (state+1)%3;
        Serial.print("State is now: ");
        Serial.println(state);

        control = 0;
        dcMotorStop();
        stepperMotorStop();

    }  
}


