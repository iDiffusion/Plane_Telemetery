/*
  LED.h - Library for using leds
  Created by Tylon I. Lee, February 5, 2020.
  Released on github as iDiffusion
*/

#ifndef LED_H
#define LED_H
#include "arduino.h"

class LED {
  public:
    LED(int pin);
    void ON();
    void OFF();
    void setPercent(int perc);
    void set(int value);
    bool switchOnOff();
    bool getState();
    int getValue();
  private:
    int _pin;
};

#endif
