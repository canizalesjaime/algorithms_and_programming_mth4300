# Lecture Notes

## table of contents
1. Pointers
2. Dynamic Memory
3. Practice Examples


## Pointers
In C++, a pointer is a variable that stores the memory address of another variable. Pointers are a powerful feature that allow for direct memory manipulation, efficient array management, and dynamic memory allocation, among other capabilities.

### Key Concepts:
* Pointer Declaration: A pointer is declared by specifying the data type it points to, followed by an asterisk (*) before the pointer name.
```cpp
int* ptr;  // ptr is a pointer to an integer
```

* Pointer Initialization: Pointers hold the memory address of another variable, which is assigned using the address-of operator (&).
```cpp
int a = 10;
int* ptr = &a;  // ptr holds the address of variable a
```

* Dereferencing a Pointer: Dereferencing a pointer means accessing the value stored at the memory address held by the pointer. This is done using the dereference operator (*).
```cpp
int a = 10;
int* ptr = &a;
cout << *ptr;  // Outputs: 10 (value of a)
```

* Null Pointer: A pointer that does not point to any valid memory address is called a null pointer. It is often initialized with nullptr or NULL.
```cpp
int* ptr = nullptr;  // ptr points to nothing
```

* Pointer Arithmetic: Pointers can be incremented or decremented, which advances or rewinds the memory address by the size of the data type it points to. This is commonly used with arrays.

```cpp
int arr[] = {1, 2, 3};
int* ptr = arr;  // ptr points to the first element of the array
ptr++;           // Now ptr points to the second element of the array
```

### Example of Pointers in C++
```cpp
#include <iostream>
using namespace std;

int main() {
    int var = 20;       // Declare an integer variable
    int* ptr = &var;    // Declare a pointer that holds the address of var
    
    cout << "Address of var: " << ptr << endl;     // Prints the memory address
    cout << "Value of var: " << *ptr << endl;      // Dereferences the pointer to get the value of var
    
    return 0;
}
```

#### Output:
```less
Address of var: 0x7ffc2c7f10b8
Value of var: 20
```


#### Common Uses of Pointers:
* Dynamic Memory Allocation: Pointers are used with new and delete to allocate and deallocate memory dynamically.

```cpp
int* p = new int;  // Allocates memory for an integer
*p = 10;
delete p;  // Frees the allocated memory
```
* Arrays and Functions: Pointers are commonly used to pass arrays or large data structures to functions to avoid copying.

```cpp
void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}
```
* Pointer to Pointer: Pointers can also point to other pointers, enabling multi-level indirection.

```cpp
int a = 5;
int* p = &a;     // Pointer to integer
int** q = &p;    // Pointer to pointer
```

### Advantages of Pointers:
* Efficiency: Pointers allow efficient handling of arrays, strings, and large data structures by passing memory addresses instead of copying data.
* Dynamic Memory Management: They enable dynamic memory allocation, allowing programs to handle memory at runtime.
* Flexibility: Pointers provide direct memory access, which is crucial for system-level programming.

### Disadvantages of Pointers:
* Complexity: Improper use of pointers can lead to hard-to-debug errors like memory leaks, dangling pointers, or crashes.
* Security Risks: Unchecked pointer operations can result in vulnerabilities such as buffer overflow or segmentation faults.

Pointers are a fundamental aspect of C++ that, when used correctly, provide great control and flexibility. However, they require careful management to avoid issues such as memory corruption.


## Dynamic Memory
In C++, dynamic memory refers to memory that is allocated at runtime using pointers, rather than being predefined at compile-time. It allows programs to request memory from the system's heap during execution. This approach offers flexibility, particularly when dealing with data whose size is unknown before the program runs.

### Key Concepts of Dynamic Memory in C++:
1. Heap vs. Stack:
   * **Stack:** Automatically managed memory where local variables and function call data are stored. Memory is allocated and deallocated automatically when functions are called and returned.<br>
   * **Heap:** Dynamically allocated memory that must be managed explicitly by the programmer using pointers. It’s ideal for memory whose size may change or isn’t known at compile time.

2. Pointers:
   * Dynamic memory in C++ is accessed via pointers. A pointer holds the memory address of a value rather than the value itself.

3. Memory Allocation and Deallocation:
   * C++ provides the new and delete operators for dynamic memory management:
     * new: Allocates memory dynamically.
     * delete: Frees dynamically allocated memory.


### Dynamic Memory Allocation Syntax:
Allocating memory using new:

```cpp
int* ptr = new int;  // Allocates memory for an integer
*ptr = 42;           // Assigns the value 42 to the allocated memory
```
This allocates memory for an integer in the heap, and ptr is a pointer that stores the address of that allocated memory.

Deallocating memory using delete:

```cpp
delete ptr;  // Frees the dynamically allocated memory
```
After freeing the memory, ptr still holds the memory address, so it's a good practice to set it to nullptr:

```cpp
ptr = nullptr;
```

Allocating Arrays Dynamically:
To allocate an array dynamically, use new[]:


```cpp
int* arr = new int[5];  // Allocates memory for an array of 5 integers
```

To free memory allocated for an array, use delete[]:

```cpp
delete[] arr;  // Frees the dynamically allocated array memory
```

### Example of Dynamic Memory Allocation in C++:
```cpp
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
```

### Important Considerations:
1. **Memory Leaks:**
   * If memory allocated with ```new``` is not deallocated using ```delete```, it leads to memory leaks. This means that memory is no longer accessible by the program, but it remains occupied, reducing available system resources.

2. **Dangling Pointers:**
   * A pointer that points to memory that has been deallocated (freed) is called a dangling pointer. Using such pointers can cause undefined behavior. Always ensure that pointers are either properly reallocated or set to nullptr after delete.

3. **Smart Pointers:**
   * Modern C++ (C++11 and later) introduces smart pointers (such as ```std::unique_ptr```, ```std::shared_ptr```, etc.), which automatically manage memory and help avoid manual memory management pitfalls like leaks and dangling pointers.
  
#### Example with Smart Pointers (C++11):
```cpp
#include <memory>  // Include smart pointer library
#include <iostream>

int main() {
    std::unique_ptr<int> ptr = std::make_unique<int>(10);  // Automatically handles memory
    std::cout << "Value: " << *ptr << std::endl;           // No need for manual delete

    // Automatically deallocated when the pointer goes out of scope
    return 0;
}
```
More on this topic later when we cover templates!


### Summary:
Dynamic memory in C++ allows for flexible memory management, particularly useful when the size of data structures is not known at compile time. However, it requires careful management to avoid memory leaks and other issues. With modern C++ standards, smart pointers can help manage dynamic memory more safely and efficiently.


## Practice Examples
1. Write a C++ program that does the following:<br>
   * Creates an integer variable and initializes it with a value (e.g., 42).
   * Creates a pointer to that integer variable.
   * Using the pointer, display the value of the integer variable.
   * Modify the value of the integer variable using the pointer, and then display the updated value.

2. Write a C++ program that dynamically allocates memory for a list of student names. The program should:
   * Ask the user to enter the number of students.
   * Dynamically allocate memory for an array of strings to store the names.
   * Allow the user to input each student's name.
   * Display the list of student names.
   * Deallocate all dynamically allocated memory before the program ends.
