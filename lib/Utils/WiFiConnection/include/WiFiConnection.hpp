#ifndef WiFiConnection_h
#define WiFiConnection_h

#include <ESP8266WiFi.h>
#include <LiquidCrystal_I2C.h>

void connectToWiFi(String ssid, String password, LiquidCrystal_I2C& lcdRef);

#endif
