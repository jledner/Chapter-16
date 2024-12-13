#include <iostream>

using namespace std;

template <class T>
T minimum(T val1, T val2) {
    if (val1 < val2)
        return val1;
    return val2;
}

template <class T>
T maximum(T val1, T val2) {
    if (val1 > val2)
        return val1;
    return val2;
}

int main() {
    int x, y;
    cout << "Enter x: " << endl;
    cin >> x;
    cout << "Enter y: " << endl;
    cin >> y;
    cout << "Minimum: " << minimum(x, y) << endl;
    cout << "Maximum: " << maximum(x, y) << endl;
    return 0;
}