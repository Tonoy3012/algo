#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    int i, j, pos, item, size;
    cout << "Enter the array size: ";
    cin >> size;
    int array[size];

    srand(time(0)); 


    for (i = 0; i < size; i++)
        array[i] = rand() % 50;

    cout << "Input array elements are: ";
    for (i = 0; i < size; i++)
        cout << array[i] << " ";

    while (true) {
        cout << "\n\nEnter the position to insert a new item (0 - " << size << "): ";
        cin >> pos;

        if (pos < 0 || pos > size) {
            cout << "Invalid position! Position should be between 0 and " << size << ".\n";
            continue; // Ask for position again
        }

        cout << "Enter the new item: ";
        cin >> item;

     
        for (j = size; j > pos; j--)
            array[j] = array[j - 1];

        
        array[pos] = item;
        size++; // Increase the size of the array

        cout << "\nArray size: " << size;
        cout << "\nArray elements: ";
        for (i = 0; i < size; i++)
            cout << array[i] << " ";
    }

    return 0;
}