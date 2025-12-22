#include "Vector3.h"

Vector3::Vector3(double x, double y, double z) : x_(x), y_(y), z_(z)
{
}

Vector3 Vector3::operator+(const Vector3& other)
{
    return Vector3(x_+other.x_, y_+other.y_, z_+other.z_);
}

Vector3 Vector3::operator-(const Vector3& other)
{
    return Vector3(x_-other.x_, y_-other.y_, z_-other.z_);
}

Vector3 Vector3::operator*(double scalar)
{
    return Vector3(x_*scalar, y_*scalar, z_*scalar);
}

Vector3 Vector3::operator/(double scalar)
{
    return Vector3(x_/scalar, y_/scalar, z_/scalar);
}

bool Vector3::operator==(const Vector3& other) const
{
    return x_==other.x_ && y_==other.y_ && z_==other.z_;
}

double Vector3::operator()(int index) const
{
    switch(index)
    {
        case 0:
            return x_;
        case 1:
            return y_;
        case 2:
            return z_;
        default:
            return 0.0;
    }
}

ostream& operator<<(ostream& out, const Vector3& p)
{
    out<<"("<<p.x_<<", "<<p.y_<<", "<<p.z_<<")"<<endl;
    return out;
}

istream& operator>>(istream& in, Vector3& p)
{
    cout<<"Enter a Point(x,y,z): "<<endl;
    in>>p.x_>>p.y_>>p.z_;
    return in;
}

double Vector3::magnitude() const
{
    return sqrt(pow(x_,2)+pow(y_,2)+pow(z_,2));
}