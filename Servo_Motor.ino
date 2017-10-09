
#define SERVO_PIN  8

int lenMicroSecondsOfPeriod = 25 * 1000;
int lenMicroSecondsOfPulse = 0;
int lenMicroSecondsOfPulseStart = 0.575 * 1000;
int lenMicroSecondsOfPulseEnd = 2.350 * 1000;
int lenMicroSecondsOfPulseStep = 0.01 * 1000;

void setup() 
{
  pinMode(SERVO_PIN, OUTPUT);
  Serial.begin(9600);
  lenMicroSecondsOfPulse = lenMicroSecondsOfPulseStart;
}

void loop() 
{
  while (lenMicroSecondsOfPulse < lenMicroSecondsOfPulseEnd)
  {
    // Turn voltage high to start the period and pulse
    digitalWrite(SERVO_PIN, HIGH);

    // Delay for the length of the pulse
    delayMicroseconds(lenMicroSecondsOfPulse);

    // Turn the voltage low for the remainder of the pulse
    digitalWrite(SERVO_PIN, LOW);

    // Delay this loop for the remainder of the period so we don't
    // send the next signal too soon or too late
    delayMicroseconds(lenMicroSecondsOfPeriod - lenMicroSecondsOfPulse); 

    // Increment our pulse
    lenMicroSecondsOfPulse += lenMicroSecondsOfPulseStep;
    
    Serial.print("lenMicroSecondsOfPulse: ");
    Serial.println(lenMicroSecondsOfPulse);
 }
 
 Serial.println("Done!");
 Serial.println();
 
 while(1);

}
