import urllib.request, json
import re
#Google MapsDdirections API endpoint
endpoint = 'https://maps.googleapis.com/maps/api/directions/json?'
api_key = 'AIzaSyD6XBYeHLK5sD7_PQkIh-NVyeRSz4dLIwg'
#Asks the user to input Where they are and where they want to go.
origin = input('Where are you?: ').replace(' ','+')
destination = input('Where do you want to go?: ').replace(' ','+')
#Building the URL for the request
nav_request = 'origin={}&destination={}&key={}'.format(origin,destination,api_key)
request = endpoint + nav_request
#Sends the request and reads the response.
response = urllib.request.urlopen(request).read()
#Loads response as JSON
directions = json.loads(response)
routes=directions['routes']
legs=routes[0]['legs']
seperation=legs[0]['distance']['text']
print(seperation)
res=re.findall(r"[-+]?\d*\.\d+|\d+", seperation)
new=res[0]
print('Fair of the journey:')
price=float(new)
if (price<10) :
    print(price*4)
elif (price>=10 and price<30):
    print(price*3)
elif (price>=30 and price<60):
    print(price*2)
elif (price>=60):
    print(price*1.1)

