#ifndef SEARCHABLEVECTOR_H
#define SEARCHABLEVECTOR_H
#include "SimpleVector.h"
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

    // Method to sort vector
    void SortableVector<T>::sort();

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

template <class T>
void SortableVector<T>::sort() {
    bool sorted = false;

    SortableVector<T> newVec(this->size());
    for (int i = 0; i < this->arraySize(); i++) {
        newVec[i] = this->getElementAt(i);
    }

    while (!sorted) {
        sorted = true;
        for (int i = 0; i < this->size() - 1; i++) {
            if (newVec[i] > newVec[i + 1]) {
                T temp = newVec[i + 1];
                newVec[i + 1] = newVec[i];
                newVec[i] = temp;
                sorted = false;
            }
        }
    }

    for (int i = 0; i < this->size(); i++) {
        *this[i] = newVec[i];
    }
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

