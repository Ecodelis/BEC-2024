#ifndef CSENSOR_H
#define CSENSOR_H

#include <Arduino.h>

class CSensor {
  private:
    int _recvpin, _trigPin, _echopin;

  public:
    // Constructor
    CSensor(int recvpin, int trigPin, int echopin);

    // Public methods
    int checkInfraredSensor();
    void initialize();
};

#endif
