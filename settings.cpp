#include "Arduino.h"
#include "settings.h"

// Constructor implementation
Settings::Settings() {
  
}

// Function to update weight from analog pin
void Settings::update() {
  // Read analog value from the pin and map it to the weight range (adjust as needed)
  weight = map(analogRead(analogPin), 0, 1023, 0, 1000);
}


