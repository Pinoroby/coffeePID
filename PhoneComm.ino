#include <Arduino.h>
#include <BluetoothSerial.h>
#include <ArduinoJson.h>


BluetoothSerial SerialBT;

// Define the UART pins
#define RX_PIN 16
#define TX_PIN 17

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32_BT"); // Bluetooth device name

  // Initialize SPIFFS
  if (!SPIFFS.begin(true)) {
    Serial.println("An error occurred while mounting SPIFFS.");
    return;
  }

  // Initialize UART communication with Arduino
  Serial1.begin(9600, SERIAL_8N1, RX_PIN, TX_PIN);
}

void loop() {
  // Read YAML file
  File file = SPIFFS.open("/settings.yaml");
  if (!file) {
    Serial.println("Failed to open config file");
    return;
  }

  // Allocate a buffer to store contents of the file.
  size_t size = file.size();
  std::unique_ptr<char[]> buf(new char[size]);
  file.readBytes(buf.get(), size);
  file.close();

  // Parse YAML content
  DynamicJsonDocument doc(1024);
  DeserializationError error = deserializeJson(doc, buf.get());

  if (error) {
    Serial.print(F("deserializeJson() failed: "));
    Serial.println(error.c_str());
    return;
  }

  // Convert the JSON document to a string
  String json;
  serializeJson(doc, json);

  // Publish JSON over Bluetooth
  SerialBT.println(json);

  // Forward JSON data to Arduino over UART
  Serial1.println(json);

  // Wait before reading the YAML file again
  delay(5000);
}