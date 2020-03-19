#include "Arduino.h"
#include "motor.h"


motor::motor(int pinOutput, int motorSpeed)
{
  //set motor speed
  _motorSpeed = motorSpeed;
  
  // set pin to output
  pinMode(pinOutput, OUTPUT);
  _pinOutput = pinOutput;  
  
  // initialize vars
  _motorActive= false;
  
  // print debug
  // String debug = "Initialized the milk frother motor on arduino output pin " + String(pinOutput) + " with speed " + String(_motorSpeed);
  //Serial.println(debug);
}

void motor::activateMotor()
{
  //analogWrite(_pinOutput, _motorSpeed);
  digitalWrite(_pinOutput, HIGH);
  _motorActive = true;
}



void motor::desactivateMotor()
{
  //analogWrite(_pinOutput, 0);
  digitalWrite(_pinOutput, LOW);
  _motorActive = false;
}


bool motor::isMotorActive()
{
  return _motorActive;
}
