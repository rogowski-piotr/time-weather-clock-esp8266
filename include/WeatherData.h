#ifndef WeatherData_h
#define WeatherData_h

struct WeatherData {
  const char* description;
  float temperature;
  int pressure;
  int humidity;
  float wind_speed;
  bool data_received;
};

void getWeatherData(WeatherData* weatherData);

void setWeatherDescription(WeatherData* weatherData, const char* descriptionMain, const char* descriptionFull);

void deserializeWeatherData(const String& jsonData, WeatherData* weatherData);

String buildURL();

#endif
