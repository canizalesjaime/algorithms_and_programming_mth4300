#include <iostream>

//using namespace std;

template <typename T>
class MyVector {
private:
    T* data;          // Pointer to dynamically allocated array
    size_t size;      // Number of elements currently in the vector
    size_t capacity;  // Capacity of the vector (how many elements it can hold)

public:
    // Constructor
    MyVector() : size(0), capacity(1) {
        data = new T[capacity];  // Allocate memory for 1 element
    }

    // Destructor
    ~MyVector() {
        delete[] data;  // Free dynamically allocated memory
    }

    // Method to add an element
    void push_back(const T& value) {
        if (size == capacity) {
            resize();  // Resize if capacity is reached
        }
        data[size] = value;
        size++;
    }

    // Method to access elements
    T& operator[](size_t index) {
        if (index >= size) throw std::out_of_range("Index out of range");
        return data[index];
    }

    // Method to get the size of the vector
    size_t getSize() const { return size; }

private:
    // Helper method to resize the vector when capacity is reached
    void resize() {
        capacity *= 2;  // Double the capacity
        T* newData = new T[capacity];  // Allocate larger array

        // Copy old data to new array
        for (size_t i = 0; i < size; i++) {
            newData[i] = data[i];
        }

        delete[] data;  // Delete old array
        data = newData;  // Point to new array
    }
};


template <typename Elem>
void swap(Elem& first, Elem& second)
{
    Elem temp=first;
    first=second;
    second=temp;
}

int main()
{
    MyVector<double> vec;
    vec.push_back(3.14);
    vec.push_back(2.718);
    for(int i=0;i<vec.getSize();i++)std::cout<<vec[i]<<" ";
    std::cout<<std::endl;


    int a,b;
    a=7;
    b=8;

    swap(a,b);
    std::cout<<a<<std::endl;

    return 0;
}