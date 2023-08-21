#ifndef TimeApiDataProvider_h
#define TimeApiDataProvider_h

#include "GenericHttpClient/include/GenericHttpClient.hpp"
#include "TimeApiData/TimeApiDataDeserializer/include/TimeApiDataDeserializer.hpp"


class TimeApiDataProvider {
public:
    void getTimeData(TimeData* timeData);

private:
    GenericHttpClient httpClient = GenericHttpClient();

    static String BASE_URL;

    static String buildURL();
};

#endif
