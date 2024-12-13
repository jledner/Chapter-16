#include "Date.h"
#include <iostream>

using namespace std;

int main() {
    bool validInput = true;
    Date newDate;
    int day;
    int month;
    int year;
    do {
        validInput = true;
        cout << "Enter day: " << endl;
        cin >> day;
        cout << "Enter month: " << endl;
        cin >> month;
        cout << "Enter year: " << endl;
        cin >> year;
        try {
            newDate = Date(day, month, year);
        }
        catch (Date::InvalidDay e) {
            cout << "Invalid day. Re-enter. " << endl;
            validInput = false;
        }
        catch (Date::InvalidMonth e) {
            cout << "Invalid month. Re-enter. " << endl;
            validInput = false;
        }
    } while (!validInput);

    cout << "Day: " << newDate.getDay() << " Month: " << newDate.getMonth() << " Year: " << newDate.getYear();
    return 0;
}