#include "sensorslab.h"

void slotSensorSetup() 
{
  
}

//--------------------------------------------------------

int slotSensorControl() 
{
  int sensor_val = analogRead(SLOT_PIN);
  /*Serial.println(sensor_val);*/
  return sensor_val;
}
