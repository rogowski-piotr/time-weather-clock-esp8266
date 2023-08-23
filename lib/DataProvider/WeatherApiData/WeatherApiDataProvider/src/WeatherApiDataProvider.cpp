#include "WeatherApiData/WeatherApiDataProvider/include/WeatherApiDataProvider.hpp"


String WeatherApiDataProvider::BASE_URL =  "api.openweathermap.org";

void WeatherApiDataProvider::getWeatherData(WeatherData* weatherData, String api_key, String city_id) {
    int httpStatusCode = -1;
    String url = buildURL(api_key, city_id);
    String result = httpClient.httpGet(url, httpStatusCode);

    if (httpStatusCode == 200) {
        WeatherApiDataDeserializer::deserialize(result, weatherData);
        weatherData->data_received = true;
    } else {
        weatherData->data_received = false;
    }
}

String WeatherApiDataProvider::buildURL(String api_key, String city_id) {
    return "https://" + BASE_URL +
        "/data/2.5/weather?id=" + city_id +
        "&units=metric&APPID=" + api_key;
}
