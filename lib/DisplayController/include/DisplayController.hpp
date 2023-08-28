#ifndef DisplayController_h
#define DisplayController_h

#include <Arduino.h>
#include <typeinfo>
#include "BaseApiData.hpp"
#include "TimeApi/TimeApiData.hpp"
#include "WeatherApi/WeatherApiData.hpp"

class DisplayController {
public:
    static void showData(const BaseApiData& data);
};

#endif


