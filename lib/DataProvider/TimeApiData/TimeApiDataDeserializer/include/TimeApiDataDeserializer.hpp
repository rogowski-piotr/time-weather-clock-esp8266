#ifndef TimeApiDataDeserializer_h
#define TimeApiDataDeserializer_h

#include <ArduinoJson.h>
#include "GenericApiData.hpp"


struct TimeData : public GenericApiData {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
};

class TimeApiDataDeserializer {
public:
    static void deserialize(const String& jsonData, TimeData* timeData);
};

#endif
