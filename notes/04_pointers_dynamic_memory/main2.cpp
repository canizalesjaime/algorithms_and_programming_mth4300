#include <iostream>
using namespace std;

int main() {
    int* p = new int;     // Dynamically allocate memory for an integer
    *p = 10;              // Assign the value 10 to that memory
    cout << "Value: " << *p << endl;  // Output the value

    delete p;             // Deallocate memory
    p = nullptr;          // Avoid dangling pointers by setting it to nullptr

    // Dynamically allocating an array
    int* arr = new int[5];
    for (int i = 0; i < 5; i++) {
        arr[i] = i * 2;
        cout << "arr[" << i << "] = " << arr[i] << endl;
    }

    delete[] arr;  // Deallocate the array memory
    arr = nullptr; // Avoid dangling pointer

    return 0;
}