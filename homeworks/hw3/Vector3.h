#ifndef VECTOR3_H
#define VECTOR3_H

#include<iostream>
#include<cmath>

using namespace std;

class Vector3
{
private: 
    double x_;
    double y_;
    double z_;

public:
    Vector3(double x=0, double y=0, double z=0);

    Vector3 operator+(const Vector3& other);
    Vector3 operator-(const Vector3& other);
    Vector3 operator*(double scalar);
    Vector3 operator/(double scalar);
    bool operator==(const Vector3& other) const;
    double operator()(int index) const;

    friend ostream& operator<<(ostream& out, const Vector3& p);
    friend istream& operator>>(istream& in, Vector3& p);

    double magnitude() const;
};

#endif // VECTOR3_H