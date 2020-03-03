#include <Wire.h>
#include <SimpleDHT.h>

#define slave_address 0x0b
#define dhtPin 7

const bool debug = false;

SimpleDHT11 dht11(dhtPin);

byte temperature = 0;
byte humidity = 0;

void setup() {
  // Initialize I2C communications as Slave
  Wire.begin(slave_address);

  // Function to run when data requested from master
  Wire.onRequest(requestEvent);

  if (debug) {
    // Setup serial monitor
    Serial.begin(9600);
    Serial.println("I2C Slave Device:");
  }
}

void loop() {
  int err = dht11.read(&temperature, &humidity, NULL);
  if (!debug) {
    return;
  }

  // start working...
  Serial.println("=================================");
  Serial.println("Sample DHT11...");

  // read without samples.
  if (err != SimpleDHTErrSuccess) {
    Serial.print("Read DHT11 failed, err="); Serial.println(err); delay(1000);
    return;
  }

  Serial.print("Sample OK: ");
  Serial.print((int)temperature); Serial.print(" *C, ");
  Serial.print((int)humidity); Serial.println("% H");

  // DHT11 sampling rate is 1HZ.
  delay(1500);
}

void requestEvent() {
  Wire.write(temperature);
  Wire.write(humidity);
}
