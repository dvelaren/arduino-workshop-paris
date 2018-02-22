//Class 1 - Example 1 - Blink
//Description: In PIN 13 there is a LED (L1) connected. Blink the LED ½ second ON and ½ second OFF.

//I/O pin labeling
#define L1 13 //Label LED connected in pin 13 as “L1”

//Constant declaration
unsigned long TBLINK = 500; //Blink constant TBLINK initialized in 500 ms

//Configuration
void setup() {
  //I/O Pin Configuration
  pinMode(L1, OUTPUT);  //Set pin L1 as Output

  //Output cleaning
  digitalWrite(L1, LOW);  //Turn OFF L1
}

//Execution
void loop() {
  digitalWrite(L1, HIGH); //Turn ON L1
  delay(TBLINK); //Delay of TBLINK miliseconds(500 ms)
  digitalWrite(L1, LOW);  //Turn OFF L1
  delay(TBLINK); //Delay of TBLINK miliseconds(500 ms)
}
