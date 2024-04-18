#include <U8g2lib.h>
#include <SPI.h> 
#include <LittleFS.h>
#include <ArduinoYaml.h>

#include "pid.h"
#include "scale.h"
#include "temp.h"
#include "yamlReader.h"

i18n_t i18n( &LittleFS );

const int scalePin = A0;
const int tempPin = A1;
const long time = 1;
const long k_p = 200;
const long k_i = 0;
const long k_d = 0;

unsigned long previousMillis = 0;
const long interval = 1000;

int a = 0;

Scale scale = Scale(scalePin);
Temp temp = Temp(tempPin);
Pid pid = Pid(200, 0, 0, 0, 1);

void setup() {
 Serial.begin(115200);

 LittleFS.begin();

 i18n.setLocale("settings");
}

void loop() {


unsigned long currentMillis = millis();    

long Ts = currentMillis - previousMillis;

if (Ts >= interval) {
// Update the weight
    
    scale.update();
    temp.update();
    pid.error(100, scale.getWeight());
    pid.CalculateOutput(Ts/1000);
    Serial.println(Hello);
    previousMillis = currentMillis;
    a++;}
    
}