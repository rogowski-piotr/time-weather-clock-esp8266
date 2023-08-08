#ifndef GenericHttpClient_h
#define GenericHttpClient_h

#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

class GenericHttpClient {
public:
    String httpGet(String url, int& httpStatusCode);
};

#endif
