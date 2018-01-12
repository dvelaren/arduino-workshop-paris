# Arduino Workshop for Université Paris 1 -  Sorbonne
Arduino workshop course for basic concepts required to start developing software in Arduino Platform. It consists in a total of 5 classes (click for PDF):

* [Class 1 - Arduino Fundamentals](https://raw.githubusercontent.com/tidusdavid/arduino-workshop-paris/master/Slides/Class%201%20-%20Arduino%20Fundamentals.pdf)
* [Class 2 - Sensors](https://raw.githubusercontent.com/tidusdavid/arduino-workshop-paris/master/Slides/Class%202%20-%20Sensors.pdf)
* [Class 3 - Analog Outputs and Mapping](https://raw.githubusercontent.com/tidusdavid/arduino-workshop-paris/master/Slides/Class%203%20-%20Analog%20Outputs%20and%20Mapping.pdf)
* [Class 4 - IO Table and FSM](https://raw.githubusercontent.com/tidusdavid/arduino-workshop-paris/master/Slides/Class%204%20-%20IO%20Table%20and%20FSM.pdf)
* [Class 5 - Relative Timing and FSM for Arduino](https://raw.githubusercontent.com/tidusdavid/arduino-workshop-paris/master/Slides/Class%205%20-%20Relative%20Timing%20and%20FSM%20for%20Arduino.pdf)

## Requirements
* [Arduino UNO](http://www.arduino.org/products/boards/arduino-uno) or [Arduino Mega](https://www.arduino.cc/en/Main/arduinoBoardMega).
* [Arduino IDE 1.8.3 or higher](https://www.arduino.cc/en/Main/Software).
* min 30 pcs [Jumper Wires H-H, M-H, M-M](https://www.amazon.com/Elegoo-120pcs-Multicolored-Breadboard-arduino/dp/B01EV70C78/ref=pd_bxgy_147_img_3?_encoding=UTF8&pd_rd_i=B01EV70C78&pd_rd_r=8R86GV0FSJYYR6FNNXK2&pd_rd_w=nM5v2&pd_rd_wg=mHeIO&psc=1&refRID=8R86GV0FSJYYR6FNNXK2)
* [DFROBOT Sensor Kit for Arduino](https://www.dfrobot.com/product-725.html).
* [DHT11 Temperature Humidity Sensor](https://www.dfrobot.com/product-174.html)
* [Photoresistor Module for Arduino](https://www.amazon.com/MagiDeal-Keyestudio-Photocell-Photosensitive-Photoresistor/dp/B01J3J5PJE/ref=sr_1_36?s=industrial&ie=UTF8&qid=1515507748&sr=1-36&keywords=Photoresistor+Sensor)
* [SRF05 Ultrasonic Sensor](https://www.dfrobot.com/product-333.html)
* [RGB LED Module for Arduino](https://www.amazon.com/Module-5050-Tri-Colour-Color-Arduino/dp/B0751JTQFY/ref=sr_1_36?ie=UTF8&qid=1515681264&sr=8-36&keywords=RGB+SMD+Board)

## Class examples
Below you can see the examples explanation and connection for each class:

### Class 1 - Arduino Fundamentals
This class covers:
1. Introduction.
2. Arduino MEGA 2560 Pinout.
3. Variables in Arduino Programming.
4. Typical Operators for Arduino Programming.
5. Arduino Program Structure.
6. Arduino common used commands.
7. Arduino common statements.

#### Example 1.1 – Arduino common used commands
In PIN 13 there is a LED (L1) connected. Blink the LED ½ second ON and ½ second OFF.
![alt text](https://raw.githubusercontent.com/tidusdavid/arduino-workshop-paris/master/Resources/E11-Blink.png)

#### Example 1.2 – If statement with digital input
In the PIN 2 there is a switch (SW) and in the PIN 13 there is a LED (L1). Turn ON the LED if the switch is activated, in other case, turn off the LED.
![alt text](https://raw.githubusercontent.com/tidusdavid/arduino-workshop-paris/master/Resources/E12-LEDSW.png)

#### Example 1.3 – Traffic light
Write a program that controls a traffic light with 2 maintenance switches. If both switches are activated, the Red light will blink. In other case the traffic light will work normally (Red, Yellow, Green).
![alt text](https://raw.githubusercontent.com/tidusdavid/arduino-workshop-paris/master/Resources/E13-TrafficLight.png)

### Class 2 - Sensors
This class covers:
1. Introduction
2. Digital sensors
3. Analog sensors
4. Specialized sensors

#### Example 2.1 – Potentiometer
Do an Arduino program that monitors the value of the potentiometer and shows it on the Serial Monitor.
![alt text](https://raw.githubusercontent.com/tidusdavid/arduino-workshop-paris/master/Resources/E21-Potentiometer.png)

#### Example 2.2 – Ultrasonic Sensor
Measure the distance in cm using an ultrasonic sensor (for SRF05).
![alt text](https://raw.githubusercontent.com/tidusdavid/arduino-workshop-paris/master/Resources/E22-Ultrasonic.png)

#### Example 2.3 – DHT11
Do  a program on Arduino that monitors the temperature and humidity of the DHT11 and prints each values on the Serial Monitor every second. If the temperature rises 30 °C, turn a LED L1.
![alt text](https://raw.githubusercontent.com/tidusdavid/arduino-workshop-paris/master/Resources/E23-DHT11.png)

### Class 3 - Analog Outputs and Mapping
This class covers:
1. Analog variables mapping
2. Analog Outputs (PWM)

#### Example 3.1 – Mapping Soil Moisture Sensor
Implement a program that calibrates from 0% to 100% a soil moisture sensor.
![alt text](https://raw.githubusercontent.com/tidusdavid/arduino-workshop-paris/master/Resources/E31-SoilMoisture.png)

#### Example 3.2 – PWM RGB LED
Do an Arduino program that varies randomly the color combination of a RGB LED. Check what type of LED (Common Anode or Cathode is being used):
Connection for common anode RGB LED
![alt text](https://raw.githubusercontent.com/tidusdavid/arduino-workshop-paris/master/Resources/E32-PWMRGB_CA.png)
Connection for common cathode RGB LEDS
![alt text](https://raw.githubusercontent.com/tidusdavid/arduino-workshop-paris/master/Resources/E32-PWMRGB_CC.png)

### Class 4 - I/O Table and Finite State Machines
This class covers:
1. I/O Table
2. Finite State Machines (FSM)

![alt text](https://raw.githubusercontent.com/tidusdavid/arduino-workshop-paris/master/Resources/E42-AdvancedFSM.png)

Do a FSM that controls a basic plastic injector, having in mind the following operation:
* The injector is completely OFF (RT and MT OFF) at the beginning.
* To start the injector, the bSTART button must be pressed.
* First, the injector must check that the raw material is at the required level (SMP1=𝑂𝑁).
* Then, the extruder screw needs to be heated using the resistance 𝑹𝑻 until it reaches a temperature of 80°C (ST≥80).
* Once the screw is at the required temperature, RT must be turned OFF and MT turned ON in order to transport the melted material until the end of the injector.
* When the melted material reaches the end of the injector (SMP2 = ON), the injector must wait 15 seconds and then turn OFF MT for starting a new injection cycle (from verifying raw material level step).
* If in any moment the bSTOP button is pressed, the machine returns to the initial state.
* Add a counter (C1, Internal Variable) to check if the injection process has compleated more than 3 injection cycles. If this is true, then the machine must return to the initial state.

### Class 5 - Relative Timing and FSM for Arduino
This class covers:
1. Relative timings in Arduino using millis() function.
2. Finite State Machines with Arduino.

#### Example 5.1 – Relative timing in Arduino with millis()
Do an Arduino program that allows to blink a LED (L1) ½ sec ON and ½ sec OFF using the millis() function.
![alt text](https://raw.githubusercontent.com/tidusdavid/arduino-workshop-paris/master/Resources/E51-BlinkMillis.png)

#### Example 5.2 – FSM with Arduino
Do an Arduino program that blinks a LED (L1) connected on pin 2, ½ sec ON and ½ sec OFF while the emergency button is not activated (BEMG) connected on pin 8. If BEMG is ON, the LED L1 remains OFF and the LED L2 connected on pin 3 turns ON. When there isn’t anymore an emergency, the process returns to its normal blinking.
![alt text](https://raw.githubusercontent.com/tidusdavid/arduino-workshop-paris/master/Resources/E52-BlinkFSM.png)
##### I/O Table
![alt text](https://raw.githubusercontent.com/tidusdavid/arduino-workshop-paris/master/Resources/E52-BlinkFSMSol1.png)

##### FSM
![alt text](https://raw.githubusercontent.com/tidusdavid/arduino-workshop-paris/master/Resources/E52-BlinkFSMSol2.png)
