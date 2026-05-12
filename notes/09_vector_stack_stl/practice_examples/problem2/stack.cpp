#include<iostream>
#include<string>
#include "stack.h"

using namespace std;


// Method to add an element to the back of Stack
void Stack::push(const string& value)
{
   data_.insert(data_.getSize(),value);
}


// Method to remove an element from the front of Stack
void Stack::pop()
{
    data_.erase(data_.getSize()-1);
}


//return last element
string Stack::top() const
{
    if (data_.getSize() == 0) return "Empty Stack";
    return data_[data_.getSize()-1];
}


// check is Stack is empty 
bool Stack::isEmpty() const
{
    if(data_.getSize()==0)return true;
    else return false;
}

