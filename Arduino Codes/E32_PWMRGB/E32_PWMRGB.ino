//Class 3 - Example 2 - PWMRGB
//Description: Do an Arduino program that varies randomly the color combination of a RGB LED

//I/O Pin Labeling
#define LR 2  //Red segment of the RGB LED connected to pin 2
#define LG 3  //Green segment of the RGB LED connected to pin 3
#define LB 4  //Blue segment of the RGB LED connected to pin 4

//Configuration
void setup() {
 //I/O Pin Configuration
  pinMode(LR, OUTPUT);  //LR as Output
  pinMode(LG, OUTPUT);  //LG as Output
  pinMode(LB, OUTPUT);  //LB as Output

 //Physical Output Cleaning
  digitalWrite(LR, LOW);  //Turn OFF LR
  digitalWrite(LG, LOW);  //Turn OFF LG
  digitalWrite(LB, LOW);  //Turn OFF LB
}

//Execution
void loop() {
  analogWrite(LR, random(256));  //Random analog writing to the red segment from 0~255
  analogWrite(LG, random(256)); //Random analog writing to the green segment from 0~255
  analogWrite(LB, random(256)); //Random analog writing to the blue segment from 0~255
  delay(200);  // 200 milisecs delay
}

