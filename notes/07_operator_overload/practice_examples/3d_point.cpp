#include<iostream>
#include<cmath>

using namespace std;

class Point3D
{
private: 
    double x_;
    double y_;
    double z_;

public:
    Point3D(double x=0, double y=0, double z=0): x_(x), y_(y), z_(z){}

    Point3D operator+(Point3D& other)
    {
        return Point3D(x_+other.x_,y_+other.y_,z_+other.z_);
    }

    Point3D operator-(Point3D& other)
    {
        return Point3D(x_-other.x_,y_-other.y_,z_-other.z_);
    }

    Point3D operator*(double scalar)
    {
        return Point3D(x_*scalar,y_*scalar,z_*scalar);
    }

    Point3D operator/(double scalar)
    {
        return Point3D(x_/scalar,y_/scalar,z_/scalar);
    }

    bool operator==(Point3D& other)
    {
        return x_==other.x_ && y_==other.y_ && z_==other.z_;
    }

    friend ostream& operator<<(ostream& out,const Point3D& p)
    {
        out<<"("<<p.x_<<", "<<p.y_<<", "<<p.z_<<")"<<endl;
        return out;
    }

    friend istream& operator>>(istream& in, Point3D& p)
    {
        cout<<"Enter a Point(x,y,z): "<<endl;
        in>>p.x_>>p.y_>>p.z_;
        return in;
    }

    double magnitude()
    {
        return sqrt(pow(x_,2)+pow(y_,2)+pow(z_,2));
    }
};


int main()
{
    Point3D p1(1.0,2.0,3);
    Point3D p2(2.0,4.0,7.0);

    Point3D p3=p1+p2;
    Point3D p4=p1-p2;
    Point3D p5=p1*2;
    Point3D p6=p2/5;

    Point3D p7;
    cin>>p7;

    bool check = p1 == p2;
    cout<<p1<<p2<<p3<<p4<<p5<<p6<<p7<<check<<" magnitude: "<<p1.magnitude();

    return 0;
}