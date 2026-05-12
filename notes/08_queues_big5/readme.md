# Lecture notes

## table of contents
1. this keyword 
2. Queues
3. Big 5 
4. Separation of Interface and Implementation
5. Compilation of multifile with g++
6. Object oriented covered so far
7. Object oriented we will cover
8. Practice Examples


## this keyword
In C++, the ```this``` keyword is a special pointer available inside non-static member functions of a class. It points to the current object (the instance of the class) for which the member function is called. The ```this``` pointer is implicitly passed to all non-static member functions of a class.

### Characteristics of the this Pointer
* Type of ```this```: The type of the this pointer is a pointer to the class type. For a class MyClass, the type of ```this``` is MyClass*.
* Automatic Availability: The ```this``` pointer is automatically available in all non-static member functions; you don't need to declare or initialize it.
* Cannot Modify: You cannot modify the ```this``` pointer itself, but you can use it to modify the object it points to.


### Common Uses of the this Pointer
#### Accessing Data Members
The ```this``` pointer is used to access data members of the class when there is a name conflict between member variables and function parameters.

```cpp
#include <iostream>

class MyClass {
private:
    int value;

public:
    // Constructor with parameter name same as member variable name
    MyClass(int value) {
        this->value = value;  // Use 'this' to distinguish member variable from parameter
    }

    void display() {
        std::cout << "Value: " << this->value << std::endl;
    }
};

int main() {
    MyClass obj(10);
    obj.display();  // Output: Value: 10
    return 0;
}
```

Explanation:<br>
The ```this->value``` notation is used to differentiate between the member variable value and the parameter value.


#### Returning the Object Itself
The ```this``` pointer is often used in member functions that need to return the current object itself. This is particularly useful in method chaining.

```cpp
#include <iostream>

class MyClass {
private:
    int value;

public:
    MyClass(int value) : value(value) {}

    // Function that modifies the value and returns the current object
    MyClass& setValue(int value) {
        this->value = value;
        return *this;  // Dereference the 'this' pointer to return the current object
    }

    void display() const {
        std::cout << "Value: " << value << std::endl;
    }
};

int main() {
    MyClass obj(5);
    obj.setValue(10).setValue(20);  // Method chaining using the 'this' pointer
    obj.display();  // Output: Value: 20
    return 0;
}
```

Explanation:<br>
The method setValue returns a reference to the current object (*this), which allows for chaining multiple method calls together.


#### Avoiding Name Conflicts
The ```this``` pointer helps in cases where a parameter has the same name as a member variable, preventing ambiguity.

```cpp
class Example {
private:
    int value;

public:
    Example(int value) { // Constructor parameter name matches the member variable name
        this->value = value; // Uses 'this' to distinguish between member variable and parameter
    }
};
```


### this in Const Member Functions
In const member functions, the this pointer has a slightly different type: it is a pointer to a const object. This means that the function cannot modify the object through the this pointer.

```cpp
class MyClass {
private:
    int value;

public:
    MyClass(int value) : value(value) {}

    void display() const {  // Const member function
        // 'this' pointer is of type 'const MyClass*' here
        std::cout << "Value: " << this->value << std::endl;
    }
};
```

### Key Points about the this Pointer
* Available in Non-static Member Functions: The ```this``` pointer is available in all non-static member functions of a class.
* Points to the Current Object: It always points to the object that invoked the member function.
* Cannot be Modified: You cannot change the value of the this pointer itself, although you can modify the object it points to.


### When Not to Use this
* In most cases, the use of ```this``` is optional when there is no name conflict between the member variables and function parameters.

The ```this``` pointer is a powerful tool in C++ that provides direct access to the current object, allowing for more flexible and intuitive code design, especially in scenarios involving method chaining, self-referencing, and resolving name conflicts.


## Queues
In C++, queues are a type of container adapter provided by the Standard Template Library (STL). They are based on the First In, First Out (FIFO) principle, meaning elements are inserted at the back and removed from the front.

