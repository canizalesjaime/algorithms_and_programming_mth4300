#include<iostream>
#include"queue_list.h"

using namespace std;

int main() 
{
    QueueList list;


    list.push(10);
    list.push(20);
    list.push(30);
    list.push(40);

    cout<<list.front()<<" "<<list.back()<<endl;

    list.pop();
    list.pop();
    cout<<list.front()<<" "<<list.back()<<endl;

    return 0;
}