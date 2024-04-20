#include "Arduino.h"
#include "settings.h"

#include <ArduinoJson.h>

// Constructor implementation

// Function to update weight from analog pin
void Settings::update() {
  // Read analog value from the pin and map it to the weight range (adjust as needed)
  
}

String Settings::createString() {

  // Create settings page for PID Control
  doc["k_p"] = k_p;
  doc["k_d"] = k_d;
  doc["k_i"] = k_i;
  doc["k_b"] = k_b;

  // Timing setting of the controller

  doc["T_s"] = T_s;

  // Weight Settings

  doc["weightPin1"] = weightPin1;
  doc["WeightPin2"] = weightPin2;
  doc["WeightMin_V"] = weightMin_V;
  doc["WeightMax_V"] = weightMax_V;
  doc["WeightMin_g"] = weightMin_g;
  doc["WeightMin_g"] = WeightMin_g;
    
  // Temperature Settings

  doc["tempPin1"] = tempPin1;
  
  doc["tempMin_V"] = tempMin_V;
  doc["tempMax_V"] = tempMax_V;
  doc["tempMin_g"] = tempMin_g;
  doc["tempMax_g"] = tempMax_g;  

}






