import serial  # Import the pyserial library to handle serial communication
import time    # Import the time library to add delays

# Function to set up the serial connection to the Arduino
def setup_serial_connection(port, baud_rate):
    return serial.Serial(port, baud_rate)

# Function to read sensor data from the Arduino
def read_sensor_data(ser):
    if ser.in_waiting > 0:
        data = ser.readline().decode('utf-8').rstrip()
        return data
    return None

# Function to continuously read and print sensor data
def read_sensor(ser):
    while True:
        data = read_sensor_data(ser)
        if data:
            print(f"Sensor data: {data}")
        time.sleep(1)

if __name__ == "__main__":
    # Set up the serial connection
    ser = setup_serial_connection('COM3', 9600)  # Replace 'COM3' with your Arduino port
    
    # Start reading sensor data
    read_sensor(ser)
