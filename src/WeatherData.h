#ifndef WeatherData_h
#define WeatherData_h

#include <ESP8266WiFi.h>

struct WeatherData {
  const char* description;
  float temperature;
  int pressure;
  int humidity;
  float wind_speed;
};

void getWeatherData(WiFiClient& client, WeatherData* weatherData);

void setWeatherDescription(WeatherData* weatherData, const char* descriptionMain, const char* descriptionFull);

String fetchDataFromAPI(WiFiClient& client);

void deserializeWeatherData(const String& jsonData, WeatherData* weatherData);

#endif
