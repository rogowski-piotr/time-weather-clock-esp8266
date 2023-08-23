#ifndef GenericHttpClient_h
#define GenericHttpClient_h

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <ESP8266HTTPClient.h>

const char TIME_API_ROOT_CA [] PROGMEM = R"CERT(
-----BEGIN CERTIFICATE-----
-----END CERTIFICATE-----
)CERT";

const char WEATHER_API_ROOT_CA [] PROGMEM = R"CERT(
-----BEGIN CERTIFICATE-----
-----END CERTIFICATE-----
)CERT";

class GenericHttpClient {
public:
    String httpGet(String url, int& httpStatusCode);
};

#endif
