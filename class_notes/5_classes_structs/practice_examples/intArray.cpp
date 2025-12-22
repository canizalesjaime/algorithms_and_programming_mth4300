#include<iostream>

using namespace std;


class IntArray
{
private:
    int* data_;
    size_t size_;
    
public:
IntArray(size_t size):size_(size)
{
    cout<<"constructor called"<<endl;
    data_=new int[size_];
    for(size_t i =0; i < size_; i++)    data_[i]=0;
}

~IntArray()
{
    delete[] data_;
    data_=nullptr;
    size_=0;
    cout<<"Array destroyed"<<endl;
}
};


int main()
{
    IntArray arr(10);
    return 0;
}