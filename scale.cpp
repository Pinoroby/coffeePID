// scale.cpp

#include "Arduino.h"
#include "scale.h"

// Constructor implementation
Scale::Scale(int pin, int pin2) {
  analogPin[0] = pin;
  analogPin[1] = pin2;
  weight[0] = 0;
  weight[1] = 0;

  min_in = 0;
  min_out = 1023;
  max_in = 0;
  max_out = 1023;

  for (int i: analogPin)
    pinMode(i, INPUT);
}

// Function to update weight from analog pin
void Scale::update() {
  // Read analog value from the pin and map it to the weight range (adjust as needed)
  int a = 0;
  for (int i: analogPin) {
    //weight[a] = map(analogRead(i), min_in, max_in, min_out, max_out);
    weight[a] = analogRead(i);
    a++;
  }

}

// Function to get the current weight
 void Scale::getWeight() {
  
  for (int i = 0; i < sizeof(analogPin)-2; i++) {
    Serial.print("Weight ");
    Serial.print(analogPin[i]);
    Serial.print(" : ");
    Serial.print(weight[i]);
    Serial.println("");
  }
  Serial.println("-----------");
}

void Scale::adjustScale(long x_in, long x_out, long y_in, long y_out) {
  min_in = x_in;
  min_out = x_out;
  max_in = y_in;
  max_out = y_out;

}

void Scale::changePin(int pin_num, int pin_num2) {

 analogPin[0] = pin_num;
 analogPin[1] = pin_num2;

}


int* Scale::getPinNum() {
  return analogPin;
}