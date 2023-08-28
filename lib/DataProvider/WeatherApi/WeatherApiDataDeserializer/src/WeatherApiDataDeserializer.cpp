#include "WeatherApi/WeatherApiDataDeserializer/include/WeatherApiDataDeserializer.hpp"


void WeatherApiDataDeserializer::deserialize(const String& jsonData, WeatherApiData* weatherData) {
    // Parsing jsonData by https://arduinojson.org/v6/assistant/
    const size_t capacity = JSON_ARRAY_SIZE(1) + JSON_OBJECT_SIZE(1) + 2*JSON_OBJECT_SIZE(2) + JSON_OBJECT_SIZE(4) + JSON_OBJECT_SIZE(5) + JSON_OBJECT_SIZE(6) + JSON_OBJECT_SIZE(13) + 280;
    DynamicJsonDocument doc(capacity);
    deserializeJson(doc, jsonData);

    JsonObject weather_0 = doc["weather"][0];
    const char* weather_0_main = weather_0["main"];
    const char* weather_0_description = weather_0["description"];
    JsonObject main = doc["main"];
    float main_temp = main["temp"];
    int main_pressure = main["pressure"];
    int main_humidity = main["humidity"];
    float wind_speed = doc["wind"]["speed"];

    setWeatherDescription(weatherData, weather_0_main, weather_0_description);
    weatherData->setTemperature(main_temp);
    weatherData->setPressure(main_pressure);
    weatherData->setHumidity(main_humidity);
    weatherData->setWindSpeed(wind_speed);
}

void WeatherApiDataDeserializer::setWeatherDescription(WeatherApiData* weatherData, const char* descriptionMain, const char* descriptionFull) {
    int descriptionFullLength = ((String) descriptionFull).length();
    if (descriptionFullLength > 16) {
        weatherData->setDescription(descriptionMain);
    } else {
        weatherData->setDescription(descriptionFull);
    }
}
