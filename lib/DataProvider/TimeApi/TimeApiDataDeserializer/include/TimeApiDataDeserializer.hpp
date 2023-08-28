#ifndef TimeApiDataDeserializer_h
#define TimeApiDataDeserializer_h

#include <ArduinoJson.h>
#include "TimeApi/TimeApiData.hpp"

class TimeApiDataDeserializer {
public:
    static void deserialize(const String& jsonData, TimeApiData* timeData);
};

#endif
