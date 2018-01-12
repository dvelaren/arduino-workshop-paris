//Class 1 - Example 2 - LEDSW
//Description: In the PIN 2 there is a switch (SW) and in the PIN 13 there is a LED (L1). Turn ON the LED if the switch is activated, in other case, turn off the LED.

//I/O pin labeling
#define SW 2  //Switch “SW” connected on pin 2
#define L1 13 //LED “L1” connected on pin 13

//Configuration
void setup() {
  //I/O Pin Configuration
  pinMode(SW, INPUT);  //SW as INPUT
  pinMode(L1, OUTPUT);  //L1 as OUTPUT

  //Output cleaning
  digitalWrite(L1, LOW);  //Turn OFF L1
}

//Execution
void loop() {
  if (digitalRead(SW) == HIGH) { //Check if SW is in logic state HIGH
    digitalWrite(L1, HIGH); //If it is, turn ON L1
  }
  else { //In other case
    digitalWrite(L1, LOW);  //If the SW is OFF, turn OFF L1
  }
}
