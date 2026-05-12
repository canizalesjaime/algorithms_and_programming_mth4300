#include<iostream>

using namespace std;


int main()
{
    double arr[10];
    double sum = 0;
    for(int i=0; i<10; i++)
    {
        double num;
        cout<<"Enter real number: "<<endl;
        cin>>num;
        arr[i]=num;
        sum=sum+num;
    }

    for(int i=0; i<10; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl<<"sum: "<<sum<<endl;

    return 0;
}

