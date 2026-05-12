#include <iostream>

using namespace std;

class Complex 
{
private:
    double real;
    double imag;

public:
    // Constructor
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    // Overloading the + operator
    Complex operator+(const Complex& other) 
    {
        return Complex(real + other.real, imag + other.imag);
    }

    // Overloading the == operator
    bool operator==(const Complex& other) 
    {
        return (real == other.real) && (imag == other.imag);
    }

    // Method to display the complex number
    void display() const
    {
        cout << real << " + " << imag << "i" << endl;
    }

    // Friend function for overloading << operator
    friend ostream& operator<<(ostream& os, const Complex& c) 
    {
        os << c.real << " + " << c.imag << "i";
        return os;
    }

    
};

int main() 
{
    Complex c1(3.0, 2.0);
    Complex c2(1.5, 4.5);

    Complex c3 = c1 + c2; // Using the overloaded + operator

    c3.display(); // Output: 4.5 + 6.5i

    return 0;
}