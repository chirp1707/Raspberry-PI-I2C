#include <Wire.h>

#define SLAVE_ADDRESS 0x08

int number = 0;
int sensorPin1;
int sensorValue1 = 0;
int sensorValue1_MSB = 0;
int sensorValue1_LSB = 0;
int toggle_high = 1;
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 13;


void setup(){

	// initialize i2c as slave
	Wire.begin(SLAVE_ADDRESS);		
	
	//define callbacks for i2c communication
	Wire.onReceive(receiveData);
	Wire.onRequest(sendData);
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);  
}
///////////////////////////////
void loop(){

	delay(100);
}
///////////////////////////////
// callback for received data
void receiveData (int byteCount){

	while(Wire.available()){
		number = Wire.read();

		if (number == 0) sensorPin1 = A0;
		if (number == 1) sensorPin1 = A1;
		if (number == 2) sensorPin1 = A2;
		if (number == 3) sensorPin1 = A3;
		if (number == 4) sensorPin1 = A4;
		if (number == 5) sensorPin1 = A5;
                if (number == 13) digitalWrite(led, HIGH);  // turn the LED on
                if (number == 23) digitalWrite(led, LOW);   // turn the LED off 

		sensorValue1 = analogRead(sensorPin1);
		sensorValue1_MSB = sensorValue1 / 256;
		sensorValue1_LSB = sensorValue1 - (sensorValue1_MSB * 256);  
	}
}
/////////////////////////////////// 
// callback for sending data
void sendData(){
 	 	
	if (sensorValue1_MSB > 4) toggle_high = 0; 

	if (toggle_high == 1){
		Wire.write(sensorValue1_MSB);
		toggle_high = 0;
	}
	else{
		Wire.write(sensorValue1_LSB);
		toggle_high = 1;
	}
}	
