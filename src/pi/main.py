import os
import time
from smbus import SMBus

debug = True
bus = SMBus(1) # indicates /dev/ic2-1
# To check for enabled type "ls /dev/*i2c*" in cmd

#TODO send commands to arduino to retrieve information
