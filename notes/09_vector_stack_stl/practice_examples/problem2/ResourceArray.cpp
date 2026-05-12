#include<iostream>
#include<string>
#include"ResourceArray.h"

using namespace std;


ResourceArray::ResourceArray() : size_(0), capacity_(1)
{ 
    data_=new string[capacity_]; 
}


ResourceArray::ResourceArray(const ResourceArray& other)
{
    size_ = other.size_;
    capacity_ = other.capacity_;
    data_ = new string[capacity_];
    for(int i =0;i<size_;i++)   data_[i]=other.data_[i];
}


ResourceArray::ResourceArray(ResourceArray&& other)
{
    size_ = other.size_;
    capacity_ = other.capacity_;
    data_=other.data_;

    other.size_=0;
    other.capacity_=1;
    other.data_=new string[other.capacity_];
}


ResourceArray& ResourceArray::operator=(const ResourceArray &rhs)
{
    if (this != &rhs) 
    {
        size_ = rhs.size_;
        capacity_ = rhs.capacity_;
        delete[] data_; 
        data_ = new string[capacity_];
        for(int i =0;i<size_;i++)   data_[i]=rhs.data_[i];
    }
    return *this;
}


ResourceArray& ResourceArray::operator=(ResourceArray &&rhs) //move assignment operator
{
    if (this != &rhs)
    {
        size_ = rhs.size_;
        capacity_ = rhs.capacity_;
        delete[] data_; 
        data_ = rhs.data_;

        rhs.size_=0;
        rhs.capacity_=1;
        rhs.data_=new string[rhs.capacity_];
    }
    return *this;
}


ResourceArray::~ResourceArray()
{
    delete[] data_;  
}


size_t ResourceArray::getSize() const 
{ 
    return size_; 
}


void ResourceArray::resize()
{
    capacity_ *= 2; 
    string* new_data = new string[capacity_];  

    for (size_t i = 0; i < size_; i++) new_data[i] = data_[i];

    delete[] data_;  
    data_ = new_data;  
}


void ResourceArray::insert(const size_t index, const string& value)
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


void ResourceArray::erase(const size_t index)
{
    if (size_ == 0 || index >= size_)
    {
        cout<<"Index out of range";
        return;
    }
    
    for(size_t i=index; i<size_-1; i++)   data_[i]=data_[i+1];
    size_--;
}


string& ResourceArray::operator[](size_t index) 
{
    if (index >= size_) cout<<"Index out of range"<<endl;
    return data_[index];
}

const std::string& ResourceArray::operator[](size_t index) const
{
    if (index >= size_) cout<<"Index out of range"<<endl;
    return data_[index];
}