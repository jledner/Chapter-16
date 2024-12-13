#ifndef TIME_H
#define TIME_H

class Time {
protected:
    int hours; // Holds the hour in standard 12-hour format
    int min;   // Holds the minutes
    int sec;   // Holds the seconds

public:
    // Default constructor
    Time() : hours(0), min(0), sec(0) {}

    // Constructor with parameters
    Time(int h, int m, int s) : hours(h), min(m), sec(s) {}

    // Setters
    void setTime(int h, int m, int s) {
        hours = h;
        min = m;
        sec = s;
    }

    // Getters
    int getHours() const { return hours; }
    int getMinutes() const { return min; }
    int getSeconds() const { return sec; }
};

#endif
