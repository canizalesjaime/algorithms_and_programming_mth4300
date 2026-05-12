#include<iostream>

using namespace std;


int main()
{
    double num;
    double max=0;

    cout<<"Enter a real number greater than zero(enter a number less than or equal to zero to end program:)"<<endl;
    cin>>num;
    while(num>0)
    {
        if(num>max)
        {
            max=num;
        }
        cout<<"Enter a real number greater than zero(enter a number less than or equal to zero to end program:)"<<endl;
        cin>>num;
    }

    cout<<"Max number entered: "<<max<<endl;
    return 0;
}
