#include <U8g2lib.h>
#include <SPI.h>

#include "pid.h"
#include "scale.h"
#include "temp.h"
//#include "settings.h"


const int scalePin = A1;
const int scalePin2 = A2;
const int tempPin = A0;
const long time = 1;
const long k_p = 200;
const long k_i = 0;
const long k_d = 0;

unsigned long previousMillis = 0;
const long interval = 1000;

int a = 0;



Scale scale = Scale(scalePin, scalePin2);
Temp temp = Temp(tempPin);
Pid pid = Pid(200, 0, 0, 0, 1);

void setup() {
 Serial.begin(115200);

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

    //Serial.println(scale.getWeight());
    previousMillis = currentMillis;
    a++;}
    
}