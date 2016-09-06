#include <Wire.h> library I2C
#define sensor 0x1E // alamat default address sensor hmc5883l

void setup() {
  Serial.begin(9600);
  Wire.begin();
  Wire.beginTransmission(sensor);
  Wire.write(0x02);
  Wire.write(0x00);
  Wire.endTransmission();
  pinMode(9, OUTPUT);
}

void loop() {
  int X, Y, Z; //triple axis data

  Wire.beginTransmission(sensor);
  Wire.write(0x07);
  Wire.endTransmission();


  //Read data from each axis, 2 registers per axis
  Wire.requestFrom(sensor, 6);
  if (6 <= Wire.available()) {
    Z = Wire.read() << 8; //Z msb
    Z |= Wire.read(); //Z lsb

  }

  Serial.print("  Medan magnet sumbu Z : ");  // MEDAN MAGNET SUMBU Z BERADA PADA RANGE 300 - 500
  Serial.println(Z);

  if (( Z <= 400 )  | (Z >= 450)) {
    digitalWrite(9, HIGH);
  }
  else {
    digitalWrite(9, LOW);

  }
 delay (1000);
}
