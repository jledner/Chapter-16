// SimpleVector class template
#ifndef SIMPLEVECTOR_H
#define SIMPLEVECTOR_H
#include <iostream>
#include <new> // Needed for bad_alloc exception
#include <cstdlib> // Needed for the exit function
using namespace std;

template <class T>
class SimpleVector {
private:
    T* aptr; // To point to the allocated array
    int arraySize; // Number of elements in the array
    void memError(); // Handles memory allocation errors
    void subError() const; // Add const here

public:
    // Default constructor
    SimpleVector() {
        aptr = 0;
        arraySize = 0;
    }

    // Constructor declaration
    SimpleVector(int);

    // Copy constructor declaration
    SimpleVector(const SimpleVector&);

    // Destructor declaration
    ~SimpleVector();

    // Accessor to return the array size
    int size() const {
        return arraySize;
    }

    // Accessor to return a specific element
    T getElementAt(int position);

    // Non-const operator[] (existing)
    T& operator[](const int& sub) {
        if (sub < 0 || sub >= arraySize)
            subError();
        return aptr[sub];
    }

    // Const operator[] (add this)
    const T& operator[](const int& sub) const {
        if (sub < 0 || sub >= arraySize)
            subError();
        return aptr[sub];
    }

    // Push_back fucntion
    void push_back(T element);
    void pop_back();

};

// Constructor for SimpleVector class. Sets the size of the array and allocates memory for it.
template <class T>
SimpleVector<T>::SimpleVector(int s) {
    arraySize = s;
    // Allocate memory for the array.
    try {
        aptr = new T[s];
    }
    catch (bad_alloc) {
        memError();
    }

    // Initialize the array.
    for (int count = 0; count < arraySize; count++)
        *(aptr + count) = 0;
}

// Copy Constructor for SimpleVector class.
template <class T>
SimpleVector<T>::SimpleVector(const SimpleVector& obj) {
    // Copy the array size.
    arraySize = obj.arraySize;

    // Allocate memory for the array.
    aptr = new T[arraySize];
    if (aptr == 0)
        memError();

    // Copy the elements of obj's array.
    for (int count = 0; count < arraySize; count++)
        *(aptr + count) = *(obj.aptr + count);
}

// Destructor for SimpleVector class.
template <class T>
SimpleVector<T>::~SimpleVector() {
    if (arraySize > 0)
        delete[] aptr;
}

// memError function. Displays an error message and terminates the program when memory allocation fails.
template <class T>
void SimpleVector<T>::memError() {
    cout << "ERROR: Cannot allocate memory.\n";
    exit(EXIT_FAILURE);
}

// subError function. Displays an error message and terminates the program when a subscript is out of range.
template <class T>
void SimpleVector<T>::subError() const { // Add const here
    cout << "ERROR: Subscript out of range.\n";
    exit(EXIT_FAILURE);
}

// getElementAt function. The argument is a subscript. This function returns the value stored at the subscript in the array.
template <class T>
T SimpleVector<T>::getElementAt(int sub) {
    if (sub < 0 || sub >= arraySize)
        subError();
    return aptr[sub];
}

template<class T>
void SimpleVector<T>::push_back(T element) {
    if (aptr != nullptr) {
        arraySize++;
        T* newSimpleVector = new T[arraySize];
        for (int i = 0; i < arraySize - 1; i++) {
            newSimpleVector[i] = aptr[i];
        }
        newSimpleVector[arraySize - 1] = element;
        delete[] aptr;
        aptr = newSimpleVector;
    }
    else {
        arraySize = 1;
        aptr = new T[arraySize];
        aptr[0] = element;
    }
}

template<class T>
void SimpleVector<T>::pop_back() {
    if (aptr != nullptr) {
        arraySize--;
        if (arraySize == 0) {
            delete[] aptr;
            aptr = nullptr;
        }
    }

    else {
        subError();
    }
}


#endif
