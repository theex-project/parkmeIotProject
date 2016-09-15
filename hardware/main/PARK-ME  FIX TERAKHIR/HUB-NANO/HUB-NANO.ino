#include <SPI.h>
#include <Mirf.h>
#include <nRF24L01.h>
#include <MirfSpiDriver.h>
#include <MirfHardwareSpiDriver.h>

const char payload_length = 32;
byte data[payload_length];

boolean terima() {
  if (!Mirf.isSending() && Mirf.dataReady()) {
    Mirf.getData(data);
    Serial.println((char*)data);
    //Serial.write((char*)data);
    return true;
    } else {
    Serial.println((char*)data);
    //Serial.write((char*)data);
    return false;
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(19200);
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
