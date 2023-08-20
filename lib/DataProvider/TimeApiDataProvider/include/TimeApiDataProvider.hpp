#ifndef TimeApiDataProvider_h
#define TimeApiDataProvider_h

#include <ArduinoJson.h>
#include "GenericApiData.hpp"
#include "GenericHttpClient/include/GenericHttpClient.hpp"


struct TimeData : public GenericApiData {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
};

class TimeApiDataProvider {
public:
    void getTimeData(TimeData* timeData);

private:
    GenericHttpClient httpClient = GenericHttpClient();

    static String BASE_URL;

    static String buildURL();

    static void deserializeTimeData(const String& jsonData, TimeData* timeData);
};

#endif
