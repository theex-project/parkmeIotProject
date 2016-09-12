import time
import requests
import sys
import json
import requests.packages.urllib3
import paho.mqtt.client as paho

#Setup a loop to send Temperature values at fixed intervals
fixed_interval = 1
start_interval = 2

#Init Firebase
firebase_url = 'https://ramean.firebaseio.com/parkme'
auth_token = 'wZMtcMP8WNLhjwCeSSR0idwy3TAzyZlnQe3MnmAG'

def on_subscribe(client, userdata, mid, granted_qos):
    print("Subscribed: "+str(mid)+" "+str(granted_qos))

def on_message(client, userdata, msg):
    # print(msg.topic+" "+str(msg.qos)+" "+str(msg.payload))
    strValue = str(msg.payload)
    #print msg
	dataSensor = {'value':strValue}
	dirSensor = 'slotPark'
	requests.packages.urllib3.disable_warnings()
	result = requests.put(firebase_url + '/' + dirSensor + '/.json' + '?auth=' + auth_token, data=json.dumps(dataSensor))
	print 'Record inserted. Result Code = ' + str(result.status_code)
	print '------------------------------------------\n'

def main():

	try:
		print '============================'
		print 'Welcome to ParkMe-Monitoring'
		print '     Getting Started...     '
		print '============================\n'
		time.sleep(start_interval)

		print "setting paho client"
		client = paho.Client()
		client.username_pw_set("admintes", "admin123")
		client.on_subscribe = on_subscribe
		client.on_message = on_message
		client.connect("hub-ex.xyz", 1883)
		client.subscribe("admintes/parkme", 0)

		client.loop_forever()

	except IOError:
		print('Error! Something went wrong.')
	except KeyboardInterrupt:
		print('\n\nOPERATION HAS BEEN CANCELED!\n')
		sys.exit()

	print 'System has been exit'
	sys.exit()

if __name__ == '__main__':main()
