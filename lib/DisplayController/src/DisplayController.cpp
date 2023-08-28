#include "DisplayController.hpp"

void DisplayController::showData(const BaseApiData& data) {
    if (data.getClassType() == CLASS_TIME_API_DTO) {
        Serial.println("Time");
        const TimeApiData* timeData = (const TimeApiData*)&data;
        Serial.println("timeData->getYear()");
        Serial.println(timeData->getYear());
        Serial.println("timeData->getMonth()");
        Serial.println(timeData->getMonth());
        Serial.println("timeData->getDay()");
        Serial.println(timeData->getDay());
        Serial.println("timeData->getHour()");
        Serial.println(timeData->getHour());
        Serial.println("timeData->getMinute()");
        Serial.println(timeData->getMinute());
        Serial.println("timeData->getSecond()");
        Serial.println(timeData->getSecond());
        Serial.println("timeData->isCorrectlyReceivedData()");
        Serial.println(timeData->isCorrectlyReceivedData());
        Serial.println("\n");



    } else if (data.getClassType() == CLASS_WEATHER_API_DTO) {
        Serial.println("Weather");
        const WeatherApiData* weatherData = (const WeatherApiData*)&data;

        Serial.println("weatherData->getDescription()");
        Serial.println(weatherData->getDescription());
        Serial.println("weatherData->getTemperature()");
        Serial.println(weatherData->getTemperature());
        Serial.println("weatherData->getPressure()");
        Serial.println(weatherData->getPressure());
        Serial.println("weatherData->getHumidity()");
        Serial.println(weatherData->getHumidity());
        Serial.println("weatherData->getWindSpeed()");
        Serial.println(weatherData->getWindSpeed());
        Serial.println("weatherData->isCorrectlyReceivedData()");
        Serial.println(weatherData->isCorrectlyReceivedData());

    }
}