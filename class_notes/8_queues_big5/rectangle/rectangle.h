#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle {
public:
    Rectangle(double w, double h);  // Constructor
    double getArea() const;                  // Member function to get area
    double getPerimeter() const;             // Member function to get perimeter

    friend std::ostream& operator<<(std::ostream& os, const Rectangle& r);

private:
    double width;                            // Member variables
    double height;
};

#endif // RECTANGLE_H