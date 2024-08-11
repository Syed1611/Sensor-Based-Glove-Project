Overview
This project involves creating a hand glove equipped with a sensor that detects objects and produces different sounds based on the distance from the object. The sensor is attached to the center of the palm and connected to an Arduino board. This project is designed to help beginners understand the basics of sensor integration with Arduino.

Components
Arduino Uno
Ultrasonic Sensor (HC-SR04)
Hand Glove
Jumper Wires
Breadboard 
Buzzer or Speaker
Resistors 

Connections
Ultrasonic Sensor (HC-SR04) Connections:
VCC: Connect to the 5V pin on the Arduino.
GND: Connect to the GND pin on the Arduino.
Trig: Connect to digital pin 9 on the Arduino.
Echo: Connect to digital pin 10 on the Arduino.

Buzzer/Speaker Connections:
Positive Lead: Connect to digital pin 11 on the Arduino.
Negative Lead: Connect to GND on the Arduino.

How It Works
Sensor Activation: The ultrasonic sensor sends out a pulse and waits for it to bounce back from an object.
Distance Calculation: The Arduino calculates the distance based on the time taken for the pulse to return.
Sound Output: Depending on the distance, the Arduino triggers the buzzer to produce different sounds.

Usage
Wear the glove and move your hand towards an object.
The buzzer will produce different sounds based on the distance from the object.