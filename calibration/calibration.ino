//Pin Definitions

const int SENSOR0 = A0;
const int SENSOR1 = A1;

//Global Variables
int sensor0;
int sensor1;

void setup() {
  //Set up serial line for debugging
  Serial.begin(9600);
  Serial.println("INITIALIZED");
}

void loop() {
  //Read sensors
  sensor0 = analogRead(SENSOR0);
  sensor1 = analogRead(SENSOR1);
  Serial.println(sensor0);
  Serial.println(sensor1);
  
  delay(2000);
}
