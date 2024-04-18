// scale.cpp

#include "Arduino.h"
#include "temp.h"

// Constructor implementation
Temp::Temp(int pin) {
  analogPin = pin;
  weight = 0;
  pinMode(analogPin, INPUT);
}

// Function to update weight from analog pin
void Temp::update() {
  // Read analog value from the pin and map it to the weight range (adjust as needed)
  weight = map(analogRead(analogPin), 0, 1023, 0, 1000);
}

// Function to get the current weight
int Temp::getWeight() {
  return weight;
}