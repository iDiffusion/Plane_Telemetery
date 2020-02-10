/*
  Obtain all the sensor data and send it to the raspberry pi
*/

#include <Wire.h>

void setup() {

}

void loop() {

}

void receiveEvent(int howMany) {
  while (Wire.available()) { // loop through all but the last
    char c = Wire.read(); // receive byte as a character
    //TODO interpret data recieved on the I2C Bus
  }
}
