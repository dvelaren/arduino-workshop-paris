//Class 3 - Example 1 - MappingSoilMoisture
//Description: Implement a program that calibrates from 0% to 100% a soil moisture sensor

//I/O Pin Labeling
#define SMpin 0  //Soil Moisture sensor connected in pin A0

//Constants Declaration
const unsigned int ADCair = 200.0; //Constant to store the ADC value in the air of the Soil Moisture sensor (200)
const unsigned int ADCwater = 800.0; //Constant to store the ADC value in the water of the Soil Moisture sensor (800)

//Variables Declaration
unsigned int sm = 0; //Variable to store the percentage of the Soil Moisture

//Configuration
void setup() {
  //Communications
  Serial.begin(9600); //Begin Serial Communications with the computer by the Serial 0 port (TX0 RX0) at 9600 bauds
}

//Execution
void loop() {
  sm = (analogRead(SMpin) - ADCair) * 100.0 / (ADCwater - ADCair);  //Soil Moisture calculation using mapping formula
  Serial.print("Soil Moisture (%): ");
  Serial.println(sm);
}
