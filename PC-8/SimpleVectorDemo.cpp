// This program demonstrates the SimpleVector template.
#include <iostream>
#include "SimpleVector.h"
#include "..\PC-9\SearchableVector.h"
#include "..\PC-11\SortableVector.h"
using namespace std;

int main() {
    const int SIZE = 10; // Number of elements
    int count; // Loop counter

    // Create a SimpleVector of ints.
    SimpleVector<int> intTable(SIZE);

    // Create a SimpleVector of doubles.
    SimpleVector<double> doubleTable(SIZE);

    // Store values in the two SimpleVectors.
    for (count = 0; count < SIZE; count++) {
        intTable[count] = (count * 2);
        doubleTable[count] = (count * 2.14);
    }

    // Display the values in the SimpleVectors.
    cout << "These values are in intTable:\n";
    for (count = 0; count < SIZE; count++)
        cout << intTable[count] << " ";
    cout << endl;

    cout << "These values are in doubleTable:\n";
    for (count = 0; count < SIZE; count++)
        cout << doubleTable[count] << " ";
    cout << endl;

    // Use the standard + operator on the elements.
    cout << "\nAdding 5 to each element of intTable"
        << " and doubleTable.\n";
    for (count = 0; count < SIZE; count++) {
        intTable[count] = intTable[count] + 5;
        doubleTable[count] = doubleTable[count] + 5.0;
    }

    // Display the values in the SimpleVectors.
    cout << "These values are in intTable:\n";
    for (count = 0; count < SIZE; count++)
        cout << intTable[count] << " ";
    cout << endl;

    cout << "These values are in doubleTable:\n";
    for (count = 0; count < SIZE; count++)
        cout << doubleTable[count] << " ";
    cout << endl;

    // Use the standard ++ operator on the elements.
    cout << "\nIncrementing each element of intTable and"
        << " doubleTable.\n";
    for (count = 0; count < SIZE; count++) {
        intTable[count]++;
        doubleTable[count]++;
    }

    // Display the values in the SimpleVectors.
    cout << "These values are in intTable:\n";
    for (count = 0; count < SIZE; count++)
        cout << intTable[count] << " ";
    cout << endl;

    cout << "These values are in doubleTable:\n";
    for (count = 0; count < SIZE; count++)
        cout << doubleTable[count] << " ";
    cout << endl;

    doubleTable.push_back(10);
    cout << "Push_back completed\n";
    for (count = 0; count < SIZE + 1; count++)
        cout << doubleTable[count] << " ";
    cout << endl;
    SearchableVector<double> searchvec(doubleTable);
    SortableVector<double> sortvec(searchvec);
    sortvec.sort();
    for (count = 0; count < SIZE; count++)
        cout << sortvec[count] << " ";
    cout << endl;

    sortvec.pop_back();
    cout << "Pop_back completed\n";
    for (count = 0; count < SIZE; count++)
        cout << sortvec[count] << " ";
    cout << endl;

    bool found = sortvec.findItem(6);
    if (found) {
        cout << "Found" << endl;
    }

    sortvec.push_back(7);
    found = sortvec.sortAndSearch(7);
    for (count = 0; count < SIZE; count++)
        cout << sortvec[count] << " ";
    cout << endl;
    if (found) {
        cout << "Found" << endl;
    }

    return 0;
}
