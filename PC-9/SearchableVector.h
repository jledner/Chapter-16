#ifndef SEARCHABLEVECTOR_H
#define SEARCHABLEVECTOR_H
#include "SimpleVector.h"
#include <algorithm>

template <class T>
class SearchableVector : public SimpleVector<T> {
public:
    // Default constructor
    SearchableVector() : SimpleVector<T>() {}

    // Constructor
    SearchableVector(int size) : SimpleVector<T>(size) {}

    // Copy constructor
    SearchableVector(const SearchableVector&);

    // Accessor to find an item
    bool findItem(const T);
};

// Copy constructor
template <class T>
SearchableVector<T>::SearchableVector(const SearchableVector& obj) :
    SimpleVector<T>(obj.size()) {
    for (int count = 0; count < this->size(); count++)
        this->operator[](count) = obj[count];
}

// findItem function
// This function searches for item. If item is found
// the subscript is returned. Otherwise −1 is returned.

template <class T>
bool SearchableVector<T>::findItem(const T item) {
    int low = 0;
    int high = this->size() - 1;

    while (low <= high) {
        int midpoint = (high + low) / 2;
        if (this->operator[](midpoint) == item) {
            return true;
        }
        else if (item > this->operator[](midpoint))
            low = midpoint + 1;
        else
            high = midpoint - 1;
    }
    return false;
}

#endif

