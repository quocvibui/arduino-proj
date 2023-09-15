/* Get output from the ultrasonic sensor(SR04) 
   and display the measurement on the LCD display
   ------------------------------------------------------------------------
   codes taken from: https://docs.arduino.cc/learn/electronics/lcd-displays
   and Elegoo's resource for Arduino Mega
*/ 

// import library
#include "SR04.h"
#include <LiquidCrystal.h>

// defining the connection of the sensor to which digital pin
#define TRIG_PIN 9
#define ECHO_PIN 8

// initializing the sensor
SR04 uSonicSensor = SR04(ECHO_PIN, TRIG_PIN);

// initializing the LCD
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// variable to keep the sensor's measurement
long measurement;

void setup(){

  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);

  // Print the sensor's name on the LCD
  lcd.print("UltraSonicSensor");

  // start the serial in arduino IDE
  Serial.begin(9600);
  
  delay(1000);
}

void loop(){

  // initializing measurement
  measurement = uSonicSensor.Distance();
  String stringCM = " cm";

  // set up lcd to print the info
  lcd.setCursor(0, 1);
  lcd.print(measurement + stringCM);

  // set up to print in serial
  Serial.print(measurement);
  Serial.println("cm");

  delay(1000);
}