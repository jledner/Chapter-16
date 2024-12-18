#ifndef SORTABLEVECTOR_H
#define SORTABLEVECTOR_H
#include "..\PC-8\SimpleVector.h"
#include <algorithm>

template <class T>
class SortableVector : public SimpleVector<T> {
public:
    // Default constructor
    SortableVector() : SimpleVector<T>() {}

    // Constructor
    SortableVector(int size) : SimpleVector<T>(size) {}

    // Copy constructor
    SortableVector(const SortableVector&);

    // Converting constructor 
    SortableVector(const SimpleVector<T>& obj);

    // Method to sort vector
    void sort();

    // Accessor to find an item
    bool findItem(const T);
};

// Copy constructor
template <class T>
SortableVector<T>::SortableVector(const SortableVector& obj) :
    SimpleVector<T>(obj.size()) {
    for (int count = 0; count < this->size(); count++)
        this->operator[](count) = obj[count];
}

// Converting constructor
template <class T>
SortableVector<T>::SortableVector(const SimpleVector<T>& obj)
    : SimpleVector<T>(obj.size()) {
    for (int count = 0; count < this->size(); count++)
        (*this)[count] = obj.operator[](count);
}

template<class T>
void SortableVector<T>::sort() {
    bool sorted = false;

    while (!sorted) {
        sorted = true;
        for (int i = 0; i < this->size() - 1; i++) {
            if ((*this)[i] > (*this)[i + 1]) {
                T temp = (*this)[i];
                (*this)[i] = (*this)[i + 1];
                (*this)[i + 1] = temp;
                sorted = false;
            }

        }
    }
}

template <class T>
bool SortableVector<T>::findItem(const T item) {
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

