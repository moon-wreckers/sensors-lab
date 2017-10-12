const int stepPin = 13;
const int dirPin = 12;
const int enblPin = 8;

int position =0;
void stepperMotorsetup() {
  // put your setup code here, to run once:
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(enblPin, OUTPUT);
}

void stepperMotorControl(int angle) {
  // 3200 steps/counts - make one rotation 
  // Enables the motor to move in the given direction
  angle = angle%360;
  int counts= map(angle, -360, 360, -3200, 3200);
  position+=angle;
  
  if(counts >= 0){

    digitalWrite(dirPin, HIGH);
  }
  else if (counts < 0){
    digitalWrite(dirPin, LOW);
  }
  else {
    return;
  }
  // Step 3200 times to make one full rotation (MS1, MS2, MS3 - LOW)
  for(int x = 0; x <abs(counts); x++){
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(100);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(100);
  }

}

int getStepperPos() 
{
return position;
}
