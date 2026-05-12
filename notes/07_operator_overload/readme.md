# Lecture Notes

## table of contents
1. Operator Overloading  
2. Practice Examples


## Operator Overloading
Operator overloading in C++ allows you to redefine how operators work with user-defined data types. This feature lets you specify how operators (like ```+```, ```-```, ```==```, etc.) behave when used with instances of classes or structs. Operator overloading helps make code more intuitive and readable by enabling the use of familiar operators with custom types.

### Basics of Operator Overloading
To overload an operator, you create a special member function of a class that defines the operator's behavior when applied to objects of that class. The syntax generally follows this pattern:

```cpp
return_type operator symbol (parameter_list);
```

**return_type:** The type that the operator function returns.<br>
**symbol:** The operator you are overloading (e.g., ```+```, ```-```, ```==```, etc.).<br>
**parameter_list:** The arguments for the operator. For most operators, this includes one or two parameters.<br>

### Example: Overloading the + Operator
Let's create a simple example of a class Complex that represents complex numbers. We will overload the + operator to add two complex numbers.

```cpp
#include <iostream>

class Complex {
private:
    double real;
    double imag;

public:
    // Constructor
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    // Overloading the + operator
    Complex operator+(const Complex& other) {
        return Complex(real + other.real, imag + other.imag);
    }

    // Method to display the complex number
    void display() const {
        std::cout << real << " + " << imag << "i" << std::endl;
    }
};

int main() {
    Complex c1(3.0, 2.0);
    Complex c2(1.5, 4.5);

    Complex c3 = c1 + c2; // Using the overloaded + operator

    c3.display(); // Output: 4.5 + 6.5i

    return 0;
}
```

In this example:<br>
We defined the operator+ function to add two Complex objects.
The function returns a new Complex object that represents the sum of the two complex numbers.
The ```+``` operator can now be used with Complex objects as if it were a built-in data type.

### Rules for Operator Overloading
* Predefined Operators Cannot Be Changed: You cannot change the precedence, associativity, or arity of an operator.
* Existing Operators Only: You cannot create new operators; you can only overload existing ones.
* One Argument for Unary, Two for Binary: Unary operators take one operand, and binary operators take two.
* At Least One User-defined Type: At least one operand must be a user-defined data type (like a class or struct).


### Commonly Overloaded Operators
* Arithmetic Operators: ```+```, ```-```, ```*```, ```/```, ```%```
* Comparison Operators: ```==```, ```!=```, ```<```, ```>```, ```<=```, ```>=```
* Increment/Decrement Operators: ```++```, ```--```
* Stream Insertion/Extraction: ```<<```, ```>>```


### Example: Overloading the == Operator
Here’s how to overload the ```==``` operator for the Complex class to compare two complex numbers:

```cpp
// Overloading the == operator
bool operator==(const Complex& other) {
    return (real == other.real) && (imag == other.imag);
}
```

This function checks if the real and imag parts of two Complex objects are equal.

### Friend Functions for Operator Overloading
Sometimes it's useful to overload operators using friend functions, especially when you need to access private members of a class. Here's an example of overloading the << operator for ostream to print a Complex object:

```cpp
#include <iostream>

class Complex {
private:
    double real;
    double imag;

public:
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    // Friend function for overloading << operator
    friend std::ostream& operator<<(std::ostream& os, const Complex& c) {
        os << c.real << " + " << c.imag << "i";
        return os;
    }
};

int main() {
    Complex c1(3.0, 2.0);
    std::cout << "Complex number: " << c1 << std::endl; // Output: Complex number: 3 + 2i

    return 0;
}
```
In this example:

We use a friend function to overload the ```<<``` operator.
The friend function can access private data members of the Complex class directly.


### Summary
* Operator overloading allows you to redefine how operators work with user-defined types.
* It makes code more intuitive by allowing the use of standard operators with custom objects.
* Not all operators can be overloaded, and you cannot change the fundamental behavior of an operator (like its precedence).
* Operator overloading helps create clean, readable, and maintainable code when used wisely.


## Practice Examples
1. Creata a class for a 3D points. Overload ```+``` and ```-``` to add corresponding indices, overload ```*``` and ```\``` for scalar multiplication\division. Overload extraction and insertion operators to print and input points, and overload ```==``` to check if two points are equal. Finally write a function that returns the magnitude of the point and prints it. 