EMG-Controlled Robotic Arm

This project demonstrates a robotic arm controlled by EMG (Electromyography) signals using an Arduino microcontroller. The system captures muscle activity from the human arm and translates it into servo motor movements, enabling intuitive and natural control of a robotic arm.

🔹 Features

EMG sensor integration for muscle activity detection.

Control of 5 servo motors (one for each finger).

Arduino Uno/Nano-based signal processing.

Real-time movement replication of human hand gestures.

Low-cost and DIY-friendly design.

🔹 Hardware Requirements

Arduino Uno / Arduino Nano

EMG Sensor Module

5 × SG90 Servo Motors (or similar)

Breadboard and jumper wires

Power supply (5V, ≥2A recommended)

🔹 Software Requirements

Arduino IDE

Servo library (default with Arduino IDE)

Optional: Python (for future data visualization/ROS2 integration)

🔹 Circuit Overview

EMG sensor signal → Arduino analog input.

Arduino processes signal → Maps to servo motor PWM output.

Servo motors move according to muscle activity.

(Add wiring diagram image here if available)

🔹 Code Example
#include <Servo.h>

Servo finger1, finger2, finger3, finger4, finger5;

int emgPin = A0;  
int val = 0;

void setup() {
  finger1.attach(3);
  finger2.attach(5);
  finger3.attach(6);
  finger4.attach(9);
  finger5.attach(10);
  Serial.begin(9600);
}

void loop() {
  val = analogRead(emgPin);  
  int angle = map(val, 0, 1023, 0, 180);  

  finger1.write(angle);
  finger2.write(angle);
  finger3.write(angle);
  finger4.write(angle);
  finger5.write(angle);

  Serial.println(val);
  delay(20);
}

🔹 Future Improvements

ROS2 and Gazebo simulation.

Machine learning for gesture recognition.

Wireless (Bluetooth/Wi-Fi) control.

3D-printed robotic arm structure.

🔹 Applications

Prosthetics and rehabilitation

Robotics research

Human-computer interaction

Gesture-controlled devices

🔹 Author

👤 Dibyendu Pradhan

Robotics & Automation Student

Passionate about AI, Electronics, and Robotics

https://in.linkedin.com/in/dibyendu-pradhan-263b67302
https://dibyendup.netlify.app

