#ifndef WeatherApiDataProvider_h
#define WeatherApiDataProvider_h

#include "WeatherApi/WeatherApiDataDeserializer/include/WeatherApiDataDeserializer.hpp"
#include "GenericHttpClient/include/GenericHttpClient.hpp"
#include "WeatherApi/WeatherApiData.hpp"

class WeatherApiDataProvider {
public:
    void getWeatherData(WeatherApiData* weatherData, String api_key, String city_id);

private:
    GenericHttpClient httpClient = GenericHttpClient();

    static String BASE_URL;

    static String buildURL(String api_key, String city_id);
};

#endif
