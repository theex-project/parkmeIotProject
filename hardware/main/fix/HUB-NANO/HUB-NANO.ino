/*
 hubX (Extention) - Universal Hub Project made by Theex.org
 Wireless Sensor Communication Section based on Internet of Things
 This code is in the private domain

 This project also in github.com/theex-project/SmartIotProjects
 Regards, Developer

 Copyright (c) 2016 Copyright Holder All Rights Reserved.
*/

//define libraries
#include <SPI.h>
#include <Mirf.h>
#include <nRF24L01.h>
#include <MirfSpiDriver.h>
#include <MirfHardwareSpiDriver.h>

//define pins


//define global variables
const char payload_length = 32;
byte data[payload_length];

boolean terima() {
  if (!Mirf.isSending() && Mirf.dataReady()) {
    Mirf.getData(data);
    Serial.println((char*)data);
    //Serial.write((char*)data);
    return true;
    //count_det = 1;
    //count_on = 1;
  } else {
    Serial.println((char*)data);
    //Serial.write((char*)data);
    return false;
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(57600);
  Mirf.spi = &MirfHardwareSpi;
  Mirf.init();
  Mirf.setRADDR((byte *)"serve");
  Mirf.payload = payload_length;
  Mirf.channel = 123;
  Mirf.config();
}

void loop() {
  boolean statusNrf = terima();
  delay(1000);
  /*if (!statusNrf) {
    Serial.println("NRF blm terdeksi");
  }*/

}
