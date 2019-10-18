//Purpose of code is simple, point car northwards
//#include "MPU9250BasicAHRS"
#include "MPU9250BasicAHRS.h"
#include <math.h>
//Steps 
//Set up
float magVal[3] = {0, 0, 0};
int motorFPin = 9;
int motorBPin = 10;

void setup() {
  // put your setup code here, to run once:
 pinMode(motorFPin, OUTPUT);
 pinMode(motorBPin, OUTPUT);
 magSetup();
}

void loop() {
//read magnetometer input
getMagVal(magVal);
//what way we are currently pointing
float radDirection = atan2(magVal[1], magVal[0]);

float degDirection = (radDirection + M_PI) * (360.0 / (2 * M_PI));

if (radDirection<0){
	radDirection=fabs(radDirection);
	//As it gets closer to the correct direction it slows down
	int speed = (radDirection/M_PI)*1023;
  analogWrite(motorFPin, speed);
  analogWrite(motorBPin, 0);
	
}else{
	radDirection=fabs(radDirection);
	//As it gets closer to the correct direction it slows down
	int speed = (radDirection/M_PI)*1024;
  analogWrite(motorBPin, speed);
  analogWrite(motorFPin, 0);
}
}

//determine which direction to turn to face north
//rotate towards north
//loop
