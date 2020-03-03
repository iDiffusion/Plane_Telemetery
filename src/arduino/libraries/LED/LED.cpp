/*
  LED.cpp - Library for using leds
  Created by Tylon I. Lee, February 5, 2020.
  Released on github as iDiffusion
*/

#include "LED.h"
#include "arduino.h"

LED:: LED(int pin) {
  pinMode(pin, OUTPUT);
  _pin = pin;
}

void LED::ON() {
  digitalWrite(_pin, HIGH);
}

void LED::OFF() {
  digitalWrite(_pin, LOW);
}

void LED::setPercent(int perc) {
  int value = map(perc, 0, 100, 0, 255);
  analogWrite(_pin, value);
}

void LED::set(int value) {
  analogWrite(_pin, value);
}

bool LED::switchOnOff() {
  int state = digitalRead(_pin);
  digitalWrite(_pin, !state);
  return !state;
}

bool LED::getState(){
  return digitalRead(_pin);
}
