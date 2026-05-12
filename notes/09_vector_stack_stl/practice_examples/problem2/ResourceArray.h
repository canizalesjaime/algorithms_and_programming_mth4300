#pragma once

#include <iostream>
#include<string>

using namespace std; 

class ResourceArray 
{
private:
    string* data_;     // Pointer to dynamically allocated array
    size_t size_;      // Number of elements currently in the ResourceArray
    size_t capacity_;  // Capacity of the ResourceArray (how many elements it can hold)

    void resize(); // Helper method to resize the ResourceArray when capacity is reached 

public:
    ResourceArray();
    ResourceArray(const ResourceArray& other);
    ResourceArray(ResourceArray&& other);
    ResourceArray& operator=(const ResourceArray& rhs); 
    ResourceArray& operator=(ResourceArray&& rhs);
    ~ResourceArray();
    
    size_t getSize() const;
    void insert(const size_t index, const string& value);
    void erase(const size_t index);
    string& operator[](size_t index);
    const std::string& operator[](size_t index) const; 
};
