#include "GenericHttpClient/include/GenericHttpClient.hpp"

String GenericHttpClient::httpGet(String url, int& httpStatusCode) {
    Serial.println("Sending HTTPS request to: " + String(url));

    WiFiClientSecure wifiClient;
    HTTPClient httpClient;

    X509List cert(TIME_API_ROOT_CA);
    cert.append(WEATHER_API_ROOT_CA);

    wifiClient.setTrustAnchors(&cert);

    httpClient.begin(wifiClient, url);
    httpStatusCode = httpClient.GET();

    Serial.println("Received HTTP status code: " + String(httpStatusCode) + "\n");

    String result;
    if (httpStatusCode == 200) {
        result = httpClient.getString();
    }

    httpClient.end();
    return result;
}
