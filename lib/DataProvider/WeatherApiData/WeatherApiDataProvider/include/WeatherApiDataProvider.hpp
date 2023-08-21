#ifndef WeatherApiDataProvider_h
#define WeatherApiDataProvider_h

#include "WeatherApiData/WeatherApiDataDeserializer/include/WeatherApiDataDeserializer.hpp"
#include "GenericHttpClient/include/GenericHttpClient.hpp"


class WeatherApiDataProvider {
public:
    void getWeatherData(WeatherData* weatherData, String api_key, String city_id);

private:
    GenericHttpClient httpClient = GenericHttpClient();

    static String BASE_URL;

    static String buildURL(String api_key, String city_id);
};

#endif
