/*
  LCDshield.h - Library for handling the Arduino LCD KeyPad Shield (SKU:DFR0009).  
*/

#ifndef LCDshield_h
#define LCDshield_h

#include <Arduino.h>
#include <LiquidCrystal.h>


class LCDshield
{
  public:
    LCDshield(LiquidCrystal & lcd);
    int read_LCD_buttons();
    void printLCD(float temperature, bool isMotorActive);
    void printMaxMin(float maxTemperature, float minTemperature);
    
  private:
    LiquidCrystal * _lcd; 
    int _analog0;
    int _LCDbtnRIGHT = 0;
    int _LCDbtnUP = 1;
    int _LCDbtnDOWN = 2;
    int _LCDbtnLEFT = 3;
    int _LCDbtnSELECT = 4;
    int _LCDbtnNONE = 5;
};

#endif
