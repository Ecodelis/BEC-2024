#include "CSensor.h"
#include <IRremote.h>

// Constructor
CSensor::CSensor(int recvpin, int trigPin, int echopin) {
    _recvpin = recvpin;
    _trigPin = trigPin;
    _echopin = echopin;
}

// Initialize the sensor pins and IR receiver
void CSensor::initialize() {  
    pinMode(_trigPin, OUTPUT);
    pinMode(_echopin, INPUT);

    IrReceiver.begin(11);    // Start the IR receiver on the specified pin
    Serial.println("IR Receiver Ready");
}

// Check infrared sensor and return the decoded IR command
int CSensor::checkInfraredSensor() {
    if (IrReceiver.decode()) {  // Check if a signal is received
        if (IrReceiver.decodedIRData.decodedRawData != 0xFFFFFFFF) {  // Ignore repeat codes
            Serial.print("Hex Code: 0x");
            Serial.println(IrReceiver.decodedIRData.command, HEX);  // Print the hex code
            int command = IrReceiver.decodedIRData.command;  // Save the decoded command
            IrReceiver.resume();  // Prepare for the next signal
            return command;  // Return the decoded command
        }
        IrReceiver.resume();  // Prepare for the next signal
    }
  
    return 0;  // Return 0 if no signal is received
}
