/*
  master_all_sensors.ino

  Recieve and fomrat sensor data from slaves and sensors

  The circuit (using MEGA):
    RGB LED to digital pin 11-13
    Left Push Button connected to digital pin 28
    Right Push Button connected to digital pin 29
    LCD VSS pin to ground
    LCD VDD pin to 5V
    LCD V0 pin to 3.3K resistor tied to ground
    LCD RS pin to digital pin 22
    LCD R/W pin to ground
    LCD Enable pin to digital pin 23
    LCD D0 pin to nothing
    LCD D1 pin to nothing
    LCD D2 pin to nothing
    LCD D3 pin to nothing
    LCD D4 pin to digital pin 24
    LCD D5 pin to digital pin 25
    LCD D6 pin to digital pin 26
    LCD D7 pin to digital pin 27
    LCD A pin to 220 resistor tied to 5V (or pot)
    LCD K pin to ground
    Humidity Signal Pin to

  Created and Modified by Tylon Ikaika Lee
*/

// Include Sensor Libraries
#include <Wire.h>
#include <LiquidCrystal.h>
#include <RGB.h>

// Define pins
#define blueLED 13
#define greenLED 12
#define redLED 11
#define btnLeft 28
#define btnRight 29
#define rs 22
#define en 23
#define d4 24
#define d5 25
#define d6 26
#define d7 27

// Empty I2C addesses are 0x08, 0x09, 0x0a, 0x0b, and more
#define slave_address_1 0x08
#define slave_address_2 0x09
#define slave_address_3 0x0a
#define slave_address_4 0x0b

// Define Constants
const bool DEBUG = false;
const int ANSWERSIZE = 8;

// Define global variables
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
unsigned long lastTime;
int selectedSensor = 0;

void setup() {
  // Initialize I2C communications as Master
  Wire.begin();

  //setup remaining input output pins
  pinMode(blueLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(btnLeft, INPUT_PULLUP);
  pinMode(btnRight, INPUT_PULLUP);

  //setup serial monitor if debugging
  if (DEBUG) {
    Serial.begin(9600);
    Serial.println("I2C Master Device:");
  }
}

void loop() {
  // Time delay in loop
  delay(50);
}