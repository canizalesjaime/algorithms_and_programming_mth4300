#include<iostream>
#include"vector.h"

using namespace std;


Vector::Vector() : size_(0), capacity_(1), data_(new double[capacity_])
{
    data_ = new double[capacity_];  
}


Vector::Vector(const Vector& other)
{
    cout<<"copy constructor called"<<endl;
    size_ = other.size_;
    capacity_ = other.capacity_;
    data_ = new double[capacity_];
    for(int i =0;i<size_;i++)   data_[i]=other.data_[i];
}


Vector::Vector(Vector&& other)
{
    cout<<"move constructor called"<<endl;
    size_ = other.size_;
    capacity_ = other.capacity_;
    data_=other.data_;

    other.size_=0;
    other.capacity_=1;
    other.data_=new double[other.capacity_];
}


Vector& Vector::operator=(const Vector &rhs)
{
    cout<<"copy assignment called "<<endl;
    if (this != &rhs) 
    {
        size_ = rhs.size_;
        capacity_ = rhs.capacity_;
        delete[] data_; 
        data_ = new double[capacity_];
        for(int i =0;i<size_;i++)   data_[i]=rhs.data_[i];
    }
    return *this;
}


Vector& Vector::operator=(Vector &&rhs) //move assignment operator
{
    cout<<"move assignment called"<<endl;
    if (this != &rhs)
    {
        size_ = rhs.size_;
        capacity_ = rhs.capacity_;
        delete[] data_; 
        data_ = rhs.data_;

        rhs.size_=0;
        rhs.capacity_=1;
        rhs.data_=new double[rhs.capacity_];
    }
    return *this;
}


Vector::~Vector()
{
    cout<<"destructor called"<<endl;
    delete[] data_;  
}


double& Vector::operator[](size_t index) 
{
    if (index >= size_) cout<<"Index out of range";
    return data_[index];
}


size_t Vector::getSize() const 
{ 
    return size_; 
}


void Vector::resize()
{
    capacity_ *= 2; 
    double* new_data = new double[capacity_];  

    for (size_t i = 0; i < size_; i++) new_data[i] = data_[i];

    delete[] data_;  
    data_ = new_data;  
}


void Vector::insert(const size_t index, const double& value)
{
    if(index > size_)
    {
        cout<<"Index out of range"<<endl;
        return;
    }

    if(size_==capacity_) resize();

    for(size_t i=size_; i>index; i--)   data_[i]=data_[i-1];
    data_[index]=value;
    size_++;
}


void Vector::erase(const size_t index)
{
    if (size_ == 0 || index >= size_)
    {
        cout<<"Index out of range";
        return;
    }
    
    for(size_t i=index; i<size_-1; i++)   data_[i]=data_[i+1];
    size_--;
}


ostream& operator<<(std::ostream& os, Vector vec)
{
    for(size_t i =0; i < vec.size_; i++)    cout<<vec.data_[i]<<", ";
    cout<<endl;
}