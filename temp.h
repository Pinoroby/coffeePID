// scale.h
#ifndef TEMP_H
#define TEMP_H

class Temp {
  // Member variables
  byte pin;
  float temp;
  byte addressToRead;

  MAX6675 *thermocouple;

  // Constructor ad member functions declaration
  public:
    Temp(int thermoCLK, int thermoCS, int thermoDO); // Constructor with pin parameter
    void update(); // Function to update weight from analog pin
    int getTemp();
};

#endif
