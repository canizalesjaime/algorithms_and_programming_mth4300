#include<iostream>
#include "square.h"


// Constructor definition
Square::Square(double s) : side(s) {}

// Function to calculate the area of the Square
double Square::getArea() const 
{
    return side*side;
}

// Function to calculate the perimeter of the Square
double Square::getPerimeter() const
{
    return 4 * side;
}


std::ostream& operator<<(std::ostream& os, const Square& r)
{
    for(int i=0; i<r.side;i++) os<<"# ";
    os<<std::endl;
    for(int j=0; j<r.side-2;j++)
    {
        os<<"# ";
        for(int i=0;i<r.side-2;i++) os<<"  ";
        os<<"# ";
        os<<std::endl;
    }
    for(int i=0; i<r.side;i++) os<<"# ";

    return os;   
}
