# Lecture Notes

## table of contents
1. Classes 
2. Structs
3. Dot operator
4. Destructors
5. Arrow Operator for Pointers
6. Compile time vs runtime for arrays
7. Practice Examples

## Classes
In C++, a class is a user-defined data type that serves as a blueprint for creating objects. It groups both data (attributes) and functions (methods) into a single unit. Classes are central to the concept of Object-Oriented Programming (OOP), which focuses on creating reusable, modular code that models real-world entities.

### Key Concepts of Classes:
* Attributes (Data Members): These are variables that store the state or characteristics of an object.
* Methods (Member Functions): These are functions that define the behavior of the object.
* Objects: Instances of a class created at runtime.
* Encapsulation: Restricting access to certain details of an object while exposing only the essential parts.
* Constructors/Destructors: Special methods for initializing and cleaning up objects.


### Basic Syntax of a Class
```cpp
#include <iostream>
using namespace std;

// Define a class
class Car {
public:
    string brand;
    string model;
    int year;

    // Constructor to initialize the object
    Car(string b, string m, int y) {
        brand = b;
        model = m;
        year = y;
    }

    // Member function to display car information
    void displayInfo() {
        cout << "Brand: " << brand << ", Model: " << model << ", Year: " << year << endl;
    }
};

int main() {
    // Create an object of the Car class
    Car car1("Toyota", "Camry", 2020);
    
    // Call the member function
    car1.displayInfo();  // Output: Brand: Toyota, Model: Camry, Year: 2020

    return 0;
}
```

### Key Features of Classes
1. **Access Specifiers**
Access specifiers define the visibility of the members (attributes and methods) of a class. The three main types of access specifiers in C++ are:

   * public: Members are accessible from outside the class.
   * private: Members are only accessible from within the class. This is the default access level in classes.
   * protected: Members are accessible within the class and its derived classes (used in inheritance).

#### Example of Access Specifiers:
```cpp
#include <iostream>
using namespace std;

class BankAccount {
private:
    double balance;

public:
    // Constructor to initialize balance
    BankAccount(double initialBalance) {
        balance = initialBalance;
    }

    // Public method to deposit money
    void deposit(double amount) {
        balance += amount;
    }

    // Public method to retrieve the balance
    double getBalance() {
        return balance;
    }
};

int main() {
    BankAccount account(1000);  // Create an object with initial balance of 1000

    account.deposit(500);       // Deposit 500
    cout << "Current balance: " << account.getBalance() << endl;  // Output: Current balance: 1500

    return 0;
}
```

2. **Constructors and Destructors**
   * Constructor: A special function that is called automatically when an object is created. It is used to initialize the object. The constructor has the same name as the class and has no return type.

   * Destructor: A special function that is called when an object is destroyed (usually at the end of the program or when an object goes out of scope). It has the same name as the class, prefixed with a tilde (~), and also has no return type.

#### Example of Constructor and Destructor:
```cpp
#include <iostream>
using namespace std;

class Car {
public:
    string brand;
    string model;
    int year;

    // Constructor
    Car(string b, string m, int y) {
        brand = b;
        model = m;
        year = y;
        cout << "Car created: " << brand << " " << model << " " << year << endl;
    }

    // Destructor
    ~Car() {
        cout << "Car destroyed: " << brand << " " << model << " " << year << endl;
    }
};

int main() {
    Car car1("Honda", "Civic", 2021);  // Car created: Honda Civic 2021
    return 0;  // Destructor will be called when the object goes out of scope
}
```

3. **Encapsulation**
Encapsulation is a concept of restricting direct access to some of the object's components and only exposing what is necessary through public methods. This protects the integrity of the data.

In the following example, the private data (balance) can only be accessed and modified via public methods (deposit() and getBalance()):

```cpp
#include <iostream>
using namespace std;

class BankAccount {
private:
    double balance;

public:
    BankAccount(double initialBalance) {
        balance = initialBalance;
    }

    void deposit(double amount) {
        balance += amount;
    }

    double getBalance() {
        return balance;
    }
};

int main() {
    BankAccount account(500);
    account.deposit(250);  // Add money to the balance
    cout << "Current balance: " << account.getBalance() << endl;  // Output: Current balance: 750
    return 0;
}
```

## Dot Operator in C++

### What it does
The **dot operator (`.`)** is used to access **public** members (variables or functions) of an object — that is, to use data or methods that belong to a specific instance of a class or struct.