### Key Characteristics of a Queue
* **FIFO Principle:** The first element added to the queue is the first one to be removed.
* **Restricted Access:**
  * Elements can only be added at the back.
  * Elements can only be removed from the front.
* **Underlying Container:**
  * The ```queue``` container adapter is implemented using either a deque or a list as the underlying container.

### Queue Operations
The ```std::queue``` class is defined in the ```<queue>``` header. Below are the primary operations provided:

### Common Methods
| Operation | Description                                  | Example                 |
|-----------|----------------------------------------------|-------------------------|
| push()    | Adds an element to the back of the queue.    | q.push(10);             |
| pop()     | Removes the front element of the queue.      | q.pop();                |
| front()   | Returns a reference to the front element.    | std::cout << q.front(); |
| back()    | Returns a reference to the last element.     | std::cout << q.back();  |
| empty()   | Checks if the queue is empty.                | if(q.empty()) { ... }   |
| size()    | Returns the number of elements in the queue. | std::cout << q.size();  |


### Real-World Use Cases
* **Task Scheduling:** Managing tasks where the first task added is processed first.
* **Print Queue:** Sending print jobs to a printer in the order they were received.
* **Breadth-First Search (BFS) in Graphs:** To explore nodes level by level.


## big 5
###  What is the Rule of Five?
In modern C++ (C++11 and later), if your class **manages resources** (like heap memory, file handles, sockets, etc.), you should define **five special member functions**. These ensure correct and efficient **copying** and **moving** of objects.

### The Big Five (Special Member Functions)

1. Copy Constructor
   - Purpose: Defines how to **copy construct** from another object.
   - Signature:
     MyClass(const MyClass& other);

2. Copy Assignment Operator
   - Purpose: Defines how to **assign** from another object.
   - Signature:
     MyClass& operator=(const MyClass& other);

3. Move Constructor
   - Purpose: Allows ownership of resources to be **moved** instead of copied.
   - Signature:
     MyClass(MyClass&& other);

4. Move Assignment Operator
   - Purpose: Allows move **assignment** of resources.
   - Signature:
     MyClass& operator=(MyClass&& other);

5. Destructor
   - Purpose: Cleans up owned resources.
   - Signature:
     ~MyClass();

If you define **any** of these manually, it's best to **define all five**, to avoid unexpected behavior (this is the "Rule of Five").
Otherwise, if no dynamic memory is used, don't define any (rule of zero).


###  What is `std::move`?

- `std::move(obj)` **does not move anything** by itself.
- It **casts** the object `obj` to an **rvalue reference**, which **enables move semantics**.
- Use it when you want to **explicitly transfer ownership** of a resource.

Example:
MyClass a;
MyClass b = std::move(a); // Calls move constructor

Without `std::move`, the compiler treats `a` as an lvalue, and would call the **copy constructor** instead.

###  Example Class with Rule of Five
```c++
class MyClass {
private:
    int* data;

public:
    // Constructor
    MyClass(int val) : data(new int(val)) {}

    // Copy Constructor
    MyClass(const MyClass& other) : data(new int(*other.data)) {}

    // Copy Assignment
    MyClass& operator=(const MyClass& other) {
        if (this != &other) {
            delete data;
            data = new int(*other.data);
        }
        return *this;
    }

    // Move Constructor
    MyClass(MyClass&& other) noexcept : data(other.data) {
        other.data = nullptr;
    }

    // Move Assignment
    MyClass& operator=(MyClass&& other) {
        if (this != &other) {
            delete data;
            data = other.data;
            other.data = nullptr;
        }
        return *this;
    }

    // Destructor
    ~MyClass() {
        delete data;
    }
};
```

### Why Use `std::move` and Move Semantics?

- Avoid **deep copies** and unnecessary allocations.
- Essential for **performance** in modern C++ (e.g., returning large containers).
- Used heavily in STL containers (e.g., `std::vector`, `std::map`).


