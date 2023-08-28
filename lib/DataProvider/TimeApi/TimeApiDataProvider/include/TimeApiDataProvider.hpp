#ifndef TimeApiDataProvider_h
#define TimeApiDataProvider_h

#include "GenericHttpClient/include/GenericHttpClient.hpp"
#include "TimeApi/TimeApiDataDeserializer/include/TimeApiDataDeserializer.hpp"
#include "TimeApi/TimeApiData.hpp"

class TimeApiDataProvider {
public:
    void getTimeData(TimeApiData* timeData);

private:
    GenericHttpClient httpClient = GenericHttpClient();

    static String BASE_URL;

    static String buildURL();
};

#endif
