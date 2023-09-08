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

WeatherApiDataProvider weatherApiDataProvider;
WeatherApiData weatherData;

DisplayController displayController(CITY_NAME);

IRAM_ATTR void BACKLIGHT_CONTROL() {
	displayController.changeBacklight();
}

bool shouldFetchData(unsigned long lastDataFetchedAt) {
	unsigned long elapsed = millis() - lastDataFetchedAt;
	return elapsed > TIME_TO_REFRESH_DATA_SEC * 1000;
}

void setup() {
    Serial.begin(9600);
    displayController.initDisplay();
    attachInterrupt(digitalPinToInterrupt(BACKLIGHT_PIN), BACKLIGHT_CONTROL, RISING);
    connectToWiFi(SECRET_SSID, SECRET_PASS, displayController.getLcdRef());
    syncWithNTP(NTP_CONNECTION_TIMEOUT_MS, displayController.getLcdRef());
}

void loop() {
    weatherApiDataProvider.getWeatherData(&weatherData, OPEN_WEATHER_MAP_API_KEY, CITY_ID);
    timeApiDataProvider.getTimeData(&timeData);
	unsigned long lastDataFetchedAt = millis();

	while (!shouldFetchData(lastDataFetchedAt)) {
		displayController.showData(timeData, timeData, SHOW_TIME_DATA_SEC);
		displayController.showData(weatherData, timeData, SHOW_WEATHER_DATA_SEC);
	}
}
