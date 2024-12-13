#include <iostream>

using namespace std;

template <class T>
T absVal(T val) {
    if (val > 0)
        return val;
    return -val;
}

int main() {
    int x1 = -4;
    int x2 = 5;
    double y1 = -4;
    double y2 = 5;
    long z1 = -4;
    long z2 = 5;

    cout << "x1: " << absVal(x1) << endl;
    cout << "x2: " << absVal(x2) << endl;
    cout << "y1: " << absVal(y1) << endl;
    cout << "y2: " << absVal(y2) << endl;
    cout << "z1: " << absVal(z1) << endl;
    cout << "z2: " << absVal(z2) << endl;

    return 0;
}