import paho.mqtt.client as paho

def on_subscribe(client, userdata, mid, granted_qos):
    print("Subscribed: "+str(mid)+" "+str(granted_qos))

def on_message(client, userdata, msg):
    # print(msg.topic+" "+str(msg.qos)+" "+str(msg.payload))
    msg = msg.payload
    #print msg
    print msg

client = paho.Client()
client.username_pw_set("admintes", "admin123")
client.on_subscribe = on_subscribe
client.on_message = on_message
client.connect("hub-ex.xyz", 1883)
client.subscribe("admintes/data", 0)

client.loop_forever()
