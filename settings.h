#ifndef SETTINGS_H
#define SETTINGS_H

#include "Arduino.h"
#include <ArduinoJson.h>


class Settings {
  // Member variables

  // Constructor ad member functions declaration
  public:
    // PID Settings
    
    JsonDocument doc;

    long k_p = 100;
    long k_d = 0;
    long k_i = 0;
    long k_b = 0;

    // Timing settings

    long T_s = 0;


    // Weight Settings

    int weightPin1 = 2;
    int weightPin2 = 3;

    long weightMin_V = 0;
    long weightMax_V = 10;
    long weightMin_g = 0;
    long WeightMin_g = 100000;

    // Tmperature Settings

    int tempPin1 = 1;

    long tempMin_V = 0;
    long tempMax_V = 10;
    long tempMin_g = 0;
    long tempMax_g = 10000;

    // json data package settings


    void update();
    String createString();

};

#endif
