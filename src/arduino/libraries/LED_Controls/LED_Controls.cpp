#include "LED_Controls.h"

LED_Controls:: LED_Controls(int pin){
  pinMode(pin, OUTPUT);
  _pin = pin;
}

void LED_Controls::ON(){
  digitalWrite(_pin, HIGH);
}

void LED_Controls::OFF(){
  digitalWrite(_pin, LOW);
}

void LED_Controls::set(int perc){
  int value = map(perc, 0, 100, 0, 127);
  analogWrite(_pin, value);
}
