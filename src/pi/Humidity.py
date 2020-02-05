import Adafruit_DHT

class Humidity:

    def __init__(self, pin):
        self.pin = pin

    def getValue(self):
        humidity, temperature = Adafruit_DHT.read_retry(Adafruit_DHT.DHT11, pin)
        temperature = (temperature * 1.8) + 32
        return (humidity, temperature)
