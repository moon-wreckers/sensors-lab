#include "sensorslab.h"

volatile signed int _encoder_pos = 0;

double err_p, err_i, err_d, err_last = 0;
unsigned long lastTick;
int desired;
/*unsigned int current;*/
bool drive_vel, drive_position;
unsigned long last_time;

const double k_p = 0.8;
const double k_i = 0.1;
const double k_d = 0.1;



void dcMotorSetup()
{
  pinMode(DC_MOTOR_EN, OUTPUT);
  pinMode(DC_MOTOR_1, OUTPUT);
  pinMode(DC_MOTOR_2, OUTPUT);
  
  pinMode(DC_MOTOR_ENC_A, INPUT);
  pinMode(DC_MOTOR_ENC_B, INPUT);
  
  attachInterrupt(DC_MOTOR_ENC_A, encoderInterruptCallBack, CHANGE);
}

void encoderInterruptCallBack()
{
    /*Serial.println("motor moved");*/
  if(digitalRead(DC_MOTOR_ENC_A) == digitalRead(DC_MOTOR_ENC_B))
  {
    _encoder_pos++;
  }
  else
  {
    _encoder_pos--;
  }
}

void dcMotorControl(int desired){
/*Serial.println("pid control loop");*/
unsigned long time = millis();
unsigned long timestep = time-last_time;
err_p = desired - _encoder_pos;
err_i += err_p;
err_d += (err_p-err_last)/timestep;

Serial.print("pos: ");
Serial.print(_encoder_pos);
Serial.print(" err_p: ");
Serial.print(err_p);
Serial.print(" err_i: ");
Serial.print(err_i);
Serial.print(" err_d: ");
Serial.print(err_d);

Serial.print(" pid output: ");
double output = err_p*k_p+err_i*k_i+err_d*k_d;
Serial.println(output);
/*Serial.print(" pid target: ");*/
/*Serial.println(desired);*/

dcMotorDrive((int)output, CLOCKWISE);
err_last = err_p;
last_time = time;


}

void dcMotorDrive(int dc_speed, rot_dir direction)
 { 
  /*clockwise maybe */
  /*Serial.println("Writing to motor");*/
  analogWrite(DC_MOTOR_EN, dc_speed);

  if(direction == CLOCKWISE){
  digitalWrite(DC_MOTOR_1, LOW);
  digitalWrite(DC_MOTOR_2, HIGH);
  }
  else{
  digitalWrite(DC_MOTOR_1, HIGH);
  digitalWrite(DC_MOTOR_2, LOW);
  }

  /*delay(2000);*/
  
  /*[>stop<]*/
  /*digitalWrite(DC_MOTOR_EN, LOW);*/
  /*delay(500);*/
  
  /*analogWrite(DC_MOTOR_EN, dc_speed);*/
  /*delay(2000);*/
  
  /*analogWrite(DC_MOTOR_EN, LOW);*/
  /*delay(500);*/
  
  /*Serial.println("DONE!");  */

}

void dcMotorStop()
{
    Serial.println("stopping dc motor");
    analogWrite(DC_MOTOR_EN, LOW);
}

unsigned int getEncoderPos()
{
  return _encoder_pos;
}

void printEncoderPosition()
{
  Serial.print("Encoder Position: ");
  Serial.println(_encoder_pos, DEC);
}

void dcMotorTestFunc()
{
  Serial.println("dc motor test");
  if(_encoder_pos < 1000)
  {
    analogWrite(DC_MOTOR_EN, DC_SPEED_HIGH);
    digitalWrite(DC_MOTOR_1, LOW);
    digitalWrite(DC_MOTOR_2, HIGH);
  }
  else{
    analogWrite(DC_MOTOR_EN, LOW);
    }
  
  printEncoderPosition();
}
