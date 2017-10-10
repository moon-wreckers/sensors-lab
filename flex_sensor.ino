#define FLEX_SENSOR_PIN A5

void flexSensorSetup() 
{
  pinMode(FLEX_SENSOR_PIN, INPUT);
}

void flexSensorControl() 
{
  int flex_sensor_val = analogRead(FLEX_SENSOR_PIN);
  Serial.print("Flex sensor value: ");
  Serial.println(flex_sensor_val);
}


