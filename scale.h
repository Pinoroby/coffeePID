// scale.h
#ifndef SCALE_H
#define SCALE_H

class Scale {
  // Member variables
  int analogPin[2];
  int weight[2];
  int weight2;
  long min_in;
  long min_out;
  long max_in;
  long max_out;


  // Constructor and member functions declaration
  public:
    Scale(int pin, int pin2); // Constructor with pin parameter
    void update(); // Function to update weight from analog pin
    void getWeight(); // Function to read the weight as value
    void adjustScale(long x_in, long x_out, long y_in, long y_out); // function to adjust scaling in function
    void changePin(int pin_num, int pin_num2); // Change the pin after creating the function
    int* Scale::getPinNum();
};

#endif