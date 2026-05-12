#include<iostream>

using namespace std;

double pow(double num, int exp);

int main()
{
    cout<<"Enter number: ";
    double num;
    cin>>num;
    cout<<endl;

    cout<<"Enter exponent: ";
    int exp;
    cin>>exp;
    cout<<endl;

    double result = pow(num,exp);
    cout<<"Result: "<<result<<endl;
    return 0;
}

double pow(double num, int exp)
{
    bool check_neg_exp = false;
    if(exp < 0)
    {
        exp = exp*-1;
        check_neg_exp=true;
    }

    double product=1;
    for (int i = 0; i < exp; i++)
    {
        product=num*product;
    }

    if(check_neg_exp)
    {
        product=1/product;
    }

    return product;
}