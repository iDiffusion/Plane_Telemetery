/*
  blink.ino - Library for using leds
  Created by Tylon I. Lee, February 11, 2020.
  Released on github as iDiffusion
*/

#include "LED.h"

LED led(LED_BUILTIN);

void setup() {
  // Do nothing
}

void loop() {
  led.ON();     // turn the LED on
  delay(1000);  // wait for a second
  led.Off();    // turn the LED off
  delay(1000);  // wait for a second
  led.set(50);  // turn the LED on with half brightness
  delay(1000);  // wait for a second
  led.switchOnOff();  // switch the LED on or off
  delay(1000);  // wait for a second
}
