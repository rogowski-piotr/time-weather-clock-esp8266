#ifndef NTPSynchronization_h
#define NTPSynchronization_h

#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <LiquidCrystal_I2C.h>

void syncWithNTP(int timeout, LiquidCrystal_I2C& lcdRef);

void tryToSync(int timeout, bool &syncSuccess);

#endif
