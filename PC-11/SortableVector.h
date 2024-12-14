#ifndef SORTABLEVECTOR_H
#define SORTABLEVECTOR_H
#include "..\PC-8\SimpleVector.h"
#include "..\PC-9\SearchableVector.h"
#include <algorithm>

template <class T>
class SortableVector : public SearchableVector<T> {
public:
    // Default constructor
    SortableVector() : SearchableVector<T>() {}

    // Constructor
    SortableVector(int size) : SearchableVector<T>(size) {}

    // Copy constructor
    SortableVector(const SortableVector&);

    // Converting constructor 
    SortableVector(const SearchableVector<T>& obj);

    // Method to sort vector
    void sort();

    // Method to sort and search
    bool sortAndSearch(T element);
};

// Copy constructor
template <class T>
SortableVector<T>::SortableVector(const SortableVector& obj) :
    SearchableVector<T>(obj.size()) {
    for (int count = 0; count < this->size(); count++)
        this->operator[](count) = obj[count];
}

// Converting constructor
template <class T>
SortableVector<T>::SortableVector(const SearchableVector<T>& obj)
    : SearchableVector<T>(obj.size()) {
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

template<class T>
bool SortableVector<T>::sortAndSearch(T element) {
    this->sort();
    bool found = this->findItem(element);
    return found;
}

#endif

