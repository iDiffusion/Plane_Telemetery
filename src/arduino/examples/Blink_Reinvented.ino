/*
  Blink_Reinvented.ino

  Turns on and off two light emitting diode (LED) connected to digital pins,
  without using the delay() function. This means that other code can run at the
  same time without being interrupted by the LED code.

  The circuit (using MEGA):
    Blue LED cathode to digital pin 13
    Green LED to digital pin 12
    Push Button connected to digital pin 7
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

  Created by Peyton
  Modified by Tylon Ikaika Lee

*/

#include <LiquidCrystal.h>

#define blueLED 13
#define greenLED 12
#define btnPin 7

// initialize the lcd library with the numbers of the interface pins
const int rs = 22, en = 23, d4 = 24, d5 = 25, d6 = 26, d7 = 27;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const bool debug = false;
const int waitTimeBlue = 1000, waitTimeGreen = 500;
unsigned long lastTimeGreen, lastTimeBlue;

void setup() {
  //setup remaining input output pins
  pinMode(blueLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(btnPin, INPUT_PULLUP);

  if (debug) {
    Serial.begin(9600);
  }

  // set up the LCD's number of rows and columns
  lcd.begin(16, 2);

  //set default led states
  turnLEDON(blueLED);
  turnLEDON(greenLED);
  lastTimeGreen = lastTimeBlue = millis();
}

void loop() {
  checkTimePast(lastTimeGreen, waitTimeGreen, greenLED);
  checkTimePast(lastTimeBlue, waitTimeBlue, blueLED);

  //check if button is pushed and switch led state
  if (checkBtnState(btnPin)) {
    switchONOFF(greenLED);
    switchONOFF(blueLED);
    lastTimeGreen = lastTimeBlue = millis();
  }

  //print to serial devices
  printLCD();
  if (debug) {
    printSerial();
  }
}

void printLCD() {
  lcd.setCursor(0, 0);
  lcd.print("LTG = ");
  lcd.print(lastTimeGreen / 100 / 10.0);
  lcd.setCursor(0, 1);
  lcd.print("LTB = ");
  lcd.print(lastTimeBlue / 100 / 10.0);
}

void printSerial() {
  Serial.print("Last time green: ");
  Serial.print(lastTimeGreen);
  Serial.print("    Last time blue: ");
  Serial.println(lastTimeBlue);
}

bool checkBtnState (int pin) {
  bool state = false;
  if (!digitalRead(pin)) {
    state = true;
  }
  while (!digitalRead(pin)) {}
  return state;
}

// check to see if enough time has passed, if so, switch led state and update last time
void checkTimePast(unsigned long &lastTime, int waitTime, int pin) {
  if (lastTime + waitTime < millis()) {
    switchONOFF(pin);
    lastTime =  millis();
  }
}

void turnLEDON(int pin) {
  digitalWrite(pin, HIGH);
}

void turnLEDOFF(int pin) {
  digitalWrite(pin, LOW);
}

void switchONOFF(int pin) {
  int state = digitalRead(pin);
  digitalWrite(pin, !state);
}

void setLEDBrightness(int pin, int perc) {
  int brightness = map(perc, 0, 100, 0, 255);
  analogWrite(pin, brightness);
}
