#ifndef INTARRAY_H
#define INTARRAY_H

class IntArray {
private:
    int* aptr; // Pointer to the array
    int arraySize; // Holds the array size
public:
    IntArray(int); // Constructor
    IntArray(const IntArray&); // Copy constructor
    ~IntArray(); // Destructor

    class SubscriptError {
    private:
        int subscript;
    public:
        SubscriptError(int s) : subscript(s) {}
        int getSubscript() { return subscript; }
    };

    int size() const // Returns the array size
    {
        return arraySize;
    }

    int& operator[](const int&); // Overloaded [] operator
};
#endif
