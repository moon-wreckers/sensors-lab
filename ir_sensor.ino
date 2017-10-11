#include "SharpIR.h"

#define ir A0
#define model 20150

SharpIR SharpIR(ir, model);

void irSensorSetup() {
    Serial.begin(9600);
}


int irSensorControl() 
{
}
