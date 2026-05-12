# Lecture Notes

## table of contents
1. Initialization Lists
2. Lvalues, Rvalues, and Reference Variables in C++
3. Const
4. Default Arguments
5. Namespaces
6. Pass by reference and value


## Initialization Lists
An initialization list in C++ is a way to initialize data members of a class before entering the body of the constructor. It's used to provide values to the data members directly, which is often more efficient and sometimes required, especially when dealing with const or reference members.

Here's the basic syntax of an initialization list in a constructor:

```cpp
// Syntax using initialization list
ClassName(type1 param1, type2 param2) : member1(param1), member2(param2) 
{
    // Constructor body
}

// Syntax not using initialization list
ClassName(type1 param1, type2 param2) 
{
    member1=param1;
    member2=param2;    
}
```

The part after the colon (:) is called the initialization list, where you directly initialize the member variables. Here's a more detailed example:

```cpp
class Example {
private:
    int a;
    int b;
    const int c;     // Const member
    int &ref;        // Reference member

public:
    // Constructor with an initialization list
    Example(int x, int y, int z, int& reference) : a(x), b(y), c(z), ref(reference) {
        // The constructor body can still perform other operations if needed
    }

    void display() {
        std::cout << "a: " << a << ", b: " << b << ", c: " << c << ", ref: " << ref << std::endl;
    }
};
```


### Why Use Initialization Lists?
* Efficiency: Initialization lists can be more efficient than assigning values inside the constructor body because the members are initialized directly, rather than being default-initialized and then assigned new values.

* Const and Reference Members: Const members and reference members must be initialized at the time of their creation. They cannot be assigned new values after they've been constructed, so initialization lists are required.


## Lvalues, Rvalues, and Reference Variables in C++
Understanding lvalues, rvalues, and reference variables in C++ is crucial for mastering memory management, function parameter passing, and efficient code design. Let's break them down.

### Lvalues vs. Rvalues
* Lvalue (Left Value): An object that persists beyond a single expression and has an identifiable memory address.
* Rvalue (Right Value): A temporary object or value that does not persist beyond the expression it is used in.

**Examples**
```cpp
int x = 10;   // 'x' is an lvalue (has memory storage)
x = 20;       // Valid: 'x' can appear on the left side of '='

int y = x + 5; // 'x + 5' is an rvalue (temporary result)
10 = x;        // ❌ Error: '10' is an rvalue, cannot be assigned to
```

#### Lvalue and Rvalue Functions
```cpp
int getValue() { return 42; } // Returns an rvalue

int& getReference(int& a) { return a; } // Returns an lvalue reference
```
* ```getValue()``` returns a temporary value (rvalue).
* ```getReference()``` returns an lvalue reference.

### Lvalue References (T&)
A reference variable (lvalue reference) allows modifying the original object.

```cpp
int a = 5;
int& ref = a;  // 'ref' is an lvalue reference to 'a'
ref = 10;      // Modifies 'a'

int& invalidRef = 10; // ❌ Error: Cannot bind lvalue reference to rvalue
```

### Rvalue References (T&&)
C++11 introduced rvalue references (```T&&```), allowing us to bind to temporary objects and enable move semantics.

```cpp
int&& rref = 10; // rvalue reference binds to a temporary value
rref = 20;       // Modifies the rvalue

int&& anotherRref = getValue(); // OK, function returns an rvalue
```


### ```const``` and References
#### Lvalue Reference to const (const T&)
Allows binding an rvalue to an lvalue reference without modification.

```cpp
const int& ref = 10; // OK: Read-only reference to rvalue
ref = 20;           // ❌ Error: Cannot modify a `const` reference
```

#### Rvalue Reference to const (```const T&&```)
Not commonly used but can be useful in some cases:

```cpp
void func(const int&& x) {
    std::cout << x << std::endl;
}
func(42); // Works with rvalues only
```


## Using const in c++
In C++, the ```const``` keyword is used to define constant values, meaning values that cannot be changed after they are initialized. It can be applied to variables, pointers, function arguments, member functions, and return types to ensure that the data they refer to is not modified. Let's explore its different uses:

#### Const Variables
When you declare a variable with const, its value cannot be changed after initialization.

```cpp
const int maxValue = 100;
// maxValue = 50; // Error: Cannot modify a const variable
```

#### Const Pointers
There are different variations of using const with pointers, and each has a distinct meaning.

* Pointer to a Const Value
This means that the value the pointer points to cannot be modified, but the pointer itself can change to point to something else.

```cpp
const int* ptr;
int x = 10;
int y = 20;
ptr = &x;  // Okay
*ptr = 15; // Error: Cannot modify the value of x through ptr
ptr = &y;  // Okay
```

* Const Pointer to a Value
This means that the pointer itself cannot change to point to another address, but the value it points to can be modified.

```cpp
int* const ptr = &x;
*ptr = 15; // Okay: Can modify the value of x through ptr
ptr = &y;  // Error: ptr itself is const and cannot be reassigned
```

* Const Pointer to a Const Value
Both the pointer and the value it points to cannot be changed.

