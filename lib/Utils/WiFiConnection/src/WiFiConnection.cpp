#include "WiFiConnection/include/WiFiConnection.hpp"


void connectToWiFi(String ssid, String password, LiquidCrystal_I2C& lcdRef) {
    WiFi.begin(ssid, password);
    Serial.print("\n\nConnecting to WiFi");

    lcdRef.clear();
    lcdRef.setCursor(0,0);
    lcdRef.print("   Conecting");
    lcdRef.setCursor(0, 1); 

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
        lcdRef.print(".");
    }

    Serial.println("\nConnected!");
    Serial.println("IP: " + WiFi.localIP().toString() + "\n");

    lcdRef.clear();
    lcdRef.setCursor(0, 0);
    lcdRef.print("   Connected!");
    lcdRef.setCursor(0, 1);
    lcdRef.print("IP:" + WiFi.localIP().toString());

    delay(2000);
}
