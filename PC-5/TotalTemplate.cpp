#include <iostream>

using namespace std;

template <class T>
T total(int amount) {
    T val;
    T sum = 0;
    for (int i = 0; i < amount; i++) {
        cout << "Enter value number " << i + 1 << ": " << endl;
        cin >> val;
        sum += val;
    }
    return sum;
}

int main() {
    int numValues;
    int sumValues;
    cout << "How many values would you like to enter: " << endl;
    cin >> numValues;
    sumValues = total<int>(numValues);
    cout << "Total: " << sumValues << endl;
    return 0;
}