```cpp
const int* const ptr = &x;
*ptr = 15; // Error: Cannot modify the value of x through ptr
ptr = &y;  // Error: ptr itself is const and cannot be reassigned
```


#### Const Member Functions
A member function declared as const promises not to modify any data members of the class. This is useful for functions that are meant to access data without altering it.

```cpp
class Example {
private:
    int value;

public:
    Example(int v) : value(v) {}

    int getValue() const {  // Const member function
        return value;
    }

    void setValue(int v) {  // Non-const member function
        value = v;
    }
};
```
Calling a const member function on an object will ensure that none of the object's members are modified within that function.


#### Const Function Arguments
Declaring function parameters as const ensures that they are not modified within the function. This is useful for passing parameters by reference or by pointer to prevent accidental modification.

```cpp
void printValue(const int& value) {
    // value = 10; // Error: Cannot modify value since it is const
    std::cout << value << std::endl;
}
```


#### Const Objects
When an object is declared as const, you cannot modify its data members or call any non-const member functions on that object.

```cpp
const Example obj(5);
obj.getValue();    // Okay: getValue() is a const member function
obj.setValue(10);  // Error: Cannot call non-const member function on a const object
```


#### Const Return Types
You can also specify a function's return type as const. This is used to prevent the caller from modifying the returned value directly.

```cpp
const int& getMaxValue() {
    static int maxValue = 100;
    return maxValue;
}
```


### Why Use const?
* Code Safety: Prevents accidental modification of data that should remain unchanged.
* Optimization: Helps the compiler make optimizations since it knows certain values won't change.
* Clear Intent: Improves code readability by explicitly indicating which variables are not supposed to be modified.
* Understanding how to use const correctly is important for writing safer and more efficient C++ code. It can help you avoid bugs and make your code easier to understand and maintain.


## Default Arguments
In C++, default arguments are values that are automatically used by a function if no corresponding arguments are passed to it during a function call. This feature makes functions more flexible and allows them to handle multiple scenarios without the need for multiple overloads.

### How Default Arguments Work
Default arguments are specified in the function declaration, and they are used if the caller does not supply values for those parameters. Here's an example of the syntax:

```cpp
void greet(const std::string &name = "Guest") {
    std::cout << "Hello, " << name << "!" << std::endl;
}
```
In this example, the function greet() can be called with or without an argument:

* If no argument is provided, it uses the default value "Guest".
* If an argument is provided, it uses that value.

### Example Usage of Default Arguments
Here is a practical example using multiple default arguments:

```cpp
#include <iostream>

// Function declaration with default arguments
void introduce(const std::string &name = "John Doe", int age = 30, const std::string &country = "USA") {
    std::cout << "Name: " << name << ", Age: " << age << ", Country: " << country << std::endl;
}

int main() {
    introduce();                      // Uses all default arguments
    introduce("Alice");               // Uses defaults for age and country
    introduce("Bob", 25);             // Uses default for country
    introduce("Charlie", 28, "UK");   // No default arguments used
    return 0;
}
```
#### Output:

```yaml
Name: John Doe, Age: 30, Country: USA
Name: Alice, Age: 30, Country: USA
Name: Bob, Age: 25, Country: USA
Name: Charlie, Age: 28, Country: UK
```


### Rules for Using Default Arguments
Order of Parameters: Default arguments must be specified from right to left. You can't have a non-default parameter after a default parameter.

```cpp
void display(int x = 5, int y = 10); // Valid
void show(int x = 5, int y);         // Invalid: non-default parameter after a default one
```
Default arguments are typically specified in the function declaration (often found in header files) rather than in the function definition. This ensures the defaults are visible to all parts of the code.


## Namespaces
Namespaces in C++ are used to organize code and prevent name conflicts, especially in large projects. They allow you to group related classes, functions, variables, and other declarations under a unique name, reducing the chances of naming collisions when different parts of a program or multiple libraries use the same identifiers.

### What is a Namespace?
A namespace is a declarative region that provides a scope to the identifiers inside it. Identifiers defined in a namespace are scoped to that namespace, which helps to distinguish them from identifiers in other namespaces or the global scope.

### Syntax of Namespaces
Here's the basic syntax for creating a namespace:

```cpp
namespace MyNamespace {
    int myVariable = 42;

    void myFunction() {
        std::cout << "Hello from MyNamespace!" << std::endl;
    }
}
```
In this example, the namespace MyNamespace contains a variable myVariable and a function myFunction. To access these members, you need to use the namespace's name.

#### Accessing Namespace Members
To access members of a namespace, you use the scope resolution operator ```::```:

```cpp
#include <iostream>

int main() {
    std::cout << MyNamespace::myVariable << std::endl;  // Accessing a variable in the namespace
    MyNamespace::myFunction();                         // Calling a function in the namespace
    return 0;
}
```


### Using the using Keyword
To avoid repeatedly typing the namespace name, you can use the using directive:

```cpp
#include <iostream>

// Use the using directive to bring all names from MyNamespace into the current scope
using namespace MyNamespace;

int main() {
    std::cout << myVariable << std::endl;  // No need to use MyNamespace::
    myFunction();                          // Direct access to the function
    return 0;
}
```
This is convenient but can lead to name conflicts, especially if multiple namespaces define members with the same names. A safer alternative is to bring only specific names into scope:

