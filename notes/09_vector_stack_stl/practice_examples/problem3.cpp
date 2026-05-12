#include<iostream>
#include<stack>
#include<string>

using namespace std;


bool valid_parenthesis(string parens)
{
    stack<char> s;
    for(int i =0; i<parens.length();i++)
    {
        if(parens[i]=='(' || parens[i]=='{' || parens[i]=='[')   
            s.push(parens[i]);

        else if(!s.empty())
        {
            if(s.top()=='(' && parens[i]==')')  s.pop();
            else if(s.top()=='{' && parens[i]=='}')  s.pop();
            else if(s.top()=='[' && parens[i]==']')  s.pop();
            else return false;
        }

        else return false; 
    }
    return s.empty();
}


int main()
{
    cout<<boolalpha<<valid_parenthesis("[()(){}]")<<endl<<valid_parenthesis("(}")<<endl;

    return 0;
}