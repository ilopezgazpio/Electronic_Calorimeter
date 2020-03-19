# Electronic_Calorimeter
Supplementing Information Available for the article **"Construction of an electronic calorimeter for laboratory instrumentation practices"**.
This guide will lead you through the process of construction of the device described in the paper.
This utility aims to mix liquids and control the mixing temperature over time.
We estimate the time to build the device is approximately 2.5 hours if you have some minimal experience with Arduino.
If you are completely new to Arduino please consider doing a tutorial first here: [Arduino Official](https://www.arduino.cc/)

The project is based on an ensemble of Arduino modules, such as: a submersible temperature sensor, to get the mixing temperature with decimal precision; a rebuild of a milk steerer (4.5 volt motor), to help mix liquids inside a thermos; and a liquid crystal display (LCD) as a user interface to easily read experiment results and control the activation of the motor by simply pushing buttons attached to it.

If you use this software for academic research please cite the described paper:
```
TBA
```
## Requirements
The project is based on the following requirements:

1. A **submersible temperature sensor** to read the temperature with decimal precision (SKU: DS18B20)
2. A **4.5 volt motor** extracted from a milk vaporizer, but any 4.5 motor will do the work. We just need a motor that enables the agitation of liquids inside a thermally insulated vessel 
3. A **thermally insulated vessel**
4. A **liquid crystal display (LCD)**, used as user interface to easily collect the results of the experiments and to control the activation of the engine. (LCD KeyPad Shield SKU:DFR0009)
5. The official **Arduino IDE** (Official Arduino programming application, can be downloaded from official site here:  [Arduino Official](https://www.arduino.cc/) )
6. An **Arduino board** with corresponding power cable and USB cable (We tested with Arduino Uno Rev3 board)
7. An external **4.5 volt battery** (to be used in the motor circuit)
8. The following **resistors**: 330 ohm resistor and a 4700 ohm resistor to be used in the motor and temperature sensor circuits respectively
9. A P2N2222AG **NPN transistor** (to be used in the motor circuit)
10. A 1N4148 **Diode** (to be used in the motor circuit)
11. An **Electronic prototyping miniboard** is optional but surely will help build the circuit
13. Prototyping **cables**, if possible with red and blue/brown colors to help check correctness of circuits
14. If you want the project to run standalone from the computer you will need a **9 volt battery** for the Arduino board (instead of having it plugged to the CPU through USB cable)

Once all the components have been collected we can safely start the assembly of the electronic calorimeter.
It should be noted that all parts of the built instrument were easily obtained for under 25€.

## Assembly instructions
The instructions to assemble the project are divided in 5 steps

1. Build the electronic circuit for the LCD screen
2. Build the electronic circuit for the 4.5 volt motor
3. Build the electronic circuit for the temperature sensor
4. Download the code provided in this repository (under src folder) and load it into an Arduino board
5. Run the project and control the temperature and motor activation through the LCD screen

### 1. LCD Screen set-up
There is a huge bunch of alternatives to connect a LCD display to the Arduino, we recommend making the following connections:
1. (From) LCD analog 0 -> (into) Arduino Analog 0
2. LCD 5 volt     ->   Arduino 5 volt
3. LCD ground     ->   Arduino ground
4. LCD Reset      ->   Arduino reset
4. LCD digital 4* ->   Arduino digital 4 
5. LCD digital 5  ->   Arduino digital 5
6. LCD digital 6  ->   Arduino digital 6
7. LCD digital 7  ->   Arduino digital 7
8. LCD digital 8  ->   Arduino digital 8
8. LCD digital 9  ->   Arduino digital 9
9. LCD digital 10 ->   Arduino digital 10 

*Starting from 0 it is the fourth pin on the front-right side of the LCD

Note that you could just plug-in the LCD screen as a shield directly into the Arduino board, but in our case we wanted to have the LCD screen distant to the board.

### 2. Motor set-up
The electronic schematics neccesary to build this circuit are shown in the diagram below
[TODO]  motorCircuit.jpg

Just make sure of the following key aspects:
1. **Input pin** in the Arduino is the one used in code to initialize the motor class, for the default case, it is **pin number 3** 

### 3. Temperature sensor set-up
The electronic schematics neccesary to build this circuit are shown in the diagram below 
[TODO] temperatureSensorCircuit.png

Just make sure of the following key aspects:
1. Sensor yellow and red cables are connected with ground 
2. Sensor green cable is the one going to the input arduino pin (The cable from which we will read data)       
2. Make sure that the **input pin** in the arduino is **number 2** (The one used in the code to initialize the temperatureSensor class, see Section 4 -Connection with the temperature sensor)

### 4. Arduino board set-up

#### Obtaining the source code
The source code needed to be uploaded to the Arduino board is located under the src folder of this repository, which you can directly download from github. All the relevant Arduino sketches are located there, no extra programming is necessary if pin numbers are strictly followed.

#### Connection with the LCD screen
The connection with the temperature sensor is handled in class **LCDShield**, which is completely made for you.
If you investigate this Arduino sketch you will see a library coded to wrap the usage of the Arduino LCD KeyPad Shield.
It is used to read the LCD buttons and write data to the screen.
The header file (.h) defines the main functions and attributes related to the LCD and the implementation file (.cpp) implements the functions defined in the header file.

It defines the following main functionalities:
1. read LCD buttons
2. print LCD
3. print Max Min

#### Connection with the motor
The connection with the temperature sensor is handled in class **motor**, which is completely made for you.
If you investigate this Arduino sketch you will see a library coded to wrap the usage of the motor.
It is used to activate and desactivate the motor at a certain speed.
The header file (.h) defines the main functions and attributes related to the motor and the implementation file (.cpp) implements the functions defined in the header file.

It defines the following main functionalities:
1. Activate Motor
2. Disable Motor
3. check motor activation status

#### Connection with the temperature sensor
The connection with the temperature sensor is handled in class **temperatureSensor**, which is completely made for you.
If you investigate this Arduino sketch you will see that it depends on two well-known libraries, [DallasTemperature](https://milesburton.com/Dallas_Temperature_Control_Library) (A third party library capable of reading temperature values in an easy way.) and [OneWire](https://www.pjrc.com/teensy/td_libs_OneWire.html) (A third party library capable of accessing 1-wire devices.).

If you investigate this Arduino sketch you will see a library coded to wrap the usage of the temperature sensor.
It is used to read temperature values from the sensor and store maximum and minimum readings.
To this aim it makes use of the previously described OneWire and DallasTemperature libraries.

It defines the following main functionalities:
1. get temperature
2. get observed max temperature
3. get observed min temperature

**The main file or sketch** to run the Arduino project is called **termometerProject.ino**. 
This file depends on all classes described above and employes them all to run the project.
It consists of the relevant code to define the setup (The pins!) and the main loop that will continuously run on the Arduino board.

### 5. Run the project using the Arduino IDE
You are done! Just enjoy your experimentation with the electronic calorimeter.

## Contact
Any issues, bugs or updates please report to Inigo Lopez-Gazpio <inigo.lopezgazpio@deusto.es>
