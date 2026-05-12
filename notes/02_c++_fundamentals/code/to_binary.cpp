#include<iostream>

using namespace std;

string to_binary(int num);

int main()
{
    cout<<"Enter number: ";
    double num;
    cin>>num;
    cout<<endl;

    string bin = to_binary(num);
    cout<<"Binary Representation: "<<bin<<endl;
    return 0;
}

string to_binary(int num)
{
    string bin_num = "";

    while(num>0)
    {
        if(num%2==0)
        {
            bin_num="0"+bin_num;
        }

        else if(num%2==1)
        {
            bin_num="1"+bin_num;
        }

        num=num/2;
    }

    return bin_num;
}