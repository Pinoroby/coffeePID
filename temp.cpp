// scale.cpp
#include <max6675.h>

#include "Arduino.h"
#include "temp.h"
#include <SPI.h>



// Constructor implementation
Temp::Temp(int thermoCLK, int thermoCS, int thermoDO) {

  temp = 0;

  thermocouple = new MAX6675(thermoCLK, thermoCS, thermoDO);

}

// Function to update weight from analog pin
void Temp::update() {
  // Read analog value from the pin and map it to the weight range (adjust as needed)
  temp = thermocouple->readCelsius();
}

// Function to get the current weight
int Temp::getTemp() {
  Serial.print("Temperatur: ");
  Serial.print(temp);
  Serial.println("");
  
  return temp;
}