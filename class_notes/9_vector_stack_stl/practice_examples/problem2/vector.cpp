#include<iostream>
#include<string>
#include"vector.h"

using namespace std;



string& Vector::operator[](size_t index) 
{
    if (index >= data_.getSize()) cout<<"Index out of range"<<endl;
    return data_[index];
}


size_t Vector::getSize() const 
{ 
    return data_.getSize(); 
}


void Vector::insert(const size_t index, const string& value)
{
    data_.insert(index,value);
}


void Vector::erase(const size_t index)
{
    data_.erase(index);
}


ostream& operator<<(std::ostream& os, const Vector& vec)
{
    for(size_t i =0; i < vec.data_.getSize(); i++)    os<<vec.data_[i]<<", ";
    os<<endl;

    return os;
}