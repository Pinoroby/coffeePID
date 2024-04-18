#include "Arduino.h"
#include "yamlReader.h"

// Constructor implementation
YamlReader::YamlReader(str name) {
  
}

// Function to update weight from analog pin
void YamlReader::update() {
  // Read analog value from the pin and map it to the weight range (adjust as needed)
  weight = map(analogRead(analogPin), 0, 1023, 0, 1000);
}

// Function to get the current weight
int YamlReader::getWeight() {
  return weight;
}
