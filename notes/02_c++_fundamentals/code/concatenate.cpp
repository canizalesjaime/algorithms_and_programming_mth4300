#include<iostream>
#include<string>

using namespace std;

string string_operator_plus(string str1, string str2);

int main()
{
    cout<<"Enter First String: ";
    string s1;
    cin>>s1;
    cout<<endl;

    cout<<"Enter Second String: ";
    string s2;
    cin>>s2;
    
    string s3 = string_operator_plus(s1,s2);
    cout<<s3<<endl;
    return 0;
}


string string_operator_plus(string str1, string str2)
{
    string result = str1 + str2 +"s"; 
    return result;
}
