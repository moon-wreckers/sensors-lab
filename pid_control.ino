double err_p, err_i, err_d, err_last = 0;
unsigned long lastTick;
int desired, current;
bool drive_vel, drive_position;
unsigned long last_time;

const double k_p = 0.8;
const double k_i = 0.1;
const double k_d = 0.1;

void pidControl()
{
Serial.println("pid control loop");
unsigned long time = millis();
unsigned long timestep = time-last_time;
current = getEncoderPos();
err_p = desired - current;
err_i += err_p;
err_d += (err_p-err_last)/timestep;

Serial.println("pid output: ");
double output = err_p*k_p+err_i*k_i+err_d*k_d;
Serial.println(output);

dcMotorControl((int)output, CLOCKWISE);
err_last = err_p;
last_time = time;

/*return output;*/
}


void setDesiredPosition(int desired_pos)
{
   desired = getEncoderPos()+desired_pos;
}
