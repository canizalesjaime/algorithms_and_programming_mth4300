#include <iostream>
#include "square.h"
#include "rectangle.h"


int main() 
{
    Rectangle rect(10.0, 5.0); 
    std::cout << "Area: " << rect.getArea() << std::endl;
    std::cout << "Perimeter: " << rect.getPerimeter() << std::endl;
    std::cout << rect << std::endl;

    Square squ(8.0);
    std::cout << "Area: " << squ.getArea() << std::endl;
    std::cout << "Perimeter: " << squ.getPerimeter() << std::endl;
    std::cout << squ << std::endl;

    return 0;
}