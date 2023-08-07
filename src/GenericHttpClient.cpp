#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>


String httpGet(String url, int& httpStatusCode) {
    WiFiClient wifiClient;
    HTTPClient httpClient;

    httpClient.begin(wifiClient, url);
    httpStatusCode = httpClient.GET();

    String result;
    if (httpStatusCode == 200) {
        result = httpClient.getString();
    }

    httpClient.end();
    return result;
}
