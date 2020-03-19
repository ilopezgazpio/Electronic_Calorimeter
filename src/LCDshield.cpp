#include "Arduino.h"
#include "LCDshield.h"

LCDshield::LCDshield(LiquidCrystal & lcd) 
{  
  // start the library
  _lcd = &lcd;
  
  _lcd->begin(16, 2);
  _lcd->clear();
  
  //String debug = "Initialized the Arduino LCD KeyPad Shield (SKU:DFR0009)";
  //Serial.println(debug);
}




int LCDshield::read_LCD_buttons()
{
  // read the value from the sensor 
  _analog0 = analogRead(0);
 // my buttons when read are centered at these values: 0, 144, 329, 504, 741
 // we add approx 50 to those values and check to see if we are close
 // We make this the 1st option for speed reasons since it will be the most likely result
 // For V1.1 us this threshold

 if (_analog0 > 1000) return _LCDbtnNONE; 
 if (_analog0 < 50)   return _LCDbtnRIGHT;  
 if (_analog0 < 250)  return _LCDbtnUP; 
 if (_analog0 < 450)  return _LCDbtnDOWN; 
 if (_analog0 < 650)  return _LCDbtnLEFT; 
 if (_analog0 < 850)  return _LCDbtnSELECT;  

 // For V1.0 comment the other threshold and use the one below:
/*
 if (_analog0 < 50)   return _LCDbtnRIGHT;  
 if (_analog0 < 195)  return _LCDbtnUP; 
 if (_analog0 < 380)  return _LCDbtnDOWN; 
 if (_analog0 < 555)  return _LCDbtnLEFT; 
 if (_analog0 < 790)  return _LCDbtnSELECT;   
*/

 // when all others fail, return this...
 return _LCDbtnNONE;  
}


void LCDshield::printLCD(float temperature, bool isMotorActive)
{
 // clear screen
 _lcd->clear();
 
 // set cursor and write temperature
 _lcd->setCursor(0,0);
 _lcd->print("Current T: ");
 _lcd->print(temperature);
 
 // set cursor and write motor state
 _lcd->setCursor(0,1);
 isMotorActive ? _lcd->print("M: on ") : _lcd->print("M: off");
 
 // set cursor and display minutes/seconds elapsed since power-up

  int totalSeconds = millis()/1000;
  int minutes = int(totalSeconds / 60);
  int seconds = int(totalSeconds % 60);
  
 _lcd->setCursor(7,1);
 _lcd->print(minutes);
 _lcd->print("m");
 _lcd->print(seconds);
 _lcd->print("s"); 
}


void LCDshield::printMaxMin(float maxTemperature, float minTemperature)
{
 // clear screen
 _lcd->clear();
 
 // set cursor and write temperature
 _lcd->setCursor(0,0);
 _lcd->print("MAX T: ");
 _lcd->print(maxTemperature);
 
 _lcd->setCursor(0,1);
 _lcd->print("MIN T: ");
 _lcd->print(minTemperature);
}

