#ifndef RealTimeSyncer_h
#define RealTimeSyncer_h

#include <Arduino.h>
#include "TimeApiData/TimeApiDataDeserializer/include/TimeApiDataDeserializer.hpp"

#define MS_PER_SEC 1000

enum TimeUnit {
    Second,
    Minute,
    Hour
};

class RealTimeSyncer {
public:
    static void sync(TimeData* timeData, int timeToSyncSec);

private:
    static void resetTimeUnit(TimeData* timeData, TimeUnit timeUnit);

    static void incrementTimeUnit(TimeData* timeData, TimeUnit timeUnit);

    static void delayOneSec(int& currentMsRef);
};

#endif
