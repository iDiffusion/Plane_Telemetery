/*
  Recieve and fomrat sensor data from slaves
*/

// Include Arduino Wire library for I2C
#include <Wire.h>

// Empty I2C addesses are 0x08, 0x09, 0x0a, 0x0b, and more
#define slave_address_1 0x08
#define slave_address_2 0x09

// Define Slave answer size
#define ANSWERSIZE 6

void setup() {
  // Initialize I2C communications as Master
  Wire.begin();

  // Setup serial monitor
  Serial.begin(9600);
  Serial.println("I2C Master Device:");
}

void loop() {
  // Time delay in loop
  delay(50);
}

int parseData(Byte response[]){
  //TODO interpret data recieved on the I2C Bus

}

void getData(int slave_address){
  // Read response from Slave
  Wire.requestFrom(slave_address, ANSWERSIZE);

  // Hold the response from slaves till its parsed
  Byte response[ANSWERSIZE];
  int sensor = 0;

  int i = 0;
  bool go = false;
  // Add bytes to an array
  while (Wire.available()) {
    byte b = Wire.read();
    if(b == 255){
      go = true;
    }
    if (go) {
      if(i == 1){
        sensor = b;
      }
      response [i++] = b;
    }
  }

  // Interpret data recieved on the I2C Bus
  parseData(response);

  // Print to Serial Monitor
  Serial.println(response);
}
