#include <Arduino.h>
#include <WiFi.h>
#include <WebServer.h>
#include <ArduinoJson.h>

const char *SSID = "Soilit";
const char *PWD = "123454321";

WebServer server(80);

int temperature = 0;
const int lm35Pin = 15;
const int humidityPin = 16;
const int moisturePin = 17;

void connectToWiFi() {
  WiFi.begin(SSID, PWD);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
}

void setup_routing() {
  server.on("/temperature", HTTP_GET, getTemperature);
  server.on("/humidity", HTTP_GET, getHumidity);
  server.on("/moisture", HTTP_GET, getMoisture);

  server.begin();
}

float readTemperature() {
  int sensorValue = analogRead(lm35Pin);
  float milliVolts = (sensorValue / 4095.0) * 3300;
  float temperature = milliVolts / 10;
  
  return temperature;
}

float readHumidity() {
  int sensorValue = analogRead(humidityPin);
  float humidity = (sensorValue / 4095.0) * 100;
  
  return humidity;
}

float readMoisture() {
  int sensorValue = analogRead(moisturePin);
  float moisture = (sensorValue / 4095.0) * 100;
  
  return moisture;
}

void getTemperature() {
  StaticJsonDocument<250> jsonDocument;
  char buffer[250];

  temperature = readTemperature();

  jsonDocument["type"] = "temperature";
  jsonDocument["value"] = temperature;
  jsonDocument["unit"] = "°C";
  serializeJson(jsonDocument, buffer);

  server.send(200, "application/json", buffer);
}

void getHumidity() {
  StaticJsonDocument<250> jsonDocument;
  char buffer[250];

  float humidity = readHumidity();

  jsonDocument["type"] = "humidity";
  jsonDocument["value"] = humidity;
  jsonDocument["unit"] = "%";
  serializeJson(jsonDocument, buffer);

  server.send(200, "application/json", buffer);
}

void getMoisture() {
  StaticJsonDocument<250> jsonDocument;
  char buffer[250];

  float moisture = readMoisture();

  jsonDocument["type"] = "moisture";
  jsonDocument["value"] = moisture;
  jsonDocument["unit"] = "%";
  serializeJson(jsonDocument, buffer);

  server.send(200, "application/json", buffer);
}

void setup() {
  Serial.begin(9600);

  temperature = readTemperature();

  pinMode(lm35Pin, INPUT);
  digitalWrite(lm35Pin, LOW);
  
  pinMode(humidityPin, INPUT);
  digitalWrite(humidityPin, LOW);

  pinMode(moisturePin, INPUT);
  digitalWrite(moisturePin, LOW);

  connectToWiFi();
  setup_routing();
}

void loop() {
  server.handleClient();
}
