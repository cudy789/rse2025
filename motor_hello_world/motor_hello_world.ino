//
// Hello world!
// This program will make the disk spin clockwise
// for one second, stop for one second, then repeat, forever.
//

// These are the pins for the motor driver board. There are two 
// pins per motor, one for the direction, and the other for speed.
int diskDirectionPin = 13;
int diskSpeedPin = 12;

// Setup all of our pins to be outputs.
// Everything inside the curly braces ({ ... }) of the setup function runs ONCE.
void setup() {
  pinMode(diskDirectionPin, OUTPUT);
  pinMode(diskSpeedPin, OUTPUT);
}

// Everything inside the curly braces ({ ... }) of the loop function runs FOREVER.
void loop() {

  // Here is our code to make the disk spin. First we need to set the direction 
  // of the motor.
  // HIGH is clockwise, LOW is counterclockwise. Then we set the speed of each motor 
  // from 0 - 255.
  // 0 is stopped, 255 is full speed, 127 is half speed, etc..

  // STOP the motor, doesn't matter which direction
  digitalWrite(diskDirectionPin, HIGH);
  analogWrite(diskSpeedPin, 0);

  // Wait for 1000 milliseconds (1 second)
  delay(1000);

  // START the motor at 50% speed going forwards
  digitalWrite(diskDirectionPin, HIGH);
  analogWrite(diskSpeedPin, 150);

  // Wait for 1000 milliseconds (1 second)
  delay(1000);
}
