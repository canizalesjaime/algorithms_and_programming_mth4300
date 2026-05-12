#pragma once

#include<iostream>
#include<string>

using namespace std;

class Queue
{
private:
    string* data_;     // Pointer to dynamically allocated array
    size_t size_;      // Number of elements currently in the vector
    size_t capacity_;  // Capacity of the vector (how many elements it can hold)

    void resize(); // Helper method to resize the vector when capacity is reached
public:
    Queue();
    Queue(const Queue& other);
    Queue& operator=(const Queue &rhs);
    Queue(Queue&& other);
    Queue& operator=(Queue &&rhs);
    ~Queue();

    void push(const string& value);
    string pop();
    string front() const;
    string back() const; 
    bool isEmpty() const;
    size_t getSize() const;
};
