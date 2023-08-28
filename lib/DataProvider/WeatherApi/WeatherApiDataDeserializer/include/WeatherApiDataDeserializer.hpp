#ifndef WeatherApiDataDeserializer_h
#define WeatherApiDataDeserializer_h

#include <ArduinoJson.h>
#include "WeatherApi/WeatherApiData.hpp"

class WeatherApiDataDeserializer {
public:
    static void deserialize(const String& jsonData, WeatherApiData* weatherData);

private:
    static void setWeatherDescription(WeatherApiData* weatherData, const char* descriptionMain, const char* descriptionFull);
};

#endif
