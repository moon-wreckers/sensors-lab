#include "sensorslab.h"

void slotSensorSetup() 
{
  
}

//--------------------------------------------------------

void slotSensorControl() 
{
  int sensor_val = analogRead(SLOT_PIN);
  Serial.println(sensor_val);
}
