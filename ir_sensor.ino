#include "SharpIR.h"

#define model 20150

SharpIR SharpIR(IR_PIN, model);

void irSensorSetup() {
}


int irSensorControl() 
{
  unsigned long pepe1=millis();  // takes the time before the loop on the library begins

  int dis=SharpIR.distance();  // this returns the distance to the object you're measuring


//  Serial.print("Mean distance: ");  // returns it to the serial monitor
//  Serial.println(dis);
return dis;
  
//  unsigned long pepe2=millis()-pepe1;  // the following gives you the time taken to get the measurement
//  Serial.print("Time taken (ms): ");
//  Serial.println(pepe2);
}
