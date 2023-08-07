#include <ArduinoJson.h>
#include "WeatherData.h"
#include "GenericHttpClient.h"
#include "secrets.h"

String BASE_URL = "api.openweathermap.org";

void getWeatherData(WeatherData* weatherData) {
  int httpStatusCode = -1;
  String url = buildURL();
  String result = httpGet(url, httpStatusCode);
  deserializeWeatherData(result, weatherData);

  if (httpStatusCode == 200) {
     weatherData->data_received = true;
  } else {
    weatherData->data_received = false;
  }
}

String buildURL() {
  return "http://" + BASE_URL +
    "/data/2.5/weather?id=" + CITY_ID +
    "&units=metric&APPID=" + OPEN_WEATHER_MAP_API_KEY;
}

void deserializeWeatherData(const String& jsonData, WeatherData* weatherData) {
  // Parsing jsonData by https://arduinojson.org/v6/assistant/
  const size_t capacity = JSON_ARRAY_SIZE(1) + JSON_OBJECT_SIZE(1) + 2*JSON_OBJECT_SIZE(2) + JSON_OBJECT_SIZE(4) + JSON_OBJECT_SIZE(5) + JSON_OBJECT_SIZE(6) + JSON_OBJECT_SIZE(13) + 280;
  DynamicJsonDocument doc(capacity);
  deserializeJson(doc, jsonData);

  // float coord_lon = doc["coord"]["lon"]; // 18.65
  // float coord_lat = doc["coord"]["lat"]; // 54.35
  JsonObject weather_0 = doc["weather"][0];
  // int weather_0_id = weather_0["id"]; // 802
  const char* weather_0_main = weather_0["main"]; // "Clouds"
  const char* weather_0_description = weather_0["description"]; // "scattered clouds"
  // const char* weather_0_icon = weather_0["icon"]; // "03d"
  // const char* base = doc["base"]; // "stations"
  JsonObject main = doc["main"];
  float main_temp = main["temp"]; // 12.9
  // float main_feels_like = main["feels_like"]; // 5.61
  // float main_temp_min = main["temp_min"]; // 12.78
  // int main_temp_max = main["temp_max"]; // 13
  int main_pressure = main["pressure"]; // 1016
  int main_humidity = main["humidity"]; // 50
  // int visibility = doc["visibility"]; // 10000
  float wind_speed = doc["wind"]["speed"]; // 8.2
  // int wind_deg = doc["wind"]["deg"]; // 320
  // int clouds_all = doc["clouds"]["all"]; // 40
  // long dt = doc["dt"]; // 1588769941
  // JsonObject sys = doc["sys"];
  // int sys_type = sys["type"]; // 1
  // int sys_id = sys["id"]; // 1696
  // const char* sys_country = sys["country"]; // "PL"
  // long sys_sunrise = sys["sunrise"]; // 1588733808
  // long sys_sunset = sys["sunset"]; // 1588789628
  // int timezone = doc["timezone"]; // 7200
  // long id = doc["id"]; // 3099434
  // const char* name = doc["name"]; // "Gdańsk"
  // int cod = doc["cod"]; // 200

  setWeatherDescription(weatherData, weather_0_main, weather_0_description);
  weatherData->temperature = main_temp;
  weatherData->pressure = main_pressure;
  weatherData->humidity = main_humidity;
  weatherData->wind_speed = wind_speed;
}

void setWeatherDescription(WeatherData* weatherData, const char* descriptionMain, const char* descriptionFull) {
  if (((String) descriptionFull).length() > 16) {
    weatherData->description = descriptionMain;
  } else {
    weatherData->description = descriptionFull;
  }
}
