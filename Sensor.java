import com.fazecast.jSerialComm.SerialPort; // Import the jSerialComm library for serial communication

public class SensorReader {

    // Function to set up the serial connection
    public static SerialPort setupSerialConnection() {
        SerialPort comPort = SerialPort.getCommPorts()[0]; // Adjust the port index as needed
        comPort.setBaudRate(9600);
        comPort.openPort();
        return comPort;
    }

    // Function to read sensor data from the Arduino
    public static String readSensorData(SerialPort comPort) {
        if (comPort.bytesAvailable() > 0) {
            byte[] readBuffer = new byte[comPort.bytesAvailable()];
            int numRead = comPort.readBytes(readBuffer, readBuffer.length);
            return new String(readBuffer, 0, numRead);
        }
        return null;
    }

    // Main function to continuously read and print sensor data
    public static void main(String[] args) {
        SerialPort comPort = setupSerialConnection();

        while (true) {
            String data = readSensorData(comPort);
            if (data != null) {
                System.out.println("Sensor data: " + data);
            }
        }
    }
}