---

### Basic Example
```cpp
#include <iostream>
using namespace std;

class Person {
public:
    string name;
    int age;

    void sayHello() {
        cout << "Hi, my name is " << name << " and I'm " << age << " years old.\n";
    }
};

int main() {
    Person p1;
    p1.name = "Alice";  // use dot operator to access a member variable
    p1.age = 25;        // set data inside the object

    p1.sayHello();      // use dot operator to call a member function
}
```

**Output:**
```
Hi, my name is Alice and I'm 25 years old.
```

---

## How it works
If `obj` is an object of some class, and `member` is a variable or method in that class, then:

```cpp
obj.member
```
means “access the member named `member` that belongs to `obj`”.

So:
- `obj.variable` → gets or sets a variable inside the object  
- `obj.method()` → calls a function that acts on the object’s data  

---


## Another Example (methods)

```cpp
class Counter {
    int value;
public:
    Counter() : value(0) {}
    void increment() { value++; }
    int get() { return value; }
};

int main() {
    Counter c;
    c.increment();           // dot operator calls a method
    cout << c.get() << '\n'; // dot operator retrieves value
}
```


## Destructors
In C++, destructors are special member functions that are automatically invoked when an object goes out of scope or is explicitly deleted. Their main purpose is to release resources acquired by the object during its lifetime, such as memory, file handles, or network connections. Destructors are crucial for preventing resource leaks, which could otherwise lead to performance issues or application crashes.

### Key points about destructors:
#### Name and syntax:
A destructor has the same name as the class, but with a tilde (~) prefix.
Destructors do not take parameters and do not return anything.
```cpp
class MyClass {
public:
    ~MyClass() {
        // Destructor logic
    }
};
```

#### Automatic invocation:
Destructors are called automatically when an object goes out of scope or is explicitly deleted using the delete keyword for dynamic objects.

##### For example:
* Automatic object: When a local object goes out of scope (end of function or block), its destructor is called automatically.
* Dynamic object: When you delete a dynamically allocated object, its destructor is called.
```cpp
void func() {
    MyClass obj;  // Constructor called here
    // Destructor called automatically when the function exits
}

MyClass* obj = new MyClass();
delete obj;  // Destructor called explicitly with delete
```

Destructors cannot be overloaded. A class can have only one destructor, which has no parameters and no return type.


### Resource Management:
Destructors are often used in conjunction with RAII (Resource Acquisition Is Initialization) to manage resources like memory or file handles.
For example, if a class dynamically allocates memory in its constructor, the destructor should release that memory:
```cpp
class MyClass {
    int* data;
public:
    MyClass() { data = new int[10]; }  // Allocate memory
    ~MyClass() { delete[] data; }      // Release memory
};
```
In summary, destructors play a vital role in managing the lifecycle of objects in C++ and ensuring proper cleanup of resources. Always consider using a virtual destructor in polymorphic base classes and ensure that dynamically allocated resources are properly released.

## Arrow Operator for Pointers
The arrow operator (->) in C++ is used to access members (methods or variables) of an object through a pointer. It is essentially a shorthand for dereferencing the pointer and then accessing the member.

### Syntax:
```cpp
pointer->member
```
This is equivalent to:

```cpp
(*pointer).member
```

### Here’s how it works:
* Dereferencing (*pointer):
When you have a pointer to an object, *pointer dereferences the pointer to give you access to the actual object.
* Member access (.):
Once you have the actual object, you can use the dot operator (.) to access its members (variables or functions).
The arrow operator (->) combines these two steps into one.

### Example:
Let's say you have the following class:

```cpp
class MyClass {
public:
    int value;
    void display() {
        std::cout << "Value: " << value << std::endl;
    }
};
```

Now, if you create a pointer to an object of this class:

```cpp
MyClass obj;
MyClass* ptr = &obj;
```

You can use the arrow operator to access the members of the object through the pointer:

```cpp
ptr->value = 42;       // Equivalent to (*ptr).value = 42;
ptr->display();        // Equivalent to (*ptr).display();
```

Without the arrow operator, you'd have to dereference the pointer first and then access the member like this:

```cpp
(*ptr).value = 42;    // Dereferencing the pointer first, then accessing the member
(*ptr).display();     // Same thing for a member function
```

