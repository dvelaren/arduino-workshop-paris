//Class 2 - Example 2 - Ultrasonic (SEEED)
//Description: Measure the distance in cm using an ultrasonic sensor (for SEEED sensor)

//I/O Pin Labeling
#define SIG 2 //Ultrasonic SIG pin connected to Arduino pin 2

//Variable declaration
unsigned int distance = 0;  //Variable for storing the value of the potentiometer (distance)

//Subroutines and functions
unsigned int ultraMeas(unsigned int SIGPIN) {
  delay(50);  //Delay of 50 ms before the next ranging
  pinMode(SIGPIN, OUTPUT); //SIGPIN as input (for transmitting)
  digitalWrite(SIGPIN, HIGH); //Turn ON the SIGPIN for measuring the distance
  delayMicroseconds(10);  //Wait 10uSecs with the TRIG ON
  digitalWrite(SIGPIN, LOW); //Turn OFF the SIGPIN
  pinMode(SIGPIN, INPUT); //SIGPIN as input (for measuring)
  return pulseIn(SIGPIN, HIGH)/58.0; //Return the distance on centimeters
}

void setup() {
  //I/O Pin Definition
  pinMode(SIG, OUTPUT); //SIGPIN as output

  //Physical Output Cleaning
  digitalWrite(SIG, LOW); //Turn OFF SIGPIN

  //Communications
  Serial.begin(9600); //Begin Serial Communications with the computer by the Serial 0 port (TX0 RX0) at 9600 bauds
}

void loop() {
  distance = ultraMeas(SIG);  //Measure distance
  Serial.print("Distance (cm): ");
  Serial.println(distance);
}
