#include "sensorslab.h"

void slotSensorSetup() 
{
pinMode(SLOT_PIN, INPUT);      // sets the digital pin<Plug>yankstack_after_paste 7 as input

}

//--------------------------------------------------------

void slotSensorControl() 
{
int val = digitalRead(SLOT_PIN);
Serial.println(val);
 
}
