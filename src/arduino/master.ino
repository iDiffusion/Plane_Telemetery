/*
  master.ino

  Recieve and fomrat sensor data from slaves and sensors

  The circuit (using MEGA):
    RGB LED to digital pin 11-13
    Left Push Button connected to digital pin 28
    Right Push Button connected to digital pin 29
    LCD VSS pin to ground
    LCD VDD pin to 5V
    LCD V0 pin to 3.3K resistor tied to ground
    LCD RS pin to digital pin 22
    LCD R/W pin to ground
    LCD Enable pin to digital pin 23
    LCD D0 pin to nothing
    LCD D1 pin to nothing
    LCD D2 pin to nothing
    LCD D3 pin to nothing
    LCD D4 pin to digital pin 24
    LCD D5 pin to digital pin 25
    LCD D6 pin to digital pin 26
    LCD D7 pin to digital pin 27
    LCD A pin to 220 resistor tied to 5V (or pot)
    LCD K pin to ground

  Created and Modified by Tylon Ikaika Lee
*/

// Include Sensor Libraries
#include <Wire.h>
#include <LiquidCrystal.h>
#include <RGB.h>

// Define pins
#define blueLED 13
#define greenLED 12
#define redLED 11
#define btnLeft 28
#define btnRight 29
#define rs 22
#define en 23
#define d4 24
#define d5 25
#define d6 26
#define d7 27

// Empty I2C addesses are 0x08, 0x09, 0x0a, 0x0b, and more
#define GRX6 0x07       // Variometer
#define LSM9DS1 0x08    // Accelerometer + Gyroscope + Magnetometer
#define NEO6M 0x09      // GPS
#define SHT31D 0x0a     // Temperature + Humidity
#define DHT11 0x0b      // Temperature + Humidity
#define MPL3115A2 0x0c  // Altimeter + Barometer

// Define global objects
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
RGB led(redLED, greenLED, blueLED);

// Define Constants
enum Sensor {
  Variometer, Altimeter, Pressure, Humidity, Temperature, Magnometer_X, Magnometer_Y, Magnometer_Z, Gyroscope_X, Gyroscope_Y, Gyroscope_Z, Accelerometer_X, Accelerometer_Y, Accelerometer_Z, GPS_Latitude, GPS_Longitude
};
const bool DEBUG = false;

// Define global variables
unsigned long lastTime;
int selectedSensor = Variometer;
float SensorValue[16];

void setup() {
  //setup serial monitor if debugging
  if (DEBUG) {
    Serial.begin(9600);
    Serial.println("I2C Master Device:");
  }

  // Initialize I2C communications as Master
  Wire.begin();

  //setup remaining input output pins
  pinMode(btnLeft, INPUT_PULLUP);
  pinMode(btnRight, INPUT_PULLUP);
}

void loop() {
  // TODO get data from each address
  delay(50);
}

void getData(int address) {
  // Read response from Slave
  int answerSize = getSize(address);
  Wire.requestFrom(address, answerSize);

  // Hold the response from slaves till its parsed
  byte response[answerSize + 1];
  int i = 0;

  // Add bytes to an array
  while (Wire.available()) {
    response [i++] = Wire.read();
  }

  // Interpret data recieved on the I2C Bus
  parseData(response, address);

  // Print to Serial Monitor
  if (!DEBUG) return;
  Serial.print("Response = ");
  for (i = 0; i < answerSize; i++) {
    Serial.print(response[i]);
    Serial.print(" ");
  }
  Serial.println();
}

int getSize(int address) {
  if (address == GRX6) {
    return 1;
  } else if (address == MPL3115A2) {
    return 2;
  } else if (address == SHT31D) {
    return 2;
  } else if (address == LSM9DS1) {
    return 9;
  } else if (address == NEO6M) {
    return 2;
  } else if (address == DHT11) {
    return 2;
  } else {
    return 0;
  }
}

void parseData(byte Response[], int address) {
  //TODO create switch statement to handle sensors
  switch (address) {
    case DHT11:
      SensorValue[Temperature] += Response[0];
      SensorValue[Humidity] += Response[1];
      break;
    case SHT31D:
      SensorValue[Temperature] += Response[0];
      SensorValue[Humidity] += Response[1];
      break;
    case GRX6:
      SensorValue[Variometer] = Response[0];
      break;
    case LSM9DS1:
      SensorValue[Accelerometer_X] = Response[0];
      SensorValue[Accelerometer_Y] = Response[1];
      SensorValue[Accelerometer_Z] = Response[2];
      SensorValue[Gyroscope_X] = Response[3];
      SensorValue[Gyroscope_Y] = Response[4];
      SensorValue[Gyroscope_Z] = Response[5];
      SensorValue[Magnometer_X] = Response[6];
      SensorValue[Magnometer_Y] = Response[7];
      SensorValue[Magnometer_Z] = Response[8];
      break;
    case MPL3115A2:
      SensorValue[Altimeter] = Response[0];
      SensorValue[Pressure] = Response[1];
      break;
    case NEO6M:
      SensorValue[GPS_Latitude] = Response[0];
      SensorValue[GPS_Longitude] = Response[1];
      break;
  }
}
