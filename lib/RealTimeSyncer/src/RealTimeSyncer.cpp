#include "RealTimeSyncer.hpp"


void RealTimeSyncer::resetTimeUnit(TimeData* timeData, TimeUnit timeUnit) {
    switch (timeUnit) {
        case Second:
            timeData->second = 0;
            break;

        case Minute:
            timeData->minute = 0;
            break;

        case Hour:
            timeData->hour = 0;
            break;
    }
}

void RealTimeSyncer::incrementTimeUnit(TimeData* timeData, TimeUnit timeUnit) {
    switch (timeUnit) {
        case Second:
            timeData->second++;
            break;

        case Minute:
            timeData->minute++;
            break;

        case Hour:
            timeData->hour++;
            break;
    }
}

void RealTimeSyncer::delayOneSec(int& currentMsRef) {
    delay(MS_PER_SEC);
    currentMsRef += MS_PER_SEC;
}

void RealTimeSyncer::sync(TimeData* timeData, int timeToSyncSec) {
    int timeToSyncMs = timeToSyncSec * MS_PER_SEC;
    int currentMs = 0;

    while (currentMs < timeToSyncMs) {
        delayOneSec(currentMs);

        incrementTimeUnit(timeData, Second);

        if (timeData->second == 60) {
            incrementTimeUnit(timeData, Minute);
            resetTimeUnit(timeData, Second);

            if (timeData->minute == 60) {
                incrementTimeUnit(timeData, Hour);
                resetTimeUnit(timeData, Minute);

                if (timeData->hour == 25) {
                    resetTimeUnit(timeData, Hour);
                }
            }
        }
    }
}
