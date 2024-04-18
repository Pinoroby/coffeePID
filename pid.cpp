#include "Arduino.h"
#include "pid.h"

Pid::Pid(long kp, long ki, long kd, long kb, long t) {

  k_p = kp;
  k_i = ki;
  k_d = kd;
  k_b = kb;
  //Ts = t;

  e = 0;
  e_1 = 0;
  e_2 = 0;

  i = 0;
  i_1 = 0;

  a = 0;

  i_min = 0;
  i_max = 100;

};


void Pid::error (long input, long measurement) {
    e = input - measurement;
}

long Pid::limit(long x, long min, long max) {

  if (x <= min)
    x = min;
  else if (x >= max)
    x = max;

  return x;

}

long Pid::hysterese(long x, long e_min, long e_max) {

  if (x <= e_min)
    x = e_min;
  else if (x >= e_max)
    x = e_max;
  else
    x = x;

  return x;

}

long Pid::CalculateOutput(long Ts) {

long il = k_d*e_2 - (k_p*Ts + 2*k_d) * e_1 + (e * a) * k_i * Ts * Ts + e * k_p * Ts + i_1 * Ts;

il = il/Ts;

i = limit(i, i_min, i_max);

a = (i - il)*k_b;

return i;

}

void Pid::setZero() {

  e = 0;
  e_1 = 0;
  e_2 = 0;

  i = 0;
  i_1 = 0;
   
}
