
void flexSensorSetup() 
{
  pinMode(FLEX_SENSOR_PIN, INPUT);
}

int flexSensorControl() 
{
  int flex_sensor_val = analogRead(FLEX_SENSOR_PIN);
  return flex_sensor_val;
  /*Serial.print("Flex sensor value: ");*/
  /*Serial.println(flex_sensor_val);*/
}


