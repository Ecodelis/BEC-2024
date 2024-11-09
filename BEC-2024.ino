
#include "CSensor.h"


CSensor sensor(11, 9, 10,2,13);


void setup() {
            // Initialize serial communication
  Serial.begin(9600);  

  sensor.initialize();
}

void loop() {
  //sensor.checkInfraredSensor();

  // sensor.checkUltrasonicDistance();
  sensor.checkHutomwua();
  delay(500);
}



