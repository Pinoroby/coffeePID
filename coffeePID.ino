

#include <max6675.h>

#include <ArduinoJson.h>


#include <U8g2lib.h>
#include <SPI.h>

#include "pid.h"
#include "scale.h"
#include "temp.h"
//#include "settings.h"


const int scalePin = A0;
const int scalePin2 = A1;
const byte tempPin = 10;
const long time = 1;
const long k_p = 200;
const long k_i = 0;
const long k_d = 0;

unsigned long previousMillis = 0;
const long interval = 1000;

int a = 0;



Scale scale = Scale(scalePin, scalePin2);
Temp temp = Temp(6,5,4);
Pid pid = Pid(200, 0, 0, 0, 1);

void setup() {
 Serial.begin(115200);
 SPI.begin();

}

void loop() {

int weight [2] = {0 , 0};

unsigned long currentMillis = millis();    

long Ts = currentMillis - previousMillis;

if (Ts >= interval) {
// Update the weight
    
    scale.update();
    temp.update();
    //pid.error(100, scale.getWeight());
    pid.CalculateOutput(Ts/1000);
    scale.getWeight();
    temp.getTemp();

    //Serial.println(scale.getWeight());
    previousMillis = currentMillis;
    a++;}
    
}