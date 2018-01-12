//Class 1 - Example 3 - SimpleTrafficLight
//Description: Write a program that controls a traffic light with 2 maintenance switches.
//If both switches are activated, the Red light will blink. In other case the traffic
//light will work normally (Red, Green, Yellow).

//I/O pin labeling
#define LR 4  //Red LED “LR” connected on digital pin 4
#define LY 3  //Yellow LED “LY” connected on digital pin 3
#define LG 2  //Green LED “LG” connected on digital pin 2
#define S1 7  //Switch “S1” connected on digital pin 7
#define S2 8  //Switch “S2” connected on digital pin 8

//Constant declaration
const unsigned long TRV = 5000; //Time constant from Red to Green initialized on 5000 ms
const unsigned long TVA = 2500; //Time constant from Green to Yellow initialized on 2500 ms
const unsigned long TAR = 1000; //Time constant from Yellow to Red initialized on 1000 ms
const unsigned long TIT = 5000; //Time constant for blinking initialized on 5000 ms

//Configuration
void setup() {
  //Pin configuration
  pinMode(LR, OUTPUT);  //LR as output
  pinMode(LY, OUTPUT);  //LY as output
  pinMode(LG, OUTPUT);  //LG as output
  pinMode(S1, INPUT);  //S1 as intput
  pinMode(S2, INPUT);  //S2 as intput
  
  //Physical Output Cleaning
  digitalWrite(LR, LOW); //Turn off LR
  digitalWrite(LY, LOW);  //Turn off LY
  digitalWrite(LG, LOW); //Turn off LG
}

//Execution
void loop() {
 if (digitalRead(S1) == HIGH && digitalRead(S2) == HIGH) { //If both maintenance switchs are ON, blink
   //Turn OFF all LEDs
    digitalWrite(LR, LOW);
    digitalWrite(LY, LOW);
    digitalWrite(LG, LOW);
    delay(TIT); //Delay of TIT msegs (5000msecs)

    //Turn ON red led
    digitalWrite(LR, HIGH);
    digitalWrite(LY, LOW);
    digitalWrite(LG, LOW);
    delay(TIT); //Delay of TIT msegs (5000msecs)
  }
  else {//In other case
    //Normal traffic light secuence
    digitalWrite(LR, HIGH);
    digitalWrite(LY, LOW);
    digitalWrite(LG, LOW);
    delay(TRV);  //Delay of TRV msecs (5000msecs)
    
    digitalWrite(LR, LOW);
    digitalWrite(LY, LOW);
    digitalWrite(LG, HIGH);
    delay(TVA);  //Delay of TVA msegs (2500msecs)
    
    digitalWrite(LR, LOW);
    digitalWrite(LY, HIGH);
    digitalWrite(LG, LOW);
    delay(TAR);  //Delay of TAR msegs (1000msecs)
  }
}

