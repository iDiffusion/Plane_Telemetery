#ifndef LED_Controls_H
#define LED_Controls_H
#include "arduino.h"

class LED_Controls {
  public:
    LED_Controls(int pin);
    void ON();
    void OFF();
    void set(int perc);
    bool switchOnOff();
  private:
    int _pin;
};

#endif
