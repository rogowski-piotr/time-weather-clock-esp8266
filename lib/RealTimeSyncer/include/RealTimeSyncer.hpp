#ifndef RealTimeSyncer_h
#define RealTimeSyncer_h

#include <Arduino.h>
#include "TimeApi/TimeApiData.hpp"

#define MS_PER_SEC 1000

enum TimeUnit {
    Second,
    Minute,
    Hour
};

class RealTimeSyncer {
public:
    static void sync(TimeApiData* timeData, int timeToSyncSec);

private:
    static void resetTimeUnit(TimeApiData* timeData, TimeUnit timeUnit);

    static void incrementTimeUnit(TimeApiData* timeData, TimeUnit timeUnit);

    static void delayOneSec(int& currentMsRef);
};

#endif
