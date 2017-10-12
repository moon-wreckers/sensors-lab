#include "sensorslab.h"


int state =0;
int readgate = 0;
long lastDebounceTime = 0;  // the last time the output pin was toggled
long debounceDelay = 300;    // the debounce time; increase if the output flickers

int rot_pot_angle=0;
int slot_sensor_value =0;
int flex_sensor_value =0;
int ir_sensor_value =0;

int servo_motor_angle = 0;
int stepper_motor_output = 0;
int dc_motor_encoder = 0;
int dc_motor_speed = 0;


int angle=0;
int rot_pot_control=0;
int commanded_vel=0;

long interval = 100L;
long prevTime;
long currentTime;


void setup() 
{
  currentTime = millis();
  prevTime = currentTime;
  Serial.begin(9600);
  Serial.println("Beginning Setup");


  pinMode(BUTTON_PIN, INPUT);

  slotSensorSetup();
  flexSensorSetup();
  rotPotSensorSetup();
  servoMotorSetup();
  stepperMotorsetup();
  dcMotorSetup();

  /*setDesiredPosition(720);*/
  
  attachInterrupt(0, stateButtonInterrupt, RISING);

  /*delay(3000);*/
  Serial.println("Ending Setup");
  Serial.setTimeout(100);
}

void loop() 
{
  // ABDUL MOEED TESTING FUNCTIONS:----------------------------
   flex_sensor_value = flexSensorControl();
   rot_pot_angle = rotPotSensorControl();
   ir_sensor_value = irSensorControl();
   slot_sensor_value = slotSensorControl();

   dc_motor_encoder = getEncoderPos();
   dc_motor_speed = getDCVelocity();
   servo_motor_angle = getServoAngle();
   stepper_motor_output = getStepperPos();

   if(rot_pot_control){
    Serial.println(rot_pot_angle);
       angle = rot_pot_angle;
   }

  switch(state){
  case 0: //Servo motor
    servoMotorControl(angle);
  break;
  case 1: //Stepper motor
    stepperMotorControl(angle);
    angle = 0;
  break;
  case 2: //DC motor
  if (commanded_vel)
    dcSpeedControl(angle);
  else
    dcMotorControl(angle); 
  break;
  }
    
  sendStateData();
  getDUICommands();
  
  
  int reading = digitalRead(BUTTON_PIN);
  if (reading == 0){ readgate =0;}

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
       changeState(data.toInt());
        Serial.print("state: ");
        Serial.println(state);
    break;
    case 'a':
        angle = data.toInt();
         Serial.print("angle: ");
         Serial.println(angle);
    break;
    case 'v':
        commanded_vel = data.toInt();
    break;
    case 'p':
        rot_pot_control = data.toInt();
        commanded_vel = 0;
         Serial.print("rot_pot_control: ");
         Serial.println(rot_pot_control);
    break;
    }
}

void sendStateData(){

String output="";
output+="sb";
output+=String(state);
output+="rp";
output+=String(rot_pot_angle);
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
output+="dc";
output+=String(dc_motor_encoder);
output+="dv";
output+=String(dc_motor_speed);
currentTime = millis();
if (currentTime - prevTime > interval) {
  /*Serial.println(output);*/
  prevTime = millis();
}
}

void changeState(int s)
{
    state = s;
    angle = 0;
    commanded_vel = 0;
    dcMotorStop();
}

void stateButtonInterrupt() {

    if (!readgate && (millis() - lastDebounceTime) > debounceDelay) {
        lastDebounceTime = millis();
        readgate=1;

        changeState((state+1)%3);
        dcMotorStop();
        /*Serial.print("State is now: ");*/
        /*Serial.println(state);*/

    }  
}


