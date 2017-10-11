#include "sensorslab.h"

volatile signed int _encoder_pos = 0;


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


void dcMotorControl(int dc_speed, rot_dir direction)
 { 
  /*clockwise maybe */
  Serial.println("Writing to motor");
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
{}

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
  while(_encoder_pos < 1000)
  {
    Serial.println(_encoder_pos);
    analogWrite(DC_MOTOR_EN, DC_SPEED_HIGH);
    digitalWrite(DC_MOTOR_1, LOW);
    digitalWrite(DC_MOTOR_2, HIGH);
  }
    analogWrite(DC_MOTOR_EN, LOW);
  
  printEncoderPosition();
}
