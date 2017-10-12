int sensorPin = A0;

void irSensorSetup() {
    Serial.begin(9600);
}


int irSensorControl() 
{   
  int count = 2000;
  float dis = 0;
  int mV = 0;
  float distance = 0;
  
  //-----coefficients
  float p1, p2, p3;

// ---------Applying a low pass filter
  while (count>0){
    dis= dis + (map(analogRead(sensorPin), 0, 1023, 0, 5000));  // this returns the distance to the object you're measuring
    count--;
  }
  dis = (dis/2000);
  mV = round(dis);

  // Experimentally optained
  p1 = 0.000008487;
  p2 = -0.05665;
  p3 = 106.5;

//-----calculate distance
  distance = ((p1*mV*mV) + (p2*mV) + p3);

//  Serial.print("Mean 200 readings (milli Volts): ");  // returns it to the serial monitor
//  Serial.println(mV);
//
//  Serial.print("Distance Prediction: ");  // returns it to the serial monitor
//  Serial.println(round(distance));
return round(distance);
}
