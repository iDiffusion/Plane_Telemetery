import Adafruit_DHT

class Humidity(Sensor):

    def __init__(self, pin):
        self.sensor = Adafruit_DHT.DHT11
        self.pin = pin
        self.lastHumid = None
        self.lastTemp = None

    def getValue(self):
        humidity, temperature = Adafruit_DHT.read_retry(sensor, pin)
        temperature = (temperature * 1.8) + 32
        return (humidity, temperature)

    def close(self):
        pass
