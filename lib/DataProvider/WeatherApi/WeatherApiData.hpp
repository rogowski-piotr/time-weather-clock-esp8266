#ifndef WeatherApiData_h
#define WeatherApiData_h

#include "BaseApiData.hpp"

class WeatherApiData : public BaseApiData {
public:
    int getClassType() const override { return CLASS_WEATHER_API_DTO; }

    const char* getDescription() const { return description; }
    void setDescription(const char* newDescription) { description = newDescription; }

    float getTemperature() const { return temperature; }
    void setTemperature(float newTemperature) { temperature = newTemperature; }

    int getPressure() const { return pressure; }
    void setPressure(int newPressure) { pressure = newPressure; }

    int getHumidity() const { return humidity; }
    void setHumidity(int newHumidity) { humidity = newHumidity; }

    float getWindSpeed() const { return wind_speed; }
    void setWindSpeed(float newWindSpeed) { wind_speed = newWindSpeed; }

private:
    const char* description;
    float temperature;
    int pressure;
    int humidity;
    float wind_speed;
};

#endif
