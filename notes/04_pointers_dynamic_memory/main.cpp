#include <iostream>
using namespace std;

int main() 
{
    int var = 20;       // Declare an integer variable
    int *ptr = &var;    // Declare a pointer that holds the address of var
    
    cout << "Address of var: " << ptr << endl;     // Prints the memory address
    cout << "Value of var: " << *ptr << endl;      // Dereferences the pointer to get the value of var
    
    return 0;
}