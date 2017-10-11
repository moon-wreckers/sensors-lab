void setup()
{
  Serial.begin(9600);
}

void loop()
{
int val=analogRead(A0); // read the sensor
Serial.println(exp(8.5841-log(val)));
delay(999);
}
