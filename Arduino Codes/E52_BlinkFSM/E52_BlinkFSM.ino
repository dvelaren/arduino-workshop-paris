//Class 5 - Example 2 - BlinkFSM
//Description: Do an Arduino program that blinks a LED (L1) connected on pin 2,
//½ sec ON and ½ sec OFF while the emergency button is not activated (BEMG)
//connected on pin 8. If BEMG is ON, the LED L1 remains OFF and the LED L2
//connected on pin 3 turns ON. When there isn’t anymore an emergency, the
//process returns to its normal blinking.

//FSM States Labeling
#define SLOFF 0 //State LED OFF
#define SLON 1 //State LED ON
#define SAEMG 2 //State Alert Emergency

//I/O Pin Labeling
#define BEMG 8  //BEMG connected on pin 8
#define L1 2  //L1 connected on pin 2
#define L2 3  //L2 connected on pin 3

//Constants declaration
const unsigned long TBLINK = 500;  //Define blinking time constant as unsigned long and initialize it in 500 milisecs

//Variables declaration
unsigned int state = SLOFF;  //Variable for storing the current FSM state and initialized in SLOFF
//->Timing Vars
unsigned long tact = 0; //Actual time (tact) as unsigned long
unsigned long tini = 0; //Initial time (tini) as unsigned long
unsigned long trel = 0; //Relative time (trel) as unsigned long

//Configuration
void setup() {
  //I/O Pin Configuration
  pinMode(BEMG, INPUT); //BEMG as INPUT
  pinMode(L1, OUTPUT);  //L1 as OUTPUT
  pinMode(L2, OUTPUT);  //L2 as OUTPUT

  //Physical Output Cleaning
  digitalWrite(L1, LOW);  //Turn OFF L1
  digitalWrite(L2, LOW);  //Turn OFF L2
  tini = millis();  //Initialization of tini (first state ELOFF requires timing)
}

//Execution
void loop() {
  tact = millis(); //Refresh always actual time
  //FSM
  switch (state) {
    case SLOFF:
      //Physical Outputs state assignation
      digitalWrite(L1, LOW);  //Turn OFF L1
      digitalWrite(L2, LOW);  //Turn OFF L2

      //Internal Variables Computation
      //->Relative timing calculation
      trel = tact - tini;

      //Transition Questions
      if (trel >= TBLINK) { //If the relative time is greater or equal to TBLINK time
        state = SLON; //Next state is then SLON
        tini = millis();  //Reset the timer to a new value for next state timing
      }
      else if (digitalRead(BEMG) == HIGH) { //In other case if the BEMG is activated
        state = SAEMG;  //Next state is then SAEMG
      }
    break;

    case SLON:
      //Physical Outputs state assignation
      digitalWrite(L1, HIGH); //Turn ON L1
      digitalWrite(L2, LOW);  //Turn OFF L2

      //Internal Variables Computation
      //->Relative timing calculation
      trel = tact - tini;

      //Transition Questions
      if (trel >= TBLINK) {//If the relative time is greater or equal to TBLINK time
        state = SLOFF; //Next state is then SLOFF
        tini = millis();  //Reset the timer to a new value for next state timing
      }
      else if (digitalRead(BEMG) == HIGH) { // In other case if the BEMG is activated
        state = SAEMG;  // Next state is then SAEMG
      }
      break;
      
    case SAEMG:
      //Physical Outputs state assignation
      digitalWrite(L1, LOW); //Turn OFF L1
      digitalWrite(L2, HIGH);  //Turn ON L2

      //Transition Questions
      if (digitalRead(BEMG) == LOW) { //If BEMG is deactivated
        state = SLON;  //Next state is then SLON
        tini = millis(); //Reset the timer to a new value for next state timing
      }
      break;
  }
}
