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
