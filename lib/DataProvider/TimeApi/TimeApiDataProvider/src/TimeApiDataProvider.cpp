#include "TimeApi/TimeApiDataProvider/include/TimeApiDataProvider.hpp"


String TimeApiDataProvider::BASE_URL =  "worldtimeapi.org/api/ip";

void TimeApiDataProvider::getTimeData(TimeApiData* timeData) {
    timeData->setYear(10);
    int httpStatusCode = -1;
    String url = buildURL();
    String result = httpClient.httpGet(url, httpStatusCode);

    if (httpStatusCode == 200) {
        TimeApiDataDeserializer::deserialize(result, timeData);
        timeData->setCorrectlyReceivedData(true);
    } else {
        timeData->setCorrectlyReceivedData(false);
    }
}

String TimeApiDataProvider::buildURL() {
    return "https://" + BASE_URL;
}
