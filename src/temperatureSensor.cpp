#include "Arduino.h"
#include "temperatureSensor.h"


temperatureSensor::temperatureSensor(int pinInput)
{
  // set pin to input
  pinMode(pinInput, INPUT);
  _pinInput = pinInput;
  
  // instantiate wire object
  wire = new OneWire(_pinInput);
  
  // instantiate sensor object
  sensor = new DallasTemperature(wire);
  
  // initialize temperature sensor
  sensor->begin();
  
  // initialize vars
  _maxTemperature = -126.0;
  _minTemperature = 126.0;
  
  // print debug
  // String debug = "Initialized the temperature sensor DS18B20 on arduino input pin " + String(pinInput);
  // Serial.println(debug);
}



float temperatureSensor::getTemperature()
{
  sensor->requestTemperatures();
  float currentTemperature = sensor->getTempCByIndex(0);
  
  // update maximum/minimum temperature
  if (currentTemperature > _maxTemperature)
  {
      _maxTemperature = currentTemperature;
  }
  
  if (currentTemperature < _minTemperature && currentTemperature > -126 )
  {
     _minTemperature = currentTemperature; 
  }
  
  return float(   (  (int)  ( currentTemperature * 100 )   )    /    100.0     );
}


float temperatureSensor::getMaxTemperature()
{
  return float(   (  (int)  ( _maxTemperature * 100 )   )    /    100.0     );
}


float temperatureSensor::getMinTemperature()
{
  return float(   (  (int)  ( _minTemperature * 100 )   )    /    100.0     );
}
