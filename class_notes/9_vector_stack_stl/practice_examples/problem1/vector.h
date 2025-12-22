#pragma once

#include <iostream>
#include<string>

using namespace std; 

class Vector 
{
private:
    string* data_;     // Pointer to dynamically allocated array
    size_t size_;      // Number of elements currently in the vector
    size_t capacity_;  // Capacity of the vector (how many elements it can hold)

    void resize(); // Helper method to resize the vector when capacity is reached 

public:
    Vector();
    Vector(const Vector& other);
    Vector(Vector&& other);
    Vector& operator=(const Vector& rhs); 
    Vector& operator=(Vector&& rhs);
    ~Vector(); 

    string& operator[](size_t index); 
    size_t getSize() const;
    void insert(const size_t index, const string& value);
    void erase(const size_t index);
    
    friend std::ostream& operator<<(ostream& os, const Vector& vec);
};
