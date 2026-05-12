#include<iostream>
#include<string>

using namespace std;

int main()
{
    int num_students;
    cout<<"Enter # of students: ";
    cin>>num_students;

    string* str_arr = new string[num_students];
    
    for(int i =0; i<num_students;i++)
    {
        cout<<"Enter Student "<<i<<" name ";
        cin>>str_arr[i];
    }

    for(int i =0; i<num_students;i++)
        cout<<str_arr[i]<<", ";
    
    delete [] str_arr;
    return 0;
}