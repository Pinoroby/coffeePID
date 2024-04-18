// scale.cpp

#include "Arduino.h"
#include "scale.h"

// Constructor implementation
Scale::Scale(int pin) {
  analogPin = pin;
  weight = 0;

  min_in = 0;
  min_out = 0;
  max_in = 1023;
  max_out = 5;


  pinMode(analogPin, INPUT);

}

// Function to update weight from analog pin
void Scale::update() {
  // Read analog value from the pin and map it to the weight range (adjust as needed)
  weight = map(analogRead(analogPin), min_in, max_in, min_out, max_out);
}

// Function to get the current weight
int Scale::getWeight() {
  return weight;
}

void Scale::adjustScale(long x_in, long x_out, long y_in, long y_out) {
  min_in = x_in;
  min_out = x_out;
  max_in = y_in;
  max_out = y_out;

}

void Scale::changePin(int pin_num) {

 analogPin = pin_num;

}


int Scale::getPinNum() {
  return analogPin;
}