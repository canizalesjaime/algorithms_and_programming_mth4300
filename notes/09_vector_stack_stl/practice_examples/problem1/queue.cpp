#include<iostream>
#include<string>
#include "queue.h"

using namespace std;


Queue::Queue() : size_(0), capacity_(1) // Constructor
{
    data_ = new string[capacity_];  // Allocate memory for 1 element
}


Queue::Queue(const Queue& other)//copy constuctor
{
    size_ = other.size_;
    capacity_ = other.capacity_;
    data_ = new string[capacity_];
    for(int i =0;i<size_;i++)   data_[i]=other.data_[i];
}


Queue& Queue::operator=(const Queue &rhs) //copy assignment operator
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


Queue::Queue(Queue&& other)//move constuctor
{
    size_ = other.size_;
    capacity_ = other.capacity_;
    data_=other.data_;

    // must delete cause you want to rid the data of other object
    other.size_=0;
    other.capacity_=1;
    other.data_=new string[other.capacity_];
}


Queue& Queue::operator=(Queue &&rhs) //move assignment operator
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
Queue::~Queue()
{
    delete[] data_;  // Free dynamically allocated memory
}


// Method to add an element to the back of queue
void Queue::push(const string& value)
{
    if (size_ == capacity_) resize();  // Resize if capacity is reached

    data_[size_] = value;
    size_++;
}


// Method to remove an element from the front of queue
string Queue::pop()
{
    if (size_ == 0) return "Nothing to pop";
    string popped = data_[0];
    for(int i=1;i<size_;i++) data_[i-1]=data_[i];
    size_--;
    return popped;
}


//return first element
string Queue::front() const
{
    if (size_ == 0) return "Empty queue";
    else return data_[0];
}


//return last element
string Queue::back() const
{
    if (size_ == 0) return "Empty queue";
    else return data_[size_-1];
}


// check is queue is empty 
bool Queue::isEmpty() const
{
    if(size_==0)return true;
    else return false;
}


// Method to get the size of the vector
size_t Queue::getSize() const 
{
     return size_; 
}


// Helper method to resize the vector when capacity is reached
void Queue::resize() 
{
    capacity_ *= 2;  // Double the capacity
    string* newData = new string[capacity_];  // Allocate larger array

    // Copy old data to new array
    for (size_t i = 0; i < size_; i++)  newData[i] = data_[i];

    delete[] data_;  // Delete old array
    data_ = newData;  // Point to new array
}
