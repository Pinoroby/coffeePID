// scale.h
#ifndef PID_H
#define PID_H


class Pid {
  // Member variables
  long k_p;
  long k_i;
  long k_d;
  long k_b;
  long a;

  long e, e_1, e_2;
  long i, i_1;

  long i_min, i_max;

  // Constructor and member functions declaration
  public:
    Pid(long kp, long ki, long kd, long kb, long t); // Constructor
    void error(long input, long measurement); // calculate error
    long limit(long x, long min, long max); // Function to read the weight as value
    long CalculateOutput(long Ts); // function to adjust scaling in function
    long hysterese(long x, long e_min, long e_max); // Change the pin after creating the function
    void setZero();
};



#endif
