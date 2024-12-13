#ifndef DATE_H
#define DATE_H

class Date {
protected:
    int day;
    int month;
    int year;
public:
    // Default constructor
    Date() {
        day = 1;
        month = 1;
        year = 1900;
    }
    class InvalidDay {};
    class InvalidMonth {};

    // Constructor
    Date(int d, int m, int y) {
        day = d;
        if (day < 1 || day > 31) {
            throw InvalidDay();
        }
        month = m;
        if (month < 1 || month > 12) {
            throw InvalidMonth();
        }
        year = y;
    }

    // Accessors
    int getDay() const {
        return day;
    }

    int getMonth() const {
        return month;
    }

    int getYear() const {
        return year;
    }
};

#endif
