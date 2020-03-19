/*
  motor.h - Library for handling the milk frother motor.  
*/

#ifndef motor_h
#define motor_h

#include <Arduino.h>

class motor
{
  public:
    motor(int pinOutput, int motorSpeed);
    void activateMotor();
    void desactivateMotor();
    bool isMotorActive();
    
  private:
    int _pinOutput;
    int _motorSpeed;
    bool _motorActive;
};

#endif
