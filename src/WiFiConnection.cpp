#include "WiFiConnection.h"
#include "secrets.h"


void connectToWiFi() {
  WiFi.begin(SECRET_SSID, SECRET_PASS);
  Serial.println("Connecting");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("Connected!");
}
