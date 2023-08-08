#include "Utils/WiFiConnection.h""


void connectToWiFi() {
    WiFi.begin(SECRET_SSID, SECRET_PASS);
    Serial.print("\n\nConnecting");

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println("\nConnected!\n");
}
