//Class 5 - Example 1 - BlinkMillis
//Description: Do an Arduino program that allows to blink a LED (L1) ½ sec ON and ½ sec OFF using the millis() function.

//I/O Pin Labeling
#define L1 13 //L1 connected on pin 13

//Constants declaration
const unsigned long TBLINK = 500; //Blinking time constant (TBLINK) as unsigned long and initialized on 500 miliseconds

//Variables declaration
unsigned long tact = 0; //Actual time (tact) as unsigned long
unsigned long tini = 0;  //Initial time (tini) as unsigned long
unsigned long trel = 0; //Relative time (trel) as unsigned long

//Configuration
void setup() {
  //I/O Pin Configuration
  pinMode(L1, OUTPUT);  //L1 as OUTPUT

  //Physical Output Cleaning
  digitalWrite(L1, LOW);  //Turn OFF L1
  tini = millis();  //Initialize for the first time the tini variable because the first relative timing calculation will take place in the void loop
}

//Execution
void loop() {
  tact = millis(); //Take always the actual execution time
  trel = tact - tini;  //Calculate the relative time
  if (trel < TBLINK) { //If relative time (trel) is less than the blinking time constant (TBLINK)
    digitalWrite(L1, HIGH);  //Turn ON L1
  }
  else if (trel < TBLINK*2) { //If tstate is greater than blinking time constant but less than blinking time x 2 (1/2 sec ON and ½ sec OFF)
    digitalWrite(L1, LOW);  //Turn OFF L1
  }
  else { //In other case (if trel is greater than 2 times the blinking time constant) 
    tini = millis();  //Take a new initial time in order to begin again the blinking cycle (reset rel time to 0 in next iteration)
  }
}

