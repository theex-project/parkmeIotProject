/*
  Park.Me! Project by Theex.org
  Transportation and Public Facility Project Section based on Internet of Things
  This code is in the private domain

  This project also in github.com/theex-project/parkmeIotProject
  Regards, Developer

  Copyright (c) 2016 Copyright Holder All Rights Reserved.
*/

//define libraries
#include <SPI.h>
#include <Ethernet.h>
#include <PubSubClient.h>

//define pins

//define global variables
byte mac[]    = {  0xDE, 0xED, 0xBA, 0xFE, 0xFE, 0xED };
IPAddress ip(172, 16, 0, 100);
IPAddress server(188, 166, 254, 81); //domain hub-ex.xyz 188.166.254.81

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

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (client.connect("arduinoClient", "admintes", "admin123")) {
      Serial.println("connected");
      // Once connected, publish an announcement...
      // client.publish("admintes/data","hello world");
      // ... and resubscribe
      //client.subscribe("inTopic");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(57600);

  client.setServer(server, 1883);
  client.setCallback(callback);

  Ethernet.begin(mac, ip);
  // Allow the hardware to sort itself out
  delay(1500);
}

void loop()
{
  if (!client.connected()) {
    reconnect();
  }

  //get Sensor Value from nano as hub extention
  int d = 0;
  while (Serial.available() > 0) {
    d = Serial.read();
  }
  char* data = (char*)d;
  //Serial.println(data);
  client.publish("admintes/data", data);
  client.loop();
}
