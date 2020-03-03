/* How to use the DHT-11 sensor with Arduino uno
   Temperature and humidity sensor
*/

#include <SimpleDHT.h>

int pinDHT11 = 2;
SimpleDHT11 dht11(pinDHT11);

byte temperature = 0;
byte humidity = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  // start working...
  Serial.println("=================================");
  Serial.println("Sample DHT11...");

  // read without samples.
  int err = SimpleDHTErrSuccess;
  if ((err = dht11.read(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
    Serial.print("Read DHT11 failed, err="); Serial.println(err);delay(1000);
    return;
  }

  Serial.print("Sample OK: ");
  Serial.print((int)temperature); Serial.print(" *C, ");
  Serial.print((int)humidity); Serial.println("% H");

  // DHT11 sampling rate is 1HZ.
  delay(1500);
}
