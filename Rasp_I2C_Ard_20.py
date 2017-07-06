import site
import smbus
import time

# Choose I2C1 bus
bus = smbus.SMBus(1)
# Address for the Arduino board we are communicating
address = 0x08
# Arduino input to use to check alignment of LSB and MSB
reference_pin = 3
# Time between sample reads
time_delay = 1
# Arduino input to get analog sample
Arduino_pin = 0

# Function to write to I2C bus
def writeNumber(value):
	try:
		bus.write_byte(address, value)
	except:
		print "Can not access I2C bus!"
	return -1

# Function to read from I2C bus
def readNumber():
	try:
		number = bus.read_byte(address)
	except:
		print "Can not access I2C bus!"
		return -1
	return number

while (True):

# Get reference pin data

	writeNumber(reference_pin)

# Get data from Arduino via I2C
	MSB = readNumber()
# Check to see if value is MSB, if MSB > 4, then it is LSB
	if (MSB > 4):
		MSB = readNumber()
	LSB = readNumber()
##		ADC_1024 = (MSB * 256) + LSB

# Get analog input data

	writeNumber(Arduino_pin)

# Get data from Arduino via I2C
	MSB = readNumber()
# Check to see if value is MSB, if MSB > 4, then it is LSB
	if (MSB > 4):
		MSB = readNumber()
	LSB = readNumber()
# Calculate ADC from MSB and LSB
	ADC_1024 = (MSB * 256) + LSB

	print ADC_1024
	time.sleep(time_delay)
	continue
