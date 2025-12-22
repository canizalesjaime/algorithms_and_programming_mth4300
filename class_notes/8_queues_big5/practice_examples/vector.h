#include <iostream>

class Vector 
{
private:
    double* data_;     // Pointer to dynamically allocated array
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

    double& operator[](size_t index); 
    size_t getSize() const;
    void insert(const size_t index, const double& value);
    void erase(const size_t index);
    
    friend std::ostream& operator<<(std::ostream& os, Vector vec);
};
