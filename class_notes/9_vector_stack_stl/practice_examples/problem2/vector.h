#pragma once

#include <iostream>
#include<string>
#include"ResourceArray.h"

using namespace std; 

class Vector 
{
private:
    ResourceArray data_;
public:
    string& operator[](size_t index); 
    size_t getSize() const;
    void insert(const size_t index, const string& value);
    void erase(const size_t index);
    
    friend std::ostream& operator<<(ostream& os, const Vector& vec);
};
