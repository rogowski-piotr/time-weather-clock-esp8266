#include "WiFiConnection/include/WiFiConnection.hpp"


void connectToWiFi(String ssid, String password) {
    WiFi.begin(ssid, password);
    Serial.print("\n\nConnecting");

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println("\nConnected!\n");
}
