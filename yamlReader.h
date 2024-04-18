#ifndef YAMLREADER_H
#define YAMLREADER_H

#include "Arduino.h"
#include <LittleFS.h>

class YamlReader {
  // Member variables

  i18n_t i18n( &LittleFS );

  int analogPin;
  int weight;

  // Constructor ad member functions declaration
  public:
    YamlReader(int pin); // Constructor with pin parameter
    void update(); // Function to update weight from analog pin
    int getWeight();
};

#endif
