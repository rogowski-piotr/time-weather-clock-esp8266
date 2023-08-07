#include <Arduino.h>
#include "WiFiConnection.h"
#include "WeatherData.h"


WeatherData weatherData;

void setup() {
  Serial.begin(9600);
  connectToWiFi();
}

void loop() {
  getWeatherData(&weatherData);

  Serial.println(weatherData.description);
  Serial.println(weatherData.temperature);
  Serial.println(weatherData.pressure);
  Serial.println(weatherData.humidity);
  Serial.println(weatherData.wind_speed);
  Serial.println(weatherData.data_received);

  delay(60000);
}
