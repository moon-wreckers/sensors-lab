const int stepPin = 13;
const int dirPin = 12;
const int enblPin = 8;

void setup() {
  // put your setup code here, to run once:
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(enblPin, OUTPUT);
}

void loop() {
//  digitalWrite(enblPin, HIGH);
  // Enables the motor to move in some direction
  digitalWrite(dirPin, HIGH);
  // Step 200 times to make one full rotation (MS1, MS2, MS3 - LOW)
  for(int x = 0; x <200; x++){
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(1000);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(1000);
  }
  delay(2000); //one second delay

  digitalWrite(dirPin, LOW); // change te direction of rotation
  //make 2 full rotations 
  for(int x = 0; x <400; x++){
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(1000);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(1000);
  }
  delay(1000);

}
