#include<iostream>

using namespace std;

void test_conditional(int num);

int main()
{
    int num;
    cout<<"enter a num: ";
    cin>>num;
    cout<<endl;
    test_conditional(num);
    cout<<endl;
    return 0;
}


void test_conditional(int num)
{
    if(num % 2 ==0 && num %3==0)
    {
        cout<<"number is divisible by 2 and 3";
    }

    else if (num % 2==0)
    {
        cout<<"number is divisible by 2 only";
    }

    else if (num % 3==0)
    {
        cout<<"number is divisible by 3 only";
    }

    else
    {
        cout<<"number is not divisble by 2 or 3";
    }
    
}