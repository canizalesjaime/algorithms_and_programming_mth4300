#pragma once

#include<iostream>
#include<string>
#include"ResourceArray.h"


using namespace std;

class Stack
{
private:
    ResourceArray data_;
public:
    void push(const string& value);
    void pop();
    string top() const; 
    bool isEmpty() const;
};
