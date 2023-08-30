#include "NTPSynchronization/include/NTPSynchronization.hpp"


void syncWithNTP(int timeout, LiquidCrystal_I2C& lcdRef) {
    Serial.print("Waiting for NTP time sync");
    lcdRef.clear();
    lcdRef.setCursor(0, 0);
    lcdRef.print("Waiting for NTP");

    bool syncSuccess = false;

    while (!syncSuccess) {
        tryToSync(timeout, syncSuccess);
    }

    lcdRef.clear();
    lcdRef.setCursor(0, 0);
    lcdRef.print("Synced with NTP!");
    delay(2000);
}

void tryToSync(int timeout, bool &syncSuccess) {
    configTime(0, 3600, "pool.ntp.org", "time.nist.gov");
    time_t now = time(nullptr);

    int currentTime = 0;
    while (now < 1500000000 && currentTime <= timeout) {
        Serial.print(".");
        currentTime += 500;
        delay(500);
        now = time(nullptr);
    }

    struct tm timeinfo;
    gmtime_r(&now, &timeinfo);

    if (now >= 1500000000) {
        syncSuccess = true;
        Serial.print("\nCorrectly sync with NTP server, UTC Time: ");
        Serial.println(asctime(&timeinfo));
    } else {
        syncSuccess = false;
    }
}
