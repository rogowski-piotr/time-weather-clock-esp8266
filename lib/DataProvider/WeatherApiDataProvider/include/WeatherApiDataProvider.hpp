#ifndef WeatherApiDataProvider_h
#define WeatherApiDataProvider_h

#include <ArduinoJson.h>
#include "GenericApiData.hpp"
#include "GenericHttpClient/include/GenericHttpClient.hpp"


struct WeatherData : public GenericApiData {
    const char* description;
    float temperature;
    int pressure;
    int humidity;
    float wind_speed;
};

class WeatherApiDataProvider {
public:
    void getWeatherData(WeatherData* weatherData, String api_key, String city_id);

private:
    GenericHttpClient httpClient = GenericHttpClient();

    static String BASE_URL;

    static String buildURL(String api_key, String city_id);

    static void deserializeWeatherData(const String& jsonData, WeatherData* weatherData);

    static void setWeatherDescription(WeatherData* weatherData, const char* descriptionMain, const char* descriptionFull);
};

#endif
