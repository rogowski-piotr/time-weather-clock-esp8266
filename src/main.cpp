#include <Arduino.h>
#include "config.hpp"
#include "secrets.hpp"
#include "NTPSynchronization/include/NTPSynchronization.hpp"
#include "WiFiConnection/include/WiFiConnection.hpp"
#include "WeatherApi/WeatherApiDataProvider/include/WeatherApiDataProvider.hpp"
#include "TimeApi/TimeApiDataProvider/include/TimeApiDataProvider.hpp"
#include "RealTimeSyncer.hpp"
#include "DisplayController.hpp"
#include "TimeApi/TimeApiData.hpp"
#include "WeatherApi/WeatherApiData.hpp"

TimeApiDataProvider timeApiDataProvider;
TimeApiData timeData;

WeatherApiDataProvider weatherApiDataProvider;
WeatherApiData weatherData;

IRAM_ATTR void BACKLIGHT_CONTROL() {
  Serial.println("interrupt");
}

void setup() {
    Serial.begin(9600);
    attachInterrupt(digitalPinToInterrupt(BACKLIGHT_PIN), BACKLIGHT_CONTROL, RISING);
    connectToWiFi(SECRET_SSID, SECRET_PASS);
    syncWithNTP(NTP_CONNECTION_TIMEOUT_MS);

    weatherApiDataProvider.getWeatherData(&weatherData, OPEN_WEATHER_MAP_API_KEY, CITY_ID);
    timeApiDataProvider.getTimeData(&timeData);
}

void loop() {
    DisplayController::showData(timeData);
    DisplayController::showData(weatherData);

    RealTimeSyncer::sync(&timeData, 120);
}
