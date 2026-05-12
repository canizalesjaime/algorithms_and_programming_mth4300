#include<iostream>
#include<string>
#include <cmath>

using namespace std;

int foo(float x); //function declaration for foo


int main()
{
    // one line comment
    
    /* this is a 
    multiline comment*/
    int y=foo(3.14); //function call
    cout<<y<<endl;
    return 0;
}


int foo(float x) // function defintion for foo
{
    return floor(x);
}
