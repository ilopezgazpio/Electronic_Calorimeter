/*
  Main file to handle the electronic calorimeter project
  
  To make the project work the following steps must be done:
  
  1) install the termometer
    a) import the following libraries to arduino IDE:
      - DallasTemperature
      - OneWire
      
    b) install the circuit as described in the github readme
       Make sure that the input pin in the arduino is the one used in the code to initialize the temperatureSensor class
       Sensor yellow and red cables are the ones going to ground
       Sensor green cable is the one going to the input arduino pin
       
  2) install the motor 
    a) install the circuit as shown in the github readme
    Make sure that the input pin in the arduino is the one used in the code to initialize the motor class
    
    
  3) install the Arduino LCD KeyPad Shield (SKU:DFR0009)
    a) install the circuit as shown below:
    LCD analog 0 -> Arduino analog 0
    LCD 5 volt -> Arduino 5 volt
    LCD ground -> Arduino ground
    LCD Reset -> Arduino reset
    LCD digital 4 (starting from 0 it is the fourth pin on the front-right side of the lcd) -> Arduino digital 4
    LCD digital 5 -> Arduino digital 5
    LCD digital 6 -> Arduino digital 6
    LCD digital 7 -> Arduino digital 7
    LCD digital 8 -> Arduino digital 8
    LCD digital 9 -> Arduino digital 9
    LCD digital 10 -> Arduino digital 10 
*/

#include "temperatureSensor.h"
#include "motor.h"
#include "LCDshield.h"
#include <OneWire.h>
#include <DallasTemperature.h>
#include <LiquidCrystal.h>


#define tempSensorPin 2
#define motorPin 3
#define motorSpeed 220


#define LCDdigital4 4
#define LCDdigital5 5
#define LCDdigital6 6
#define LCDdigital7 7
#define LCDdigital8 8
#define LCDdigital9 9

#define LCDbtnRIGHT  0
#define LCDbtnUP     1
#define LCDbtnDOWN   2
#define LCDbtnLEFT   3
#define LCDbtnSELECT 4
#define LCDbtnNONE   5


LiquidCrystal myLCD(LCDdigital8, LCDdigital9, LCDdigital4, LCDdigital5, LCDdigital6, LCDdigital7);
temperatureSensor *myTempSensor;
motor *myMotor;
LCDshield *myLCDshield;

float readTemp;

void setup() 
{
  // open the serial port at 9600 bps:Serial.begin(9600);
  Serial.begin(9600);
  
  // instantiate classes
  myTempSensor = new temperatureSensor(tempSensorPin);
  myMotor = new motor(motorPin, motorSpeed);
  myLCDshield = new LCDshield(myLCD);
}

void loop() 
{
  readTemp = myTempSensor->getTemperature();
  Serial.println(readTemp);   
  
  // depending on which button was pushed, we perform an action
  switch (myLCDshield->read_LCD_buttons())              
  {
     case LCDbtnRIGHT: {
       break;
     }
     case LCDbtnLEFT: {
       break;
     }
     case LCDbtnUP: {
       if (myMotor->isMotorActive() == false) {
         myMotor->activateMotor();
       }
       break;
     }
     case LCDbtnDOWN: {
       if (myMotor->isMotorActive() == true) {
         myMotor->desactivateMotor();
       }
       break;
     }
     case LCDbtnSELECT: {
       myLCDshield->printMaxMin(myTempSensor->getMaxTemperature(), myTempSensor->getMinTemperature());
       // stay while button still pressed
       while (myLCDshield->read_LCD_buttons() == LCDbtnSELECT){delay(1000);};
       break;
     }
     default: 
       break;
   }
  
  // print data on LCD 
  myLCDshield->printLCD(readTemp, myMotor->isMotorActive());
  delay(1000);
}
