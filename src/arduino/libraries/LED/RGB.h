/*
  RGB.h - Library for using rgb leds
  Created by Tylon I. Lee, March 2, 2020.
  Released on github as iDiffusion
*/

#ifndef RGB_H
#define RGB_H
#include "arduino.h"

class RGB{
  public:
    RGB(int red, int green, int blue);
    void RED();
    void ORANGE();
    void YELLOW();
    void GREEN();
    void BLUE();
    void PURPLE();
    void WHITE();
    void ON();
    void OFF();
    void setPercent(int perc);
    void set(int red, int green, int blue);
    bool switchOnOff();
    bool getState();
  private:
    int[] _pin, _value;
    bool checkValue();
};

#endif