### Why Use the Arrow Operator?
The arrow operator simplifies the syntax, making the code cleaner and easier to read when working with pointers. Instead of having to type (*ptr).member every time, you can simply use ptr->member.

### Key Points:
* -> is only used when dealing with pointers to objects.
* If you're not using a pointer but a regular object, you should use the dot operator (.) instead.
* The arrow operator is equivalent to dereferencing the pointer and then using the dot operator (.).


### Example with dynamic memory:
If you dynamically allocate an object using new, you access its members through the arrow operator:

```cpp
MyClass* dynamicObj = new MyClass();
dynamicObj->value = 10;  // Use the arrow operator for pointer
dynamicObj->display();
delete dynamicObj;       // Don't forget to free dynamically allocated memory
```


### In a Class with Operator Overloading:
The arrow operator can also be overloaded in user-defined classes. This is rare but can be useful in some advanced cases (e.g., smart pointers).

Here's an example of how you might overload the arrow operator for a class:

```cpp
class Wrapper {
    MyClass obj;
public:
    MyClass* operator->() {
        return &obj;  // Return a pointer to the contained object
    }
};

int main() {
    Wrapper w;
    w->value = 5;    // Uses the overloaded arrow operator
    w->display();    // Access members of MyClass through the wrapper
}
```

In this case, Wrapper overloads the -> operator to return a pointer to an internal object of type MyClass. This allows the user to directly access MyClass members as if they were using a pointer to MyClass.

### Summary:
The arrow operator (->) simplifies accessing members of an object through a pointer.
It is equivalent to dereferencing the pointer and then accessing the member.
It is often used when working with dynamically allocated objects or class instances managed through pointers.

## Structs
Do all the same thing as classes, minus the encapsulation(private, public, protected). Use a struct when you are dealing with simple data structures that don’t need strict encapsulation or private members(but you can also use classes and just not include the private keyword).


## Compile-Time vs Run-Time Arrays in C++
### What “compile time” and “run time” mean
- **Compile time** → when the program is being translated into binary code (before execution). Values known at this point are *static*.  
- **Run time** → when the program is actually executing. Values can depend on *user input* or *program logic*.

---

## Compile-Time Arrays (static arrays)
If you write:
```cpp
int arr[5];
```
then:
- The compiler knows at **compile time** that `arr` has 5 elements.  
- The compiler allocates `5 * sizeof(int)` bytes (usually on the **stack**).  
- The size **cannot change** later.

**Example**
```cpp
int arr[5] = {1, 2, 3, 4, 5};
```

**Non-standard / compiler extension (not portable)**
```cpp
int n = 5;
int arr[n];  // Not standard C++; some compilers (e.g., GCC) allow this as a VLA extension
```

---

## Run-Time Arrays (dynamic arrays)
When the array size isn’t known until the program runs, allocate on the **heap**:

```cpp
int n;
std::cin >> n;          // user supplies size at runtime
int* arr = new int[n];  // allocated dynamically
```

- The array size depends on runtime input.  
- Memory lives on the **heap**.  
- You must free it manually:
```cpp
delete[] arr;
arr = nullptr;
```

---

## Comparison

| Feature | Compile-Time Array | Run-Time Array |
|--------:|:-------------------:|:---------------:|
| Size known when? | Compile time | Run time |
| Memory location | Stack (automatic) | Heap (dynamic) |
| Declaration | `int arr[10];` | `int* arr = new int[n];` |
| Can size vary? | ❌ No | ✅ Yes |
| Must manually delete? | ❌ No | ✅ Yes (`delete[]`) |
| Modern alternative | `std::array<T,N>` | `std::vector<T>` |


## Practice Examples

1.
Define a class `IntArray` that:
- Dynamically allocates an integer array in its constructor using `new int[size]`.
- Initializes all elements to zero.
- Prints a message in the constructor (e.g., “Array created”).
- Has a destructor that releases the allocated memory using `delete[]` and prints “Array destroyed”.

In `main()`, create a local `IntArray` object and observe when the constructor and destructor are called.


---

2.
You are given this class:
```cpp
class Student {
public:
    string name;
    int grade;
    void display() {
        cout << name << " has a grade of " << grade << endl;
    }
};
```

Write code that:
1. Creates a `Student` object (not a pointer) and uses the dot operator to set the fields and call `display()`.
2. Creates a `Student*` pointer using `new`, sets its members, calls `display()` using the arrow operator, and then deletes it.

