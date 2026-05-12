#include<iostream>
#include "rectangle.h"


// Constructor definition
Rectangle::Rectangle(double w, double h) : width(w), height(h) {}

// Function to calculate the area of the rectangle
double Rectangle::getArea() const 
{
    return width * height;
}

// Function to calculate the perimeter of the rectangle
double Rectangle::getPerimeter() const
{
    return 2 * (width + height);
}


std::ostream& operator<<(std::ostream& os, const Rectangle& r)
{
    for(int i=0; i<r.width;i++) os<<"# ";
    os<<std::endl;
    for(int j=0; j<r.height-2;j++)
    {
        os<<"# ";
        for(int i=0;i<r.width-2;i++) os<<"  ";
        os<<"# ";
        os<<std::endl;
    }
    for(int i=0; i<r.width;i++) os<<"# ";

    return os;   
}
