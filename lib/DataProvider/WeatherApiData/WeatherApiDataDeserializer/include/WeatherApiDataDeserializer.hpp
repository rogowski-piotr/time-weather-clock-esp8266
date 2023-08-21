#ifndef WeatherApiDataDeserializer_h
#define WeatherApiDataDeserializer_h

#include <ArduinoJson.h>
#include "GenericApiData.hpp"


struct WeatherData : public GenericApiData {
    const char* description;
    float temperature;
    int pressure;
    int humidity;
    float wind_speed;
};

class WeatherApiDataDeserializer {
public:
    static void deserialize(const String& jsonData, WeatherData* weatherData);

private:
    static void setWeatherDescription(WeatherData* weatherData, const char* descriptionMain, const char* descriptionFull);
};

#endif