```cpp
#include <iostream>

// Bring only specific members into scope
using MyNamespace::myFunction;

int main() {
    myFunction();          // Direct access to the function
    // std::cout << myVariable << std::endl;  // Error: myVariable is not in the current scope
    return 0;
}
```


### Why Use Namespaces?
* Avoid Naming Conflicts: Namespaces help prevent name clashes, especially in large projects or when integrating third-party libraries.
* Organize Code: They provide a way to logically group related code, making it easier to manage and understand.
* Maintainability: Code organized into namespaces is easier to maintain, modify, and expand.

### Best Practices
* Avoid using namespace in header files: This can lead to name conflicts for anyone including that header file.
* Use namespaces for code organization: Namespaces are a great way to organize large codebases into logical modules.
* Prefer explicit namespace use: While using namespace is convenient, explicitly qualifying names with their namespace reduces ambiguity and potential conflicts.
* Namespaces are a fundamental feature in C++ that help manage the complexity of larger codebases and libraries by providing a structured way to group and access related code elements.


## Pass by reference and value
In C++, when calling a function, you can pass arguments in two main ways: pass by value and pass by reference. Understanding the differences between these two approaches is crucial for writing efficient and correct code.

### Pass by Value
When you pass a variable by value to a function, a copy of the variable is made. This means that changes to the variable inside the function do not affect the original variable outside the function.

#### Example of Pass by Value
```cpp
#include <iostream>

void modifyValue(int value) {
    value = 20;  // This change will not affect the original variable
}

int main() {
    int number = 10;
    modifyValue(number);
    std::cout << "Number after modifyValue: " << number << std::endl;  // Output: 10
    return 0;
}
```
Output:
```javascript
Number after modifyValue: 10
```

In this example, even though the function modifyValue changes the value of its parameter, the original number variable remains unchanged because it was passed by value.

#### Characteristics of Pass by Value
* A copy of the argument is created.
* Changes made to the parameter inside the function do not affect the original argument.
* It can be less efficient if the argument is a large object because copying large data can be time-consuming.


### Pass by Reference
When you pass a variable by reference to a function, the function receives a reference to the original variable. This means that any changes made to the variable inside the function directly affect the original variable outside the function.

#### Example of Pass by Reference
```cpp
#include <iostream>

void modifyValue(int &value) {  // The & symbol denotes a reference
    value = 20;  // This change will affect the original variable
}

int main() {
    int number = 10;
    modifyValue(number);
    std::cout << "Number after modifyValue: " << number << std::endl;  // Output: 20
    return 0;
}
```
Output:
```javascript
Number after modifyValue: 20
```
In this example, the modifyValue function changes the original number variable because it was passed by reference.

#### Characteristics of Pass by Reference
* The function receives a reference to the original argument.
* Changes made to the parameter inside the function affect the original variable.
* More efficient than pass by value for large objects because it avoids copying data.

### Pass by Pointer (Similar to Pass by Reference)
Pass by pointer is another way to achieve similar behavior to pass by reference but uses pointers instead of references. It requires explicit dereferencing to access or modify the value.

```cpp
#include <iostream>

void modifyValue(int *value) {  // Pointer is used
    *value = 30;  // Dereference the pointer to modify the original value
}

int main() {
    int number = 10;
    modifyValue(&number);  // Pass the address of the variable
    std::cout << "Number after modifyValue: " << number << std::endl;  // Output: 30
    return 0;
}
```
Output:
```javascript
Number after modifyValue: 30
```

### Differences Between Pass by Value and Pass by Reference
|           Feature           |                Pass by Value               |                    Pass by Reference                    |
|:---------------------------:|:------------------------------------------:|:-------------------------------------------------------:|
| Data Handling               | Creates a copy of the data                 | Uses a reference to the original data                   |
| Memory Usage                | More memory is used for copying large data | Less memory as no copy is made                          |
| Effect on Original Variable | Original variable remains unchanged        | Original variable can be modified                       |
| Safety                      | Safer, as it prevents accidental changes   | Less safe, as changes directly affect the original data |
| Syntax                      | Uses standard parameter notation           | Uses & for reference parameters                         |


### When to Use Pass by Value and Pass by Reference
#### Pass by Value:
* Use when the function does not need to modify the original value.
* Preferred for primitive data types (like int, float, char) since the overhead of copying is minimal.

#### Pass by Reference:
* Use when the function needs to modify the original value.
* Use for large objects or data structures to avoid the overhead of copying.
* Useful for functions that need to return multiple values (through reference parameters).


### Advantages and Disadvantages
#### Pass by Value:
Advantages: Simpler and safer as it avoids unintended side effects.
Disadvantages: Can be inefficient for large objects due to copying overhead.


#### Pass by Reference:
Advantages: More efficient for large data structures and allows modification of original data.
Disadvantages: Can lead to unintended side effects if not used carefully.
Choosing between pass by value and pass by reference depends on whether you want to modify the original data and the efficiency considerations for large objects.

