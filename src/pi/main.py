import os
import time
import Humidity as Humidity

debug = True
hum = Humidity(4);

try:
    f = open('/media/pi/data/humidity.csv', 'a+')
    if os.stat('/media/pi/data/humidity.csv').st_size == 0:
        f.write('Date,Time,Temperature,Humidity\r\n')

    while True:
        # Print date
        if debug:
            print('{0}\t'.format(time.strftime('%H:%M')))

        # Humidity sensor data
        humidity, temperature = hum.getValue()
        if humidity is not None and temperature is not None:
            f.write('{0},{1},{2:0.1f}*F,{3:0.1f}%\r\n'.format(time.strftime('%m/%d/%y'), time.strftime('%H:%M'), temperature, humidity))
            if debug:
                print('{0:0.1f}*F\t{1:0.1f}%'.format(temperature, humidity))
        elif debug:
            print("Failed to retrieve data from humidity sensor")

        # Print new line
        if debug:
            print ('\n')

        # Sleep for 30 seconds
        time.sleep(30)

except:
    pass

finally:
    hum.close()
