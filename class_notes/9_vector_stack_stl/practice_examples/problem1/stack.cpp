#include<iostream>
#include<string>
#include "stack.h"

using namespace std;


Stack::Stack() : size_(0), capacity_(1) // Constructor
{
    data_ = new string[capacity_];  // Allocate memory for 1 element
}


Stack::Stack(const Stack& other)//copy constuctor
{
    size_ = other.size_;
    capacity_ = other.capacity_;
    data_ = new string[capacity_];
    for(int i =0;i<size_;i++)   data_[i]=other.data_[i];
}


Stack& Stack::operator=(const Stack &rhs) //copy assignment operator
{
    if (this != &rhs) 
    {
        size_ = rhs.size_;
        capacity_ = rhs.capacity_;
        delete[] data_; // clear what was there before
        data_ = new string[capacity_];
        for(int i =0;i<size_;i++)   data_[i]=rhs.data_[i];
    }
    return *this;
}


Stack::Stack(Stack&& other)//move constuctor
{
    size_ = other.size_;
    capacity_ = other.capacity_;
    data_=other.data_;

    // must delete cause you want to rid the data of other object
    other.size_=0;
    other.capacity_=1;
    other.data_=new string[other.capacity_];
}


Stack& Stack::operator=(Stack &&rhs) //move assignment operator
{
    if (this != &rhs)
    {
        size_ = rhs.size_;
        capacity_ = rhs.capacity_;
        delete[] data_; // clear what was there before
        data_ = rhs.data_;

        // must delete cause you want to rid the data of rhs object
        rhs.size_=0;
        rhs.capacity_=1;
        rhs.data_=new string[rhs.capacity_];
    }
    return *this;
}


// Destructor
Stack::~Stack()
{
    delete[] data_;  // Free dynamically allocated memory
}


// Method to add an element to the back of Stack
void Stack::push(const string& value)
{
    if (size_ == capacity_) resize();  // Resize if capacity is reached

    data_[size_] = value;
    size_++;
}


// Method to remove an element from the front of Stack
string Stack::pop()
{
    if (size_ == 0) return "Nothing to pop";
    return data_[--size_];
}


//return last element
string Stack::top() const
{
    if (size_ == 0) return "Empty Stack";
    else return data_[size_-1];
}


// check is Stack is empty 
bool Stack::isEmpty() const
{
    if(size_==0)return true;
    else return false;
}


// Method to get the size of the vector
size_t Stack::getSize() const 
{
     return size_; 
}


// Helper method to resize the vector when capacity is reached
void Stack::resize() 
{
    capacity_ *= 2;  // Double the capacity
    string* newData = new string[capacity_];  // Allocate larger array

    // Copy old data to new array
    for (size_t i = 0; i < size_; i++)  newData[i] = data_[i];

    delete[] data_;  // Delete old array
    data_ = newData;  // Point to new array
}
