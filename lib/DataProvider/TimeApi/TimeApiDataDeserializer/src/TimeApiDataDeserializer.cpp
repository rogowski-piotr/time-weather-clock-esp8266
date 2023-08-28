#include "TimeApi/TimeApiDataDeserializer/include/TimeApiDataDeserializer.hpp"


void TimeApiDataDeserializer::deserialize(const String& jsonData, TimeApiData* timeData) {
    // Parsing result by https://arduinojson.org/v6/assistant/
    const size_t capacity = JSON_OBJECT_SIZE(15) + 350;
    DynamicJsonDocument doc(capacity);
    deserializeJson(doc, jsonData);

    const char* dateTime = doc["datetime"]; // "2020-05-05T23:08:41.476838+02:00"

    timeData->setYear(String(dateTime).substring(0, 4).toInt());
    timeData->setMonth(String(dateTime).substring(5, 7).toInt());
    timeData->setDay(String(dateTime).substring(8, 10).toInt());
    timeData->setHour(String(dateTime).substring(11, 13).toInt());
    timeData->setMinute(String(dateTime).substring(14, 16).toInt());
    timeData->setSecond(String(dateTime).substring(17, 19).toInt());
}
