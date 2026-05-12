#pragma once

#include<iostream>
#include<string>

using namespace std;

class Stack
{
private:
    string* data_;     // Pointer to dynamically allocated array
    size_t size_;      // Number of elements currently in the vector
    size_t capacity_;  // Capacity of the vector (how many elements it can hold)

    void resize(); // Helper method to resize the vector when capacity is reached
public:
    Stack();
    Stack(const Stack& other);
    Stack& operator=(const Stack &rhs);
    Stack(Stack&& other);
    Stack& operator=(Stack &&rhs);
    ~Stack();

    void push(const string& value);
    string pop();
    string top() const; 
    bool isEmpty() const;
    size_t getSize() const;
};
