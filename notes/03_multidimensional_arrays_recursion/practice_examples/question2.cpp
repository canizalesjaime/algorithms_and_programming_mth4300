#include<iostream>

using namespace std;

int nth_fibonacci_number(int n);


int main()
{
    cout<<"Enter n: "<<endl;
    int n;
    cin>>n;

    cout<<nth_fibonacci_number(n)<<endl;
    return 0;
}


int nth_fibonacci_number(int n)
{
    if(n==0) // Base case #1
        return 0;
    
    else if(n==1) // Base case #2
        return 1;

    else 
        return nth_fibonacci_number(n-1) + nth_fibonacci_number(n-2);
}