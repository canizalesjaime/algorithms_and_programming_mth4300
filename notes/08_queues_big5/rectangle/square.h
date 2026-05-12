#pragma once
#include"rectangle.h"

class Square {
public:
    Square(double s);  // Constructor
    double getArea() const;                 // Member function to get area
    double getPerimeter() const;            // Member function to get perimeter

    friend std::ostream& operator<<(std::ostream& os, const Square& r);

private:
    double side;
};
