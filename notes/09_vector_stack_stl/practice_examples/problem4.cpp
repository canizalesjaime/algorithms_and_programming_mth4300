#include<iostream>
#include<stack>

using namespace std;


int stack_fib(int num)
{
    stack<int> s;
    s.push(0);
    s.push(1);
    for(int i = 2; i<num;i++)
    {
        int temp1 = s.top();
        s.pop();
        int temp2=temp1+s.top();
        s.pop();
        s.push(temp1);
        s.push(temp2);
    }

    return s.top();
}


int main()
{
    cout<<stack_fib(5)<<endl;
    return 0;
}