#include "NTPSynchronization/include/NTPSynchronization.hpp"


void syncWithNTP(int timeout) {
    Serial.print("Waiting for NTP time sync");

    configTime(0, 3600, "pool.ntp.org", "time.nist.gov");
    time_t now = time(nullptr);

    int currentAttempt = 0;
    while (now < 1500000000 && currentAttempt <= timeout) {
        Serial.print(".");
        currentAttempt += 500;
        delay(500);
        now = time(nullptr);
    }

    struct tm timeinfo;
    gmtime_r(&now, &timeinfo);

    Serial.print("\nCorrectly sync with NTP server, UTC Time: ");
    Serial.println(asctime(&timeinfo));
}
