#ifndef WeatherApiDataProvider_h
#define WeatherApiDataProvider_h

#include <ArduinoJson.h>
#include "DataProvider/GenericApiData.h"
#include "Utils/GenericHttpClient.h"
#include "secrets.h"


struct WeatherData : public GenericApiData {
    const char* description;
    float temperature;
    int pressure;
    int humidity;
    float wind_speed;
};

class WeatherApiDataProvider {
public:
    void getWeatherData(WeatherData* weatherData);

private:
    GenericHttpClient httpClient = GenericHttpClient();

    static String BASE_URL;

    static String buildURL();

    static void deserializeWeatherData(const String& jsonData, WeatherData* weatherData);

    static void setWeatherDescription(WeatherData* weatherData, const char* descriptionMain, const char* descriptionFull);
};

#endif
