/*
 Park.Me! Project by Theex.org
 Transportation and Public Facility Project Section based on Internet of Things
 This code is in the private domain

 This project also in github.com/theex-project/parkmeIotProject
 Regards, Developer

 Copyright (c) 2016 Copyright Holder All Rights Reserved.
*/

//define libraries
#include <Wire.h> library I2C
#include <SPI.h>
#include <Mirf.h>
#include <nRF24L01.h>
#include <MirfHardwareSpiDriver.h>

//define pinss
#define ledPin 5

//define global variables
#define sensor 0x1E // alamat default address sensor hmc5883l
const char payload_length = 32;
byte data[payload_length];
// float sensorParam = 0 ;

void sendData(int sensorParam) {
 String sensorVal = String(sensorParam);
 char data[32];
 sensorVal.toCharArray(data, 32);
 Mirf.send((byte*) data);
 //delay(1000);
}

void setup() {
  Serial.begin(9600);
  Wire.begin();
  Wire.beginTransmission(sensor);
  Wire.write(0x02);
  Wire.write(0x00);
  Wire.endTransmission();
  pinMode(ledPin, OUTPUT);
  //NRF
  Mirf.spi = &MirfHardwareSpi;
  Mirf.init();
  Mirf.setTADDR((byte *)"serve");
  Mirf.payload = payload_length;
  Mirf.channel = 123;
  Mirf.config();
}

void loop() {
  int Z; // sumbu Z pada sensor HMCL5883l

  Wire.beginTransmission(sensor);
  Wire.write(0x05);
  Wire.endTransmission();

  //Read data from each axis, 2 registers per axis
  Wire.requestFrom(sensor, 6);
  if (6 <= Wire.available()) {
    Z = Wire.read() << 8; //Z msb
    Z |= Wire.read(); //Z lsb
  }
    
  Serial.println(Z); // MEDAN MAGNET SUMBU Z BERADA PADA RANGE 300 - 500

  if ((Z >= 400) && (Z <= 600)) {   // kalibrasi sesuai tempat
    digitalWrite(ledPin, HIGH); // kondisi normal (tidak ada mobil dan lampu menyala)
    sendData(0);
  } else {
    digitalWrite(ledPin, LOW); // kondisi ada mobil dan lampu mati
    sendData(1);
  }
  delay (1000);
}
