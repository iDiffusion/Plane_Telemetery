/*
  Obtain all the sensor data and send it to the master
*/

#include <Wire.h>

// Empty I2C addesses are 0x08, 0x09, 0x0a, 0x0b, and more
#define slave_address 0x08

// Define Slave answer size
#define ANSWERSIZE 6

byte sensor = 0;
int value = 0;

void setup() {
  // Initialize I2C communications as Slave
  Wire.begin(slave_address);

  // Function to run when data requested from master
  Wire.onRequest(requestEvent);

  // Function to run when data received from master
  Wire.onReceive(receiveEvent);

  // Setup serial monitor
  Serial.begin(9600);
  Serial.println("I2C Slave Device:");

  //TODO setup pins as outputs or inputs
}

void loop() {
  // Time delay in loop
  delay(50);
}

void receiveEvent(int howMany) {
  while (Wire.available()) { // loop through all but the last
    byte x = Wire.read(); // receive byte as a character
    //TODO interpret data recieved on the I2C Bus
  }
  Serial.println("Receive event");
}

void requestEvent() {
  // Setup byte variable in the correct size
  byte response[ANSWERSIZE];

  response[0] = 255;

  // Format answer as array
  if (value < 0) {
    response[1] = response[2] = response[3] = response[4] = 0;
  }
  else if (0 <= value && value < 256) {
    response[1] = value;
    response[2] = response[3] = response[4] = 0;
  }
  else if (256 <= value && value < 512) {
    response[1] = 255;
    response[2] = value - 256;
    response[3] = response[4] = 0;
  }
  else if (512 <= value && value < 768) {
    response[1] = response[2] = 255;
    response[3] = value - 512;
    response[4] = 0;
  }
  else if (768 <= value && value < 1024) {
    response[1] = response[2] = response[3] = 255;
    response[4] = value - 768;
  }
  else {
    response[1] = response[2] = response[3] = response[4] = 255;
  }

  response[5] = sensor;

  // Send response back to Master
  Wire.write(response, sizeof(response));

  // Print to Serial Monitor
  Serial.println("Request event");
}
