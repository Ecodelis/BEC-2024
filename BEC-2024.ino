#include "Cpins.h"
#include "CSensor.h"


CSensor sensor(11, 9, 10);


void setup() {
            // Initialize serial communication
  Serial.begin(9600);  

  sensor.initialize();
}

void loop() {
  sensor.checkInfraredSensor();
}



