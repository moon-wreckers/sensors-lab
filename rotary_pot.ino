#include "sensorslab.h"

void rotPotSensorSetup() 
{
  pinMode(ROT_POT_SENSOR_PIN, INPUT);
}

int rotPotSensorControl() 
{
  int rp_sensor_val = analogRead(ROT_POT_SENSOR_PIN);
  int rp_angle  = 0;
  rp_angle = map(rp_sensor_val,0,1020,0,270);;

  Serial.print("rotary potentiometer value: ");
  Serial.println(rp_angle);
  return rp_angle;
}
