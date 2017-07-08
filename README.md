# Raspberry-PI-I2C-Arduino

Many projects require the use of an A/D converter. There are expansion boards the implement this function. This project utilizes a different method using an Arduino to add a 10 bit A/D converter via the I2C capability of the Raspberry-PI.

Using an Arduino rather than an expansion board offer many advantages:
1) Lower cost
2) Protecting the Raspberry-PI from possible damage by separating the input-output function from the Raspberry-PI.
3) Better voltage regulation. The Arduino can use its own power supply.
4) The ability to interface multiple (possible 128) Arduinos to 1 Raspberry-PI.

This method has been successfully tested with the Arduino Leonardo, Arduino Uno, and the Arduino Nano. It has been unsuccessful tested with the Arduino Due and Arduino 101.

There have been other articles describing using the Arduino A/D for the Raspberry-PI via I2C. This software sends data from the Arduino to the Raspberry-PI via I2C using (8 bit) bytes. The software on the Arduino takes the 10 bit data from the A/D converter, breaks it into 2 (8 bit) bytes and sends it to the Raspberry-PI. The software on the Raspberry-PI looks at these 2 (8 bit) bytes and correctly assembles them back into the 10 bit A/D data. This is the major development of this project.

To implement this project:
1. Enable the I2C function in the Raspberry-PI in the Raspberry PI configuration table.
2. Add “dtparam=i2c_baudrate=25000” to the config.txt file located in the /boot directory. This slows down the i2c rate.
3. Install the Arduino programing software on the Raspberry PI by using “sudo apt-get install Arduino”
4. Go to www.github.com and search for “Raspberry-PI-I2C-Arduino”, then download this as a zip file. Using the file manager go the download directory and unzip the file. Move the unzipped directory into the home directory.
5. Program the Arduino e.g. by going to Programming then Arduino IDE. Once the IDE opens, in the IDE click on File, then Open and go to the unzipped downloaded file that the extension is “ino”, click open.
6. In the upper left corner of the IDE is a check mark, click on it. This compiles and verifies the Arduino file.
7. Connect a usb cable from the Raspberry PI to the usb connector on the Arduino.
8. Click on Tools and select Boards. Choose the Arduino that is being used. For example, Arduino Leonardo.
9. Click on Tools and select Serial Port, /dev/ACM0.
10. In the upper left corner of the IDE is an arrow that points to the right, click on it and this should program the Arduino. If everything goes correctly, it will display “Done uploading.
11. Using one of the many diagrams of the Raspberry GPIO, connect the SDA, SCL and ground between the Raspberry PI and the Arduino. The Arduino pins are labeled.
12. Run the command “i2cdetect –y 1”. You should get a display of the i2c connections.
13. The input voltage to be measured should be connected to pin A0 on the Arduino. In order for the Raspberry PI software to align the bytes correctly, pin A3 needs to be connected to pin 5 volts. For testing purposes, connect pin 5 volts to pin A0. 
14. Run the program by entering “python Rasp_I2C_Ard_20.py.” The display should update once a second with 1023, which represents 5 volts.
15. For testing purposes, leave the usb cable attached between the Raspberry PI and Arduino to power the Arduino. The Arduino will function better if it has its own 5 volt supply from a separate usb power supply. The Arduino will even better if a separate external power is supplied to the Arduino. Arduinos have a voltage regulator built onto the board.


