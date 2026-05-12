#include<iostream>
#include<list>

using namespace std;


int main() 
{
    list<int> l;
    l.push_back(10);
    l.push_back(20);
    l.push_back(30);
    l.push_back(40);

    auto it_adv=l.begin();
    advance(it_adv,2);
    l.insert(it_adv,98);

    for(auto it = l.begin(); it != l.end(); ++it)   cout<<*it<<"-> ";
    cout<<endl;


    l.reverse();
    for(auto it = l.begin(); it != l.end(); ++it)   cout<<*it<<"-> ";
    cout<<endl;

    return 0;
}