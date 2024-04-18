// scale.h
#ifndef TEMP_H
#define TEMP_H

class Temp {
  // Member variables
  int analogPin;
  int weight;

  // Constructor ad member functions declaration
  public:
    Temp(int pin); // Constructor with pin parameter
    void update(); // Function to update weight from analog pin
    int getWeight();
};

#endif
