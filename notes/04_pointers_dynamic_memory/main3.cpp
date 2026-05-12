#include<iostream>
#include<string>

using namespace std;

int main()
{
    int a = 77; // a is an int on the stack
    int* p= new int; // p points to int on the heap(dynamic memory)
    *p=10; // set the variable that p points to, to 10
    

    bool b = true; // b is a bool on the stack
    bool* bool_ptr= new bool; // bool_ptr points to data on the heap(dynamic memory)
    *bool_ptr=false; // set the variable that bool_ptr points to, to false
    
    
    string s = "Hello"; // s is a string on the stack
    string* str_ptr = new string; // str_ptr points to data on the heap(dynamic memory)
    *str_ptr="World"; // set the variable that p points to, to "World"
    cout<<s+" "+*str_ptr<<endl;    
    
    int arr[]={1,2,3}; // arr is on the stack
    int* arr_ptr = new int[4]; // arr_ptr points to data on the heap(dynamic memory)
    for(int i=0;i<4;i++) // set the variable that arr_ptr points to
    {
        arr_ptr[i]=i*2;
        cout<<arr_ptr[i]<<", ";
    } 
    return 0;
}