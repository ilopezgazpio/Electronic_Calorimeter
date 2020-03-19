/*
  temperatureSensor.h - Library for handling the DS18B20 temperature sensor.  
*/

#ifndef temperatureSensor_h
#define temperatureSensor_h

#include <Arduino.h>
#include <OneWire.h>
#include <DallasTemperature.h>

class temperatureSensor
{
  public:
    temperatureSensor(int pinInput);
    float getTemperature();
    float getMaxTemperature();
    float getMinTemperature();
    
  private:
    int _pinInput;
    float _maxTemperature;
    float _minTemperature;
    OneWire *wire;
    DallasTemperature *sensor;
};

#endif
