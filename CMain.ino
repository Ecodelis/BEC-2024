#include "CMotor.h"
#include "CServo.h"


CMotor _motor(2, 3, 4, 5, A0, A1);
CServo _servo(9);

void setup() {
  Serial.begin(9600);
  _motor.setSpeed(150);  // Set initial speed
  _servo.attach();
}

void loop() {
    if (Serial.available() > 0) {
        char input = Serial.read();  // Read a single character
        //int input_num = input.toInt();
        //Serial.print("You entered: ");
        //Serial.println(input);

        if (input == 'w' || input == 'W') {
            _motor.forward();
        } else if (input == 's' || input == 'S') {
            _motor.backward();
        } else if (input == 'a' || input == 'A') {
            _motor.left();
        } else if (input == 'd' || input == 'D') {
            _motor.right();
            }
        else {
            _motor.stop();
        }
    }
}
