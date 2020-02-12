/*
  LiquidCrystal Library - display() and noDisplay()

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 This sketch prints "Hello World!" to the LCD and uses the
 display() and noDisplay() functions to turn on and off
 the display.

 The circuit:
 * LCD VSS pin to ground
 * LCD VDD pin to 5V
 * LCD V0 pin to 3.3K resistor tied to ground
 * LCD RS pin to digital pin 22
 * LCD R/W pin to ground
 * LCD Enable pin to digital pin 23
 * LCD D0 pin to nothing
 * LCD D1 pin to nothing
 * LCD D2 pin to nothing
 * LCD D3 pin to nothing
 * LCD D4 pin to digital pin 24
 * LCD D5 pin to digital pin 25
 * LCD D6 pin to digital pin 26
 * LCD D7 pin to digital pin 27
 * LCD A pin to 220 resistor tied to 5V
 * LCD K pin to ground
*/

// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 22, en = 23, d4 = 24, d5 = 25, d6 = 26, d7 = 27;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("hello, world!");
}

void loop() {
  // Turn off the display:
  lcd.noDisplay();
  delay(500);
  // Turn on the display:
  lcd.display();
  delay(500);
}
