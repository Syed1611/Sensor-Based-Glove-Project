// Define the pin where the sensor is connected
int sensorPin = A0; // A0 is an analog pin on the Arduino

// Define the pin where the buzzer is connected
int buzzerPin = 9;  // Digital pin 9 on the Arduino

// Define thresholds for different distances
int closeThreshold = 200;
int mediumThreshold = 500;

// Function to initialize the setup
void setup() {
    // Initialize the serial communication at a baud rate of 9600
    Serial.begin(9600);
    
    // Set the buzzer pin as an output
    pinMode(buzzerPin, OUTPUT);
}

// Function to read the sensor value
int readSensor() {
    return analogRead(sensorPin);
}

// Function to control the buzzer based on the sensor value
void controlBuzzer(int sensorValue) {
    if (sensorValue < closeThreshold) {
        // If the sensor value is less than closeThreshold, the object is very close
        // Produce a fast beeping sound
        tone(buzzerPin, 1000); // Generate a tone of 1000 Hz
        delay(100);            // Beep duration of 100 milliseconds
        noTone(buzzerPin);     // Stop the tone
        delay(100);            // Pause duration of 100 milliseconds
    } else if (sensorValue < mediumThreshold) {
        // If the sensor value is between closeThreshold and mediumThreshold, the object is at a medium distance
        // Produce a medium-speed beeping sound
        tone(buzzerPin, 1000); // Generate a tone of 1000 Hz
        delay(300);            // Beep duration of 300 milliseconds
        noTone(buzzerPin);     // Stop the tone
        delay(300);            // Pause duration of 300 milliseconds
    } else {
        // If the sensor value is greater than mediumThreshold, the object is far away
        // Produce a slow beeping sound
        tone(buzzerPin, 1000); // Generate a tone of 1000 Hz
        delay(500);            // Beep duration of 500 milliseconds
        noTone(buzzerPin);     // Stop the tone
        delay(500);            // Pause duration of 500 milliseconds
    }
}

// Main loop function
void loop() {
    // Read the value from the sensor
    int sensorValue = readSensor();
    
    // Print the sensor value to the serial monitor
    Serial.println(sensorValue);

    // Control the buzzer based on the sensor value
    controlBuzzer(sensorValue);

    // Add a small delay to avoid rapid looping
    delay(100);
}
