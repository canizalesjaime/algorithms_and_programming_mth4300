#include<iostream>

using namespace std;

int main()
{
    int num = 7;

    int* ptr = &num;

    *ptr=11;

    cout<<"address of num: "<<ptr<<", content of num(as per ptr): "<<*ptr<<endl;
    cout<<"num variable: "<<num<<endl;
    return 0;
}