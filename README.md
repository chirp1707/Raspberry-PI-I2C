Raspberry-PI-I2C-Arduino

Many projects require the use of an A/D converter. There are expansion boards the implement this function. This project utilizes a different method using an Arduino to add a 10 bit A/D converter via the I2C capability of the Raspberry-PI.

Using an Arduino rather than an expansion board offer many advantages:
1) Lower cost
2) Protecting the Raspberry-PI from possible damage by separating the input-output function from the Raspberry-PI.
3) Better voltage regulation. The Arduino can use its own power supply.
4) The ability to interface multiple (possible 128) Arduinos to 1 Raspberry-PI.


There have been other articles describing using the Arduino A/D for the Raspberry-PI via I2C. The major development of this project is that it utilizes the 10 bit A/D converter on the Arduino. It breaks the 10 bit data into 2 8 bit bytes which it sends to the Raspberry PI. The Raspberry PI then correctly reassembles these 2 8 bit bytes back into the 10 bit A/D converter output.

This method has been successfully tested with the Arduino Leonardo, Arduino Uno, and the Arduino Nano. It has been unsuccessful tested with the Arduino Due and Arduino 101.

To implement this project:
1. Enable the I2C function in the Raspberry-PI in the Raspberry PI configuration table.
2. Add “dtparam=i2c_baudrate=25000” to the config.txt file located in the /boot directory. This slows down the i2c rate.
3. Install the Arduino programing software on the Raspberry PI by using “sudo apt-get install arduino”
4. Go to www.github.com and search for “Raspberry-PI-I2C-Arduino”, then download this as a zip file. Using the file manager, select the downloaded file, then unzip it. Move the unzipped directory into the home directory.
5. Program the Arduino by clicking on the Raspberry, select Programming, then select Arduino IDE. In the IDE select File, then select Open and go to the unzipped downloaded file that the extension is “ino”, click open.
6. In the upper left corner of the IDE is a check mark, click on it. This compiles and verifies the Arduino file.
7. Connect a usb cable from the Raspberry PI to the usb connector on the Arduino.
8. Click on Tools and select Boards. Choose the Arduino that is being used. For example, Arduino Leonardo.
9. Click on Tools and select Serial Port, /dev/ACM0.
10. In the upper left corner of the IDE is an arrow that points to the right, click on it and this should program the Arduino. If everything goes correctly, it will display “Done uploading.
11. Using one of the many diagrams of the Raspberry GPIO, connect the SDA, SCL and ground between the Raspberry PI and the Arduino. The Arduino pins are labeled.
12. Run the command “i2cdetect –y 1”. This will display of the i2c connections.
13. The input voltage to be measured should be connected to pin A0 on the Arduino. In order for the Raspberry PI software to align the bytes correctly, pin A3 needs to be connected to pin 5 volts. For testing purposes, connect pin 5 volts to pin A0. 
14. Run the program by entering “python Rasp_I2C_Ard_20.py”. The display should update once a second with 1023, which represents 5 volts. Move the A0 connection to 3.3 V on the Arduino, the display should change to 686. Move the A0 connection to GND, the display should change to 0.
15. For testing purposes, leave the usb cable attached between the Raspberry PI and Arduino to power the Arduino. The 10 bit A/D stability will be improved if a separate usb converter is used to power the Arduino. The 10 bit A/D stability would be further improved if a 9V power adapter is used power the Arduino via the barrel plug on the Arduino.


