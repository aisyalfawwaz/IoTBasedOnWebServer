# Soil Sensor with WiFi Access - README

This repository contains Arduino code for a soil sensor with WiFi access. The sensor measures temperature, humidity, and moisture of the soil and provides the data through a web server over WiFi.

## Hardware Requirements
- Arduino board (e.g., Arduino Uno)
- LM35 temperature sensor
- Humidity sensor (e.g., DHT11 or DHT22)
- Moisture sensor (e.g., analog moisture sensor or soil moisture sensor)
- WiFi module (e.g., ESP8266 or ESP32)

## Software Requirements
- Arduino IDE (https://www.arduino.cc/en/software)
- Libraries: WiFi, WebServer, ArduinoJson (can be installed through Arduino Library Manager)

## Circuit Connection
Connect the sensors to the Arduino board as follows:
- LM35 temperature sensor: Connect VCC to 5V, GND to GND, and Out to pin 15 (can be changed in the code).
- Humidity sensor: Connect VCC to 5V, GND to GND, and Out to pin 16 (can be changed in the code).
- Moisture sensor: Connect VCC to 5V, GND to GND, and Out to pin 17 (can be changed in the code).

## WiFi Configuration
Modify the following variables in the code to match your WiFi network:
```cpp
const char *SSID = "YourWiFiNetworkName";
const char *PWD = "YourWiFiPassword";
```

## Endpoints and Data Format
The sensor exposes three HTTP GET endpoints:
- `/temperature`: Returns the temperature reading in Celsius.
- `/humidity`: Returns the humidity reading as a percentage.
- `/moisture`: Returns the moisture reading as a percentage.

Example response for temperature:
```json
{
  "type": "temperature",
  "value": 25.5,
  "unit": "°C"
}
```

Example response for humidity:
```json
{
  "type": "humidity",
  "value": 45.8,
  "unit": "%"
}
```

Example response for moisture:
```json
{
  "type": "moisture",
  "value": 62.1,
  "unit": "%"
}
```

## Usage
1. Open the code in Arduino IDE.
2. Connect your Arduino board to your computer.
3. Select the appropriate board and port in the Arduino IDE.
4. Compile and upload the code to the Arduino board.
5. Open the Serial Monitor in Arduino IDE to view the serial output.
6. Connect your computer or mobile device to the same WiFi network as configured in the code.
7. Access the sensor data by sending an HTTP GET request to the corresponding endpoints (`/temperature`, `/humidity`, or `/moisture`).
8. The response will contain the sensor data in JSON format.

Note: The sensor readings are updated during the setup phase, not in the main loop. You can modify the code to update the readings periodically if needed.

## License
This code is provided under the [MIT License](LICENSE).

Feel free to modify and adapt the code to meet your specific requirements.

If you have any questions or encounter any issues, please feel free to open an issue in this repository.

Enjoy using the soil sensor with WiFi access!

---

Don't forget to include any additional information or instructions that may be relevant to users of your code or repository.