###  Why to return *this in copy and move assignment ?
You return *this from an assignment operator so the function can return a reference to the assigned object, allowing chaining like:

a = b = c;


Here, b = c returns a reference to b, so a = (b = c) works correctly.
Without returning *this, chaining assignments wouldn’t compile or behave as expected.

### Shallow Copy vs Deep Copy
* **Shallow copy:** Copies an object's member values directly, so pointers or references still point to the same memory as the original.

* **Deep copy:** Creates a new, independent copy of all dynamically allocated or referenced data, so the new object owns its own resources.

Something to take note of, is when you do not define any of the big 5, the c++ compiler will write them for you. If you do not use any dynamic memory, these will work just fine because they perform a shallow copy. However, if you use dynamic memory a deep copy will be required. Below, is an example of how the compiler would implement the big 5 and you can see hows wrong.

```cpp
#include <iostream>
#include <string>

using namespace std;

struct Example {
    int id;       // built-in type
    string name;  // has its own copy/move semantics
    int* arr;     // raw pointer to dynamic data

    // --- Regular constructor ---
    Example(int i, string n)
        : id(i), name(move(n)) {
        arr = new int[3]{i, i + 1, i + 2};
        cout << "Constructor\n";
    }

    // --- Copy constructor (what the compiler would do by default) ---
    Example(const Example& other)
        : id(other.id),
          name(other.name),
          arr(other.arr)   // shallow copy — both point to same array
    {
        cout << "Copy constructor (default)\n";
    }

    // --- Move constructor (compiler-generated pattern) ---
    Example(Example&& other)
        : id(move(other.id)),
          name(move(other.name)),
          arr(other.arr)   // shallow move of pointer
    {
        other.arr = nullptr; // compiler doesn't do this, we add it for safety
        cout << "Move constructor (default-like)\n";
    }

    // --- Copy assignment ---
    Example& operator=(const Example& other) {
        cout << "Copy assignment (default)\n";
        if (this != &other) {
            id = other.id;
            name = other.name;
            arr = other.arr; // shallow copy again
        }
        return *this;
    }

    // --- Move assignment ---
    Example& operator=(Example&& other) {
        cout << "Move assignment (default-like)\n";
        if (this != &other) {
            id = move(other.id);
            name = move(other.name);
            arr = other.arr;
            other.arr = nullptr; // manual cleanup
        }
        return *this;
    }

    // --- Destructor ---
    ~Example() {
        cout << "Destructor\n";
        delete[] arr;
    }
};

int main() {
    Example a(1, "A");
    Example b = a;             // Copy constructor
    Example c = move(a);       // Move constructor
    b = c;                     // Copy assignment
    c = move(b);               // Move assignment
}

```



## Separation of Implementation and Interface
The concept of separating interface from implementation is a common practice in C++ programming. It involves organizing code into two distinct parts: interface (declarations) and implementation (definitions). This separation improves code clarity, maintainability, and reduces compile-time dependencies.

### Interface vs. Implementation
* Interface: Specifies what a class or function does. It includes the function prototypes, class declarations, and any other details that a user needs to know to use the code. Interfaces are typically placed in header files (.h or .hpp).
* Implementation: Specifies how the class or function works. It contains the actual code that implements the logic defined by the interface. Implementations are usually placed in source files (.cpp).


### Why Separate Interface from Implementation?
* Code Organization: It makes the code easier to read and manage by clearly separating what the code does from how it does it.
* Compile-time Dependency Reduction: Changes in implementation do not require recompiling the files that depend on the interface, reducing build times.
* Encapsulation: The user only needs to know the interface, not the details of the implementation, which can help prevent unintended misuse of the code.
* Maintainability: Modifying the implementation does not affect the files that only rely on the interface, making updates and debugging simpler.

### Example of Separation of Interface and Implementation
Let's create a simple example with a class that represents a Rectangle. We'll separate the interface into a header file (Rectangle.h) and the implementation into a source file (Rectangle.cpp).

