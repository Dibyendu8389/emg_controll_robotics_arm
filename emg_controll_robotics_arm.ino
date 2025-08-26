#include <Servo.h>

// Define servo objects for 5 fingers
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;

// EMG sensor pin
const int emgPin = A0;

// Servo angle
int activeAngle = 90;   // Finger bent position
int restAngle   = 0;    // Finger rest position

// Threshold for muscle detection (adjust if needed)
int threshold = 60;  // If EMG value > 12, finger will bend

void setup() {
  Serial.begin(9600);

  // Attach servos to PWM pins
  servo1.attach(3);
  servo2.attach(5);
  servo3.attach(6);
  servo4.attach(9);
  servo5.attach(10);

  // Set all to rest initially
  setAllServos(restAngle);
}

void loop() {
  int emgValue = analogRead(emgPin);
  Serial.println(emgValue);  // For monitoring via Serial Plotter

  if (emgValue > threshold) {
    // Muscle detected: close fingers
    setAllServos(activeAngle);
  } else {
    // No muscle: open fingers
    setAllServos(restAngle);
  }

  delay(100);  // Adjust for responsiveness
}

// Function to set all servos together
void setAllServos(int angle) {
  servo1.write(angle);
  servo2.write(angle);
  servo3.write(angle);
  servo4.write(angle);
  servo5.write(angle);
}
