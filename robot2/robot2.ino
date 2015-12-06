/*
This is the source code for our line following robot
 ***INFO***
 Team 3
 Kyle Thomas; Harshdeep Goraya; Ashley Impastato; Randy Lavota
 Revision 2.0
 Date
 20141028
 Class
 EGR-1100-SECTION
 ***DISCRIPTION***
 Starts by definging global variables
 Startup
 starts debugging
 sets pin modes
 Loop
 read sensors
 comapre values to the calibration 
 assigns digital logic
 uses a compare of the 2 digital logic values to determine movement needs
 makes movement
 */
//environment
#define baud 9600
#define calibration 200

//Pinout
#define SENSOR0 A0
#define SENSOR1 A1
#define MOTOR0 6
#define MOTOR1 5

//Motor speeds
#define FWD 255
#define TURN 255
#define STOP 0

//Global variables
int sensor0;
int sensor1;
int sensorC0;
int sensorC1;
int a;
int b;

void setup() {
  //Start serial line for debugging
  Serial.begin(baud);
  Serial.println("INITILIZED");

  //Pin setup
  pinMode(MOTOR0, OUTPUT);
  pinMode(MOTOR1, OUTPUT);
  Serial.println("MOTOR PINS SET");
}

void loop() {
  //Read sensor values
  sensor0 = analogRead(SENSOR0);
  sensor1 = analogRead(SENSOR1);
  Serial.println(sensor0);
  Serial.println(sensor1);

  /*Movement Logic*/

  //Generate Digital logic based on a comp
  //between sensor value and calibration value
  if (sensor0 < calibration) {
    a = 0;
  }
  else if (sensor0 > calibration) {
    a = 1;
  }

  if (sensor1 < calibration) {
    b = 0;
  }	
  else if (sensor1 > calibration) {
    b = 1;
  }
  //Compare digital logic values to each other
  //to detmin the direction that the bot needs to go
  if (a == b){
    Serial.println("ON TRACK");
    //Forward
    analogWrite(MOTOR0,FWD);
    analogWrite(MOTOR1,FWD);
  }

  if (a < b){
    Serial.println("GO RIGHT");
    //Turn until the line is detected by the other sensor
    while (true) {
      //Differential turning
      analogWrite(MOTOR1, STOP);
      analogWrite(MOTOR0, TURN);
      sensorC0 = analogRead(SENSOR0);
      if (sensorC0 > calibration) {
        //Break out of the infinite loop once the line is detected again
        break;
      }
    }
  }

  if (a > b) {
    Serial.println("GO Left");
    //Turn until the line is detected by the other sensor
    while (true) {
      //Differential turning
      analogWrite(MOTOR0, STOP);
      analogWrite(MOTOR1, TURN);
      sensorC1 = analogRead(SENSOR1);
      if (sensorC1 > calibration) {
        //Break out of the infinite loop once the line is detected again
        break;
      }
    }
  }
}


