#ifndef DisplayController_h
#define DisplayController_h

#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include "BaseApiData.hpp"
#include "TimeApi/TimeApiData.hpp"
#include "WeatherApi/WeatherApiData.hpp"
#include "RealTimeSyncer.hpp"

class DisplayController {
public:
    DisplayController(const String& city) : cityName(city) { }
    void initDisplay();
    void changeBacklight();
    void showData(const BaseApiData& dataToShow, TimeApiData& timeDataToSync, int timeToShowSec);

private:
    LiquidCrystal_I2C lcd{0x27, 16, 2};
    bool isBacklight = false;
    String cityName;
    void showTimeData(const TimeApiData& data);
    void showWeatherData(const WeatherApiData& data);
    void showWeatherDespription(const WeatherApiData& data);
};

#endif


