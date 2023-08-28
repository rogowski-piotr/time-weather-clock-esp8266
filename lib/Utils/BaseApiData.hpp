#ifndef BaseApiData_h
#define BaseApiData_h

#include <Arduino.h>

class BaseApiData {
public:
    virtual int getClassType() const = 0;

    bool isCorrectlyReceivedData() const { return correctly_received_data; }
    void setCorrectlyReceivedData(bool value) { correctly_received_data = value; }

protected:
    bool correctly_received_data;
};

const int CLASS_TIME_API_DTO = 1;
const int CLASS_WEATHER_API_DTO = 2;

#endif