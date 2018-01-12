//Class 2 - Example 3 - DHT11
//Description: Do  a program on Arduino that monitors the temperature
//and humidity of the DHT11 and prints each values on the Serial
//Monitor every second. If the temperature rises 25 °C, turn a LED L1.

//Library Declaration
#include <DHT.h>

//I/O Pin Labeling
#define L1 13 //LED L1 connected on pin 13
#define DHTPIN 2 //DHT11 sensor connected to pin 2

//Constants declaration
const int Tmax = 25;  //Max temperature constants initiliazed
//on 25 °C.
//Variable declaration
float temperature = 0;  //Variable to store the temperature
float humidity = 0;  //Variable to store humidity

//Library Vars
#define DHTTYPE DHT11 //Use DHT11 sensor variant
DHT dht(DHTPIN, DHTTYPE); //DHT object var

//Subroutines & Functions
void readDHT() {
  temperature = dht.readTemperature();
  humidity = dht.readHumidity();
}

//Configuration
void setup() {
  //Pin Configuration
  pinMode(L1, OUTPUT);  //LED L1 as a digital output

  //Physical Outputs Cleaning
  digitalWrite(L1, LOW);  //Turn off L1

//Communications
  Serial.begin(9600); //Begin Serial Communications with the computer by the Serial 0 port (TX0 RX0) at 9600 bauds
  dht.begin(); //Initialize communications with DHT11 sensor
}

//Execution
void loop() {
    readDHT();
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.print(" Humidity: ");
    Serial.println(humidity);
    if (temperature >= Tmax) {
      digitalWrite(L1, HIGH);
    }
    delay(1000);
}
