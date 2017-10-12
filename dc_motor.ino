#include "sensorslab.h"

volatile signed int _encoder_pos = 0;
bool motor_on = false;
double err_p, err_i, err_d, err_last, pos_last, pos_cur = 0;
double swin_acc_err = 0;
unsigned long pid_time_last, pid_time_cur = 0;
unsigned long lastTick;
double current_vel =0;
int desired;
/*unsigned int current;*/
bool drive_vel, drive_position;

const double k_p = 1.0;
const double k_i = 0.005;
const double k_d = 0.2;
const int output_offset = 100;

long current_encoder_pos = 0;
long last_time = 0;
long last_vel_time, cur_vel_time = 0;
long last_encoder_pos = 0;
int dc_ctrl_output = 0;

void dcMotorSetup()
{
  pinMode(DC_MOTOR_EN, OUTPUT);

  pinMode(DC_MOTOR_1, OUTPUT);
  pinMode(DC_MOTOR_2, OUTPUT);

  pinMode(DC_MOTOR_ENC_A, INPUT);
  pinMode(DC_MOTOR_ENC_B, INPUT);

  attachInterrupt(DC_MOTOR_INTERRUPT, encoderInterruptCallBack, CHANGE);
}

void encoderInterruptCallBack()
{
  /*Serial.println("motor moved");*/
  if (digitalRead(DC_MOTOR_ENC_A) == digitalRead(DC_MOTOR_ENC_B))
  {
    _encoder_pos++;
  }
  else
  {
    _encoder_pos--;
  }
}

void dcMotorControl(int desired) {
  const double decay_rate = 0.0075;
  swin_acc_err = abs(_encoder_pos - desired) * decay_rate + swin_acc_err * (1.0 - decay_rate);
  //Serial.print("dc");
  //Serial.println(_encoder_pos); 
  if (swin_acc_err > 6)
  {
    while (swin_acc_err > 5)
    {
      swin_acc_err = abs(_encoder_pos - desired) * decay_rate + swin_acc_err * (1.0 - decay_rate);
      Serial.print("dc");
      Serial.println(_encoder_pos);

      pid_time_last = pid_time_cur;
      pid_time_cur = millis();
      err_last = err_p;
      err_p = desired - _encoder_pos;
      
      pos_last = pos_cur;
      pos_cur = _encoder_pos;

      err_i += err_p;
      err_d = (pos_cur - pos_last) * 1000 / (pid_time_cur - pid_time_last);

      double output = err_p * k_p + err_i * k_i + err_d * k_d;

      rot_dir direction = err_p < abs(err_p) ? COUNTERCLOCKWISE : CLOCKWISE;
      output = abs(output);
      output += output_offset;
      output = min(output, 210);

      /*
      Serial.print("pos: ");
      Serial.print(_encoder_pos);
      Serial.print(" err_p: ");
      Serial.print(err_p * k_p);
      Serial.print(" err_i: ");
      Serial.print(err_i * k_i);
      Serial.print(" err_d: ");
      Serial.print(err_d * k_d);
      Serial.print(" pid output: ");
      Serial.print((int)output);
      Serial.print(" direction: ");
      Serial.println(direction);
      */
      
      dcMotorDrive((int)output, direction);
    }

    dcMotorStop();
  }
}

void dcMotorDrive(int dc_speed, rot_dir direction)
{
  motor_on = true;
  /*clockwise maybe */
  /*Serial.println("Writing to motor");*/
  analogWrite(DC_MOTOR_EN, dc_speed);

  if (direction == CLOCKWISE) { digitalWrite(DC_MOTOR_1, LOW); digitalWrite(DC_MOTOR_2, HIGH);
  }
  else {
    digitalWrite(DC_MOTOR_1, HIGH);
    digitalWrite(DC_MOTOR_2, LOW);
  }

}

void dcMotorStop()
{
  motor_on = false;
  analogWrite(DC_MOTOR_EN, LOW);
  /*_encoder_pos = 0;*/
  /*_encoder_pos = 0;*/
  err_p = 0;
  err_i = 0;
  err_d = 0;
}

unsigned int getEncoderPos()
{
  return _encoder_pos;
}

unsigned int getDCVelocity()
{
  return current_vel;
}

void printEncoderPosition()
{
  Serial.print("Encoder Position: ");
  Serial.println(_encoder_pos, DEC);
}

void dcMotorTestFunc()
{
  Serial.println("dc motor test");
  if (_encoder_pos < 1000)
  {
    analogWrite(DC_MOTOR_EN, DC_SPEED_HIGH);
    digitalWrite(DC_MOTOR_1, LOW);
    digitalWrite(DC_MOTOR_2, HIGH);
  }
  else {
    analogWrite(DC_MOTOR_EN, LOW);
  }

  printEncoderPosition();
}

void dcSpeedControl(int desired_vel)
{
  last_encoder_pos = current_encoder_pos;
  cur_vel_time = millis();
  current_encoder_pos = _encoder_pos;
  double timediff = (cur_vel_time- last_vel_time)/1000.0;
  /*Serial.print("timediff: ");*/
  /*Serial.println(timediff);*/

  current_vel = (current_encoder_pos - last_encoder_pos) / (timediff);  // degrees/second

  if (abs(current_vel- desired_vel) > 3)
    dc_ctrl_output-=(current_vel-desired_vel)/4;

  
  dc_ctrl_output=abs(dc_ctrl_output);

  /*Serial.print("desired : ");*/
  /*Serial.print(desired_vel);*/
  /*Serial.print("  current_vel: ");*/
  /*Serial.print(current_vel);*/
  /*Serial.print("  dc_ctrl_output: ");*/
  /*Serial.println(dc_ctrl_output);*/


  last_vel_time = cur_vel_time;
  rot_dir direction_ = (desired_vel < abs(desired_vel)) ? COUNTERCLOCKWISE : CLOCKWISE;
  dcMotorDrive((int)dc_ctrl_output, direction_);
}
