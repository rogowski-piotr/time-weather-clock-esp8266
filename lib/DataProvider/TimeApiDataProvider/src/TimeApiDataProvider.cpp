#include "TimeApiDataProvider/include/TimeApiDataProvider.hpp"


String TimeApiDataProvider::BASE_URL =  "worldtimeapi.org/api/ip";

void TimeApiDataProvider::getTimeData(TimeData* timeData) {
    int httpStatusCode = -1;
    String url = buildURL();
    String result = httpClient.httpGet(url, httpStatusCode);

    if (httpStatusCode == 200) {
        deserializeTimeData(result, timeData);
        timeData->data_received = true;
    } else {
        timeData->data_received = false;
    }
}

void TimeApiDataProvider::deserializeTimeData(const String& jsonData, TimeData* timeData) {
    // Parsing result by https://arduinojson.org/v6/assistant/
    const size_t capacity = JSON_OBJECT_SIZE(15) + 350;
    DynamicJsonDocument doc(capacity);
    deserializeJson(doc, jsonData);

    const char* dateTime = doc["datetime"]; // "2020-05-05T23:08:41.476838+02:00"

    timeData->year = String(dateTime).substring(0, 4).toInt();
    timeData->month = String(dateTime).substring(5, 7).toInt();
    timeData->day = String(dateTime).substring(8, 10).toInt();
    timeData->hour = String(dateTime).substring(11, 13).toInt();
    timeData->minute = String(dateTime).substring(14, 16).toInt();
    timeData->second = String(dateTime).substring(17, 19).toInt();
}

String TimeApiDataProvider::buildURL() {
    return "http://" + BASE_URL;
}
