//Purpose of code is simple, point car northwards
//#include "MPU9250BasicAHRS"
#include "MPU9250BasicAHRS.h"
#include  <Wire.h>
#include  <LiquidCrystal_I2C.h>
#include <math.h>
LiquidCrystal_I2C lcd(0x3F, 16, 2);
//Steps
//Set up
float magVal[3] = {0, 0, 0};
int motorFPin = 9;
int motorBPin = 10;

void setup() {
  lcd.init();                      // initialize the lcd
  lcd.backlight();
  lcd.print("Lets get started");
  pinMode(motorFPin, OUTPUT);
  pinMode(motorBPin, OUTPUT);
  magSetup();
}

void loop() {
  //read magnetometer input
  getMagVal(magVal);
  //what way we are currently pointing
  lcd.clear();
  float radDirection = atan2(magVal[1], magVal[0]);
  //lcd.setCursor(0,1);
  lcd.setCursor(0, 0);
  lcd.print(magVal[1]);
  lcd.print(" ");
  lcd.print(magVal[0]);
  lcd.setCursor(0, 1);
  float degDirection = (radDirection + M_PI) * (360.0 / (2 * M_PI));
  lcd.print(int(degDirection));
  lcd.print(" ");
  lcd.print(radDirection);

  if (radDirection < 0) {
    radDirection = fabs(radDirection);
    //As it gets closer to the correct direction it slows down
    int speed = (radDirection / M_PI) * 1023;
    analogWrite(motorFPin, speed);
    analogWrite(motorBPin, 0);

  } else {
    radDirection = fabs(radDirection);
    //As it gets closer to the correct direction it slows down
    int speed = (radDirection / M_PI) * 1024;
    analogWrite(motorBPin, speed);
    analogWrite(motorFPin, 0);
  }
  delay(500);
}

//determine which direction to turn to face north
//rotate towards north
//loop
