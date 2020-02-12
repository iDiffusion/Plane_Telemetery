/*
  Obtain all the sensor data and send it to the raspberry pi
*/

#include <Wire.h>

void setup() {
  // Join I2C bus as slave with address 8
  Wire.begin(0x8);

  // Call receiveEvent when data received
  Wire.onReceive(receiveEvent);

  //TODO setup pins as outputs or inputs
}

void loop() {

}

void receiveEvent(int howMany) {
  while (Wire.available()) { // loop through all but the last
    char c = Wire.read(); // receive byte as a character
    //TODO interpret data recieved on the I2C Bus
  }
}
