#pragma once

#include<iostream>
#include<string>
#include"ResourceArray.h"

using namespace std;

class Queue
{
private:
    ResourceArray data_;
public:
    void push(const string& value);
    void pop();
    string front() const;
    string back() const; 
    bool isEmpty() const;
};
