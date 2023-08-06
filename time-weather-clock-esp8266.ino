#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

#include "src/WiFiConnection.h"
#include "src/WeatherData.h"


WiFiClient client;
WeatherData weatherData;

void setup() {
  Serial.begin(9600);
  connectToWiFi();
}

void loop() {
  getWeatherData(client, &weatherData);

  Serial.println(weatherData.description);
  Serial.println(weatherData.temperature);
  Serial.println(weatherData.pressure);
  Serial.println(weatherData.humidity);
  Serial.println(weatherData.wind_speed);
  
  delay(10000);
}
