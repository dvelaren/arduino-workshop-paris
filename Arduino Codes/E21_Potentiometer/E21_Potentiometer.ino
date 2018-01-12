//Class 2 - Example 1 - Potentiometer
//Description: Do an Arduino program that monitors the value of the potentiometer and shows it on the Serial Monitor

//I/O Pin Labeling
#define POT1 0  //Potentiometer POT1 connected to pin A0

//Variable declaration
unsigned int valuePOT = 0; //Variable to store the value of the potentiometer (valuePOT)

//Configuration
void setup() {
  //I/O Pin Configuration
  //Note: The analog inputs are not declared as INPUTS, they come like this as default

  //Communications
  Serial.begin(9600);  //Begin Serial communications with the computer using the Serial0 ports (TX0 RX0) and 9600 speed bauds rate
}

//Execution
void loop() {
  valuePOT = analogRead(POT1); //Read the ADC value of POT1 pin and store it on valuePOT
  Serial.print("POT value: "); //Print result on Serial monitor
  Serial.println(valuePOT); //Print result on Serial monitor
}
