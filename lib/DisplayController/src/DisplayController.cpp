#include "DisplayController.hpp"

void DisplayController::initDisplay() {
    lcd.init();
    lcd.noBacklight();
    lcd.clear();
}

void DisplayController::changeBacklight() {
    if (isBacklight) {
        isBacklight = false;
        lcd.noBacklight();
    } else {
        isBacklight = true;
        lcd.backlight();
    }
}

void DisplayController::showTimeData(const TimeApiData& data) {
    lcd.clear();
    lcd.setCursor(5,0);

    // display time
    lcd.print(data.getHour());
    lcd.print(":");

    if (data.getMinute() < 10) {
        lcd.print("0");
    }
    lcd.print(data.getMinute());

    lcd.setCursor(10,0);
    lcd.print("   ");
    lcd.setCursor(3,1);

    // display date
    if (data.getDay() < 10) {
        lcd.print("0");
    }
    lcd.print(data.getDay());
    lcd.print(".");

    if (data.getMonth() < 10) {
        lcd.print("0");
    }
    lcd.print(data.getMonth());
    lcd.print(".");

    lcd.print(data.getYear());
}

void DisplayController::showWeatherData(const WeatherApiData& data) {
    lcd.clear();
    lcd.setCursor(0,0);

    // displaying temperature
    lcd.print("T:"); 
    lcd.print(data.getTemperature());
    lcd.print((char)223);
    lcd.print("C ");

    // displaying humidity
    lcd.print(" H:");
    lcd.print(data.getHumidity());
    lcd.print("%");

    // displaying pressure
    lcd.setCursor(0,1);
    lcd.print("P:");
    lcd.print(data.getPressure());
    lcd.print("hPa");

    // displaying wind
    lcd.print(" W:");
    lcd.print(int(data.getWindSpeed()));
    lcd.print("kmh");
}

void DisplayController::showWeatherDespription(const WeatherApiData& data) {
    lcd.clear();
    lcd.setCursor(0,0);

    // displaying description and city
    lcd.print("   " + cityName + " now:");
    lcd.setCursor(0, 1);
    lcd.print(data.getDescription());
}

void DisplayController::showData(const BaseApiData& dataToShow, TimeApiData& timeDataToSync, int timeToShowSec) {
    if (dataToShow.getClassType() == CLASS_TIME_API_DTO) {
        const TimeApiData* timeDataToShow = (const TimeApiData*)&dataToShow;

        showTimeData(*timeDataToShow);
        RealTimeSyncer::sync(timeDataToSync, timeToShowSec);

    } else if (dataToShow.getClassType() == CLASS_WEATHER_API_DTO) {
        const WeatherApiData* weatherDataToShow = (const WeatherApiData*)&dataToShow;

        showWeatherData(*weatherDataToShow);
        RealTimeSyncer::sync(timeDataToSync, timeToShowSec);

        showWeatherDespription(*weatherDataToShow);
        RealTimeSyncer::sync(timeDataToSync, 3);
    }
}
