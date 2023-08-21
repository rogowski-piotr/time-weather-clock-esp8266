#include "TimeApiData/TimeApiDataProvider/include/TimeApiDataProvider.hpp"


String TimeApiDataProvider::BASE_URL =  "worldtimeapi.org/api/ip";

void TimeApiDataProvider::getTimeData(TimeData* timeData) {
    int httpStatusCode = -1;
    String url = buildURL();
    String result = httpClient.httpGet(url, httpStatusCode);

    if (httpStatusCode == 200) {
        TimeApiDataDeserializer::deserialize(result, timeData);
        timeData->data_received = true;
    } else {
        timeData->data_received = false;
    }
}

String TimeApiDataProvider::buildURL() {
    return "http://" + BASE_URL;
}
