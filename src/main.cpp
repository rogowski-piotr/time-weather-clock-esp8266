#include <Arduino.h>
#include "config.hpp"
#include "secrets.hpp"
#include "NTPSynchronization/include/NTPSynchronization.hpp"
#include "WiFiConnection/include/WiFiConnection.hpp"
#include "WeatherApi/WeatherApiDataProvider/include/WeatherApiDataProvider.hpp"
#include "TimeApi/TimeApiDataProvider/include/TimeApiDataProvider.hpp"
#include "DisplayController.hpp"
#include "TimeApi/TimeApiData.hpp"
#include "WeatherApi/WeatherApiData.hpp"


TimeApiDataProvider timeApiDataProvider;
TimeApiData timeData;
unsigned long timeDataFetchedAt;

WeatherApiDataProvider weatherApiDataProvider;
WeatherApiData weatherData;
unsigned long weatherDataFetchedAt;

DisplayController displayController(CITY_NAME);

IRAM_ATTR void BACKLIGHT_CONTROL() {
	displayController.changeBacklight();
}

bool shouldFetchTimeData(unsigned long lastDataFetchedAt) {
	unsigned long elapsed = millis() - lastDataFetchedAt;
	return elapsed > TIME_TO_REFRESH_TIME_DATA_SEC * 1000;
}

bool shouldFetchWeatherData(unsigned long lastDataFetchedAt) {
	unsigned long elapsed = millis() - lastDataFetchedAt;
	return elapsed > TIME_TO_REFRESH_WEATHER_DATA_SEC * 1000;
}

void setup() {
    Serial.begin(9600);
    displayController.initDisplay();
    attachInterrupt(digitalPinToInterrupt(BACKLIGHT_PIN), BACKLIGHT_CONTROL, RISING);
    connectToWiFi(SECRET_SSID, SECRET_PASS, displayController.getLcdRef());
    syncWithNTP(NTP_CONNECTION_TIMEOUT_MS, displayController.getLcdRef());

	// fetch time and weather data first time
	timeApiDataProvider.getTimeData(&timeData);
	timeDataFetchedAt = millis();

	weatherApiDataProvider.getWeatherData(&weatherData, OPEN_WEATHER_MAP_API_KEY, CITY_ID);
	weatherDataFetchedAt = millis();
}

void loop() {
	if (shouldFetchTimeData(timeDataFetchedAt)) {
		timeDataFetchedAt = millis();
		timeApiDataProvider.getTimeData(&timeData);
	}

	if (shouldFetchWeatherData(weatherDataFetchedAt)) {
		weatherDataFetchedAt = millis();
		weatherApiDataProvider.getWeatherData(&weatherData, OPEN_WEATHER_MAP_API_KEY, CITY_ID);
	}

	displayController.showData(timeData, timeData, SHOW_TIME_DATA_SEC);
	displayController.showData(weatherData, timeData, SHOW_WEATHER_DATA_SEC);
}
