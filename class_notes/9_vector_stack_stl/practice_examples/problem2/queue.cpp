#include<iostream>
#include<string>
#include "queue.h"

using namespace std;


// Method to add an element to the back of queue
void Queue::push(const string& value)
{
    data_.insert(data_.getSize(),value);
}


// Method to remove an element from the front of queue
void Queue::pop()
{
    data_.erase(0);
}


//return first element
string Queue::front() const
{
    if (data_.getSize() == 0) return "Empty queue";
    else return data_[0];
}


//return last element
string Queue::back() const
{
    if (data_.getSize() == 0) return "Empty queue";
    else return data_[data_.getSize()-1];
}


// check is queue is empty 
bool Queue::isEmpty() const
{
    if(data_.getSize()==0)return true;
    else return false;
}

