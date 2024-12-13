#include "Time.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class MilTime : public Time {
private:
    int milHours;
    int milSeconds;

public:
    MilTime() : milHours(0), milSeconds(0) {
        Time::setTime(0, 0, 0);
    }
    MilTime(int h, int s) {
        setTime(h, s);
    }

    class BadHour {
    private:
        int invalidValue;
    public:
        BadHour(int e) : invalidValue(e) {}
        int getBadHour() { return invalidValue; }
    };

    class BadSecond {
    private:
        int invalidValue;
    public:
        BadSecond(int e) : invalidValue(e) {}
        int getBadSecond() { return invalidValue; }
    };

    void setTime(int h, int s) {
        milHours = h;
        if (h > 2359 || h < 0)
            throw BadHour(h);

        milSeconds = s;
        if (s > 59 || s < 0)
            throw BadSecond(s);

        int hours = milHours / 100;
        int minutes = milHours % 100;
        int seconds = milSeconds;

        Time::setTime(hours, minutes, seconds);
    }
    int getHour() { return milHours; }
    int getSeconds() { return milSeconds; }


    string getStandHr() {
        ostringstream str1;
        str1 << Time::getHours() << ":" << Time::getMinutes();
        return str1.str();
    }
};

class TimeClock : public MilTime {
private:
    MilTime startTime;
    MilTime endTime;
public:
    TimeClock(MilTime st, MilTime et) : startTime(st), endTime(et) {}
    int timeElapsed() {
        int elapsed = ((endTime.getHour() - startTime.getHour()) / 100.0);
        return elapsed;
    }
};

int main() {
    int myHours = -1;
    int mySeconds = -1;

    bool invalidHours = true;
    bool invalidSeconds = true;

    while (invalidHours) {
        invalidHours = false;
        cout << "Enter hours in military format: " << endl;
        cin >> myHours;
        cout << "Enter seconds in military format: " << endl;
        cin >> mySeconds;
        try {
            MilTime myTime = MilTime(myHours, mySeconds);
        }
        catch (MilTime::BadHour e) {
            cout << "You entered " << e.getBadHour() << ". Invalid hours. Re-enter" << endl;
            invalidHours = true;
        }
        catch (MilTime::BadSecond e) {
            cout << "You entered " << e.getBadSecond() << ". Invalid seconds. Re-enter" << endl;
            invalidSeconds = true;
        }
    }


    MilTime myTime = MilTime(myHours, mySeconds);
    MilTime myTime2 = MilTime(1200, 00);

    TimeClock myTimeClock(myTime2, myTime);

    cout << "Military time: " << myTime.getHour() << ":" << mySeconds << endl;
    cout << "Standard time " << myTime.getStandHr() << ":" << mySeconds << endl;

    cout << "Hours elapsed since noon: " << myTimeClock.timeElapsed();

}