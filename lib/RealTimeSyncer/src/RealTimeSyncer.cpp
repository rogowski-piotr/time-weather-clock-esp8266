#include "RealTimeSyncer.hpp"


void RealTimeSyncer::resetTimeUnit(TimeApiData* timeData, TimeUnit timeUnit) {
    switch (timeUnit) {
        case Second:
            timeData->setSecond(0);
            break;

        case Minute:
            timeData->setMinute(0);
            break;

        case Hour:
            timeData->setHour(0);
            break;
    }
}

void RealTimeSyncer::incrementTimeUnit(TimeApiData* timeData, TimeUnit timeUnit) {
    switch (timeUnit) {
        case Second:
            timeData->setSecond(timeData->getSecond() + 1);
            break;

        case Minute:
            timeData->setMinute(timeData->getMinute() + 1);
            break;

        case Hour:
            timeData->setHour(timeData->getHour() + 1);
            break;
    }
}

void RealTimeSyncer::delayOneSec(int& currentMsRef) {
    delay(MS_PER_SEC);
    currentMsRef += MS_PER_SEC;
}

void RealTimeSyncer::sync(TimeApiData* timeData, int timeToSyncSec) {
    int timeToSyncMs = timeToSyncSec * MS_PER_SEC;
    int currentMs = 0;

    while (currentMs < timeToSyncMs) {
        delayOneSec(currentMs);

        incrementTimeUnit(timeData, Second);

        if (timeData->getSecond() == 60) {
            incrementTimeUnit(timeData, Minute);
            resetTimeUnit(timeData, Second);

            if (timeData->getMinute() == 60) {
                incrementTimeUnit(timeData, Hour);
                resetTimeUnit(timeData, Minute);

                if (timeData->getHour() == 25) {
                    resetTimeUnit(timeData, Hour);
                }
            }
        }
    }
}
