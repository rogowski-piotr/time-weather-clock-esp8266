#include <Arduino.h>
#include "secrets.hpp"
#include "WiFiConnection/include/WiFiConnection.hpp"
#include "WeatherApiData/WeatherApiDataProvider/include/WeatherApiDataProvider.hpp"
#include "TimeApiData/TimeApiDataProvider/include/TimeApiDataProvider.hpp"

TimeApiDataProvider timeApiDataProvider;
TimeData timeData;

WeatherApiDataProvider weatherApiDataProvider;
WeatherData weatherData;

void setup() {
    Serial.begin(9600);
    connectToWiFi(SECRET_SSID, SECRET_PASS);
}

void loop() {
    timeApiDataProvider.getTimeData(&timeData);
    Serial.println(timeData.year);
    Serial.println(timeData.month);
    Serial.println(timeData.day);
    Serial.println(timeData.hour);
    Serial.println(timeData.minute);
    Serial.println(timeData.second);
    Serial.println(timeData.data_received);

    Serial.println("\n");

    weatherApiDataProvider.getWeatherData(&weatherData, OPEN_WEATHER_MAP_API_KEY, CITY_ID);
    Serial.println(weatherData.description);
    Serial.println(weatherData.temperature);
    Serial.println(weatherData.pressure);
    Serial.println(weatherData.humidity);
    Serial.println(weatherData.wind_speed);
    Serial.println(weatherData.data_received);

    delay(60000);
}
