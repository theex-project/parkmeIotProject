/*
  Park.Me! Project by Theex.org
  Transportation and Public Facility Project Section based on Internet of Things
  This code is in the private domain

  This project also in github.com / theex - project / parkmeIotProject
  Regards, Developer

  Copyright (c) 2016 Copyright Holder All Rights Reserved.
*/

//define libraries
#include <SPI.h>
#include <Ethernet.h>
#include <PubSubClient.h>

//define pins

//define global variables
byte mac[]  = {  0x98, 0x4F, 0xEE, 0x00, 0x96, 0xD9 };
IPAddress ip(192, 168, 100, 28);
IPAddress server(188, 166, 254, 81); //domain hub-ex.xyz 188.166.254.81

#define ledPin 4
char data;
char* lastStatus;

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();
}

EthernetClient ethClient;
PubSubClient client(ethClient);
long lastMsg = 0;
char msg[50];
int value = 0;

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (client.connect("arduinoClient", "admintes", "admin123")) {
      Serial.println("connected");
      // Once connected, publish an announcement...
      //client.publish("admintes/data","hello world");
      // ... and resubscribe
      //client.subscribe("inTopic");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      //delay(5000);
    }
  }
}

void setup() {
  Serial.begin(115200);

  client.setServer(server, 1883);
  client.setCallback(callback);

  Ethernet.begin(mac, ip);
  // Allow the hardware to sort itself out
  delay(1500);

  Serial1.begin(19200);
  Serial.println("Ready");
  pinMode (ledPin, OUTPUT);

}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  //client.loop();

  if (Serial1.available() > 0) {
    data = Serial1.read();
    //Serial.print(data);
    if (data == '0') {
      digitalWrite(ledPin, HIGH);
      //lastStatus = "0";
      value = 0;
      // kondisi normal (tidak ada mobil dan lampu menyala
    } if (data == '1') {
      digitalWrite(ledPin, LOW); // kondisi ada mobil dan lampu mati
      //lastStatus = "1";
      value = 1;
    }
  }

  snprintf (msg, 75, "%ld", value);
  Serial.print("Mobil ada : ");
  Serial.println(msg);
  client.publish("admintes/data", msg);

  //Serial.println(lastStatus);
  //client.publish("admintes/data", lastStatus);


  delay(300);

}
