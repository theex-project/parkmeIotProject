/*
 Park.Me! Project by Theex.org
 Transportation and Public Facility Project Section based on Internet of Things
 This code is in the private domain

 This project also in github.com/theex-project/SmartIotProjects
 Regards, Developer

 Copyright (c) 2016 Copyright Holder All Rights Reserved.
*/

//define libraries
#include <Wire.h>

//define pins
#define addr 0x1E

//define global variables

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Wire.begin();
  Wire.beginTransmission(addr); //start talking
  Wire.write(0x02); // Set the Register
  Wire.write(0x00); // Tell the HMC5883 to Continuously Measure
  Wire.endTransmission();
}

void loop() {
  // put your main code here, to run repeatedly:
  int x,y,z; //triple axis data

 //Tell the HMC what regist to begin writing data into
 Wire.beginTransmission(addr);
 Wire.write(0x03); //start with register 3.
 Wire.endTransmission();

 //Read the data.. 2 bytes for each axis.. 6 total bytes
 Wire.requestFrom(addr, 6);
 if(6<=Wire.available()){
   x = Wire.read()<<8; //MSB  x
   x |= Wire.read(); //LSB  x
   z = Wire.read()<<8; //MSB  z
   z |= Wire.read(); //LSB z
   y = Wire.read()<<8; //MSB y
   y |= Wire.read(); //LSB y
 }

 // Show Values
 Serial.print("X Value: ");
 Serial.println(x);
 Serial.print("Y Value: ");
 Serial.println(y);
 Serial.print("Z Value: ");
 Serial.println(z);
 Serial.println();

 delay(1000);
}
