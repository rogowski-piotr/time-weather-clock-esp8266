#ifndef TimeApiData_h
#define TimeApiData_h

#include "BaseApiData.hpp"

class TimeApiData : public BaseApiData {
public:
    int getClassType() const override { return CLASS_TIME_API_DTO; }

    int getYear() const { return year; }
    void setYear(int newYear) { year = newYear; }

    int getMonth() const { return month; }
    void setMonth(int newMonth) { month = newMonth; }

    int getDay() const { return day; }
    void setDay(int newDay) { day = newDay; }

    int getHour() const { return hour; }
    void setHour(int newHour) { hour = newHour; }

    int getMinute() const { return minute; }
    void setMinute(int newMinute) { minute = newMinute; }

    int getSecond() const { return second; }
    void setSecond(int newSecond) { second = newSecond; }

private:
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
};

#endif
