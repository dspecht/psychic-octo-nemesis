# Get current weather for Little_Rock:(4119403)
import requests
import json

url = "https://community-open-weather-map.p.rapidapi.com/weather"

querystring = {"id":"4119403","units":"Imperial","mode":"json"}

headers = {
    'x-rapidapi-host': "community-open-weather-map.p.rapidapi.com",
    'x-rapidapi-key': "4fc24b1155msh74b976c53fbe648p192d4fjsn4f40b47dbb41"
    }

response = requests.request("GET", url, headers=headers, params=querystring)
data = response.json()

currentTemp = data["main"]["feels_like"]
minTemp = data["main"]["temp_min"]
maxTemp = data["main"]["temp_max"]
humidity = data["main"]["humidity"]

windDeg = data["wind"]["deg"]
windSpeed = data["wind"]["speed"]

#wType = data["weather"]["main"]
#wDescription = data["weather"]["description"]

print("\nCurrent Temp: %.2f F" % currentTemp)
#print("\nLow: %.2f F || High: %.2f F" % minTemp maxTemp)
print("Humidity: %.2f" % humidity)
#print("%s \n%s" % wType, wDescription)
#print("Direction: %f | Speed: %.2f" % windDeg, windSpeed)