#### Step 1: Create the Header File (Rectangle.h)
```cpp
// Rectangle.h
#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle {
public:
    Rectangle(double width, double height);  // Constructor
    double getArea() const;                  // Member function to get area
    double getPerimeter() const;             // Member function to get perimeter
    friend std::ostream& operator<<(std::ostream& os, const Rectangle& r);

private:
    double width;                            // Member variables
    double height;
};

#endif // RECTANGLE_H
```

Explanation:<br>
The header file defines the interface of the Rectangle class.
It contains declarations of the constructor, member functions, and private member variables.
The use of include guards (#ifndef, #define, #endif) prevents multiple inclusions of the same header file and avoids redefinition errors.
Alternatively, you can also use #pragma once see [square.h](./rectangle/square.h)


#### Step 2: Create the Source File (Rectangle.cpp)
```cpp
// Rectangle.cpp
#include "Rectangle.h"

// Constructor definition
Rectangle::Rectangle(double width, double height) : width(width), height(height) {}

// Function to calculate the area of the rectangle
double Rectangle::getArea() const {
    return width * height;
}

// Function to calculate the perimeter of the rectangle
double Rectangle::getPerimeter() const {
    return 2 * (width + height);
}


std::ostream& operator<<(std::ostream& os, const Rectangle& r){
    for(int i=0; i<width;i++) std::cout<<"#";
    std::cout<<std::endl;
    for(int j=0; j<height-2;j++)
    {
        std::cout<<"#";
        for(int i=0;i<width-2;i++) std::cout<<" ";
        std::cout<<"#";
        std::cout<<std::endl;
    }
    for(int i=0; i<width;i++) cout<<"#";   
}

```

Explanation:<br>
The source file contains the implementation of the methods declared in the header file.
Each method is defined using the scope resolution operator :: to specify that these functions belong to the Rectangle class.


#### Step 3: Use the Rectangle Class in a Main Program (main.cpp)
```cpp
#include <iostream>
#include "Rectangle.h"

int main() {
    Rectangle rect(5.0, 3.0);  // Create a Rectangle object with width 5.0 and height 3.0

    std::cout << "Area: " << rect.getArea() << std::endl;
    std::cout << "Perimeter: " << rect.getPerimeter() << std::endl;

    return 0;
}
```

Explanation:<br>
The main program includes the Rectangle.h file, which provides the interface to work with the Rectangle class.
It does not need to know the implementation details that are in Rectangle.cpp.


### Benefits of Separation
* Improved Compilation Speed: Changes made to the implementation in Rectangle.cpp do not require recompiling the code that includes Rectangle.h.
* Modularity: It supports modular development, allowing different team members to work on different parts of the project without interfering with each other.
* Encapsulation: Implementation details are hidden from the user, ensuring a clean and clear interface.


### Common Practice in C++
* Header files (.h, .hpp) contain declarations (interfaces): class definitions, function prototypes, and data type definitions.
* Source files (.cpp) contain implementations: the actual code for the functions and methods.

### Real-World Example: Standard Library
The C++ Standard Library uses this separation extensively. For example, when you use #include <iostream>, you're including only the declarations (interface) of the vector class. The actual implementation of vector operations is handled elsewhere and linked during the compilation process.

### Key Points to Remember
* Include Guards: Always use include guards in header files to prevent multiple inclusions.
* Minimal Dependencies: Keep header files minimal by including only the necessary dependencies.
* Loose Coupling: Aim to keep the implementation and interface loosely coupled to facilitate easier updates and maintenance.
* Separating interface and implementation in C++ is a fundamental design practice that leads to more modular, maintainable, and efficient code. It supports better software architecture principles by clearly defining what each component does without exposing the details of how it does it.



## Compilation of multifile with g++
To compile a multi-file C++ program using g++, follow these steps:

Compile each source file (.cpp) separately into object files (.o):

```bash
g++ -c file1.cpp  # Generates file1.o
g++ -c file2.cpp  # Generates file2.o
```

Link the object files together into a single executable:
```bash
g++ file1.o file2.o -o output_executable
```

Alternatively, you can compile and link in one step:
```bash
g++ file1.cpp file2.cpp -o output_executable
```

* Header files (.h) are included with #include in .cpp files and do not need to be compiled separately.
* Object files can be reused, which speeds up recompilation.



## object oriented covered so far
Object-Oriented Programming (OOP) in C++ is a programming paradigm that uses the concept of objects to design and structure software. It focuses on grouping related data (attributes) and functions (methods) into entities called classes, which serve as blueprints for creating objects. The key principles of OOP in C++ are(classes and objects, encapsulation, inheritance, polymorphism, abstraction):

### Classes and Objects:
A class is a blueprint or template for creating objects. It defines the properties (data) and behaviors (functions) that the objects created from it will have.
An object is an instance of a class. It represents a specific entity with its own unique set of attributes and behaviors.
```cpp
class Car {
public:
    void startEngine() { /* code to start engine */ }
};

Car myCar;  // myCar is an object of the class Car
myCar.startEngine();  // Calling a method on the object
```

### Encapsulation:
Encapsulation involves bundling the data (attributes) and methods (functions) that operate on that data into a single unit (class).
It also restricts direct access to some of the object’s components, usually through the use of access specifiers like private, protected, and public.
This helps protect the internal state of the object and allows controlled access to it.
```cpp
class Account {
private:
    double balance;  // Encapsulated data
public:
    void deposit(double amount) { balance += amount; }  // Controlled access
};
```


## object oriented which we will cover later
### Inheritance:
Inheritance allows a new class (derived class) to inherit attributes and methods from an existing class (base class).
This promotes code reuse and creates a relationship between classes, where the derived class extends or specializes the behavior of the base class.

```cpp
class Vehicle {
public:
    void drive() { /* code to drive vehicle */ }
};

class Car : public Vehicle {  // Car inherits from Vehicle
public:
    void honk() { /* code to honk */ }
};
```

### Polymorphism:
Polymorphism allows functions or methods to work in multiple forms, enabling objects of different classes to be treated as objects of a common base class.
The most common type is function overriding, where a derived class provides its own implementation of a method defined in the base class.
```cpp
class Animal {
public:
    virtual void makeSound() { std::cout << "Animal sound" << std::endl; }
};

class Dog : public Animal {
public:
    void makeSound() override { std::cout << "Woof" << std::endl; }
};
```

### Abstraction:
Abstraction involves hiding complex implementation details and exposing only the necessary parts to the user.
It can be achieved using abstract classes and interfaces, which define a set of functions that must be implemented by derived classes.
```cpp
class Shape {
public:
    virtual double getArea() = 0;  // Pure virtual function
};

class Circle : public Shape {
public:
    double getArea() override { /* calculate area */ }
};
```


### Key Benefits of OOP in C++
* Modularity: Code is organized into classes, making it easier to manage, modify, and reuse.
* Reusability: Through inheritance, common functionality can be shared between classes.
* Scalability: Polymorphism allows code to be more flexible and adaptable to change.
* Maintainability: Encapsulation and abstraction reduce complexity, making the code easier to understand and maintain.

In summary, Object-Oriented Programming in C++ is all about creating modular code using classes and objects that represent real-world entities. It leverages principles like encapsulation, inheritance, polymorphism, and abstraction to build robust and scalable software.


## Practice Examples
1. Write a class for an array of doubles, that starts off with a capacity of 1, but can grow as you add elements and name it "Vector". 
    * Include an insert method that takes an integer position, and a double element as parameters, and inserts element in the array at that position.
    * Include an erase method that takes an integer position, and deletes the element in the array at that position.
    * Write the big 5
    * Overload [] operator to print the element at a given position in the array. Signature ```int operator[](const int position)``` 
    * Overload << operator to print the Vector object(all the elements in the array) 
    * Separate interface and implementation 