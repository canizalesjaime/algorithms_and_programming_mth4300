#include<iostream>
#include<vector>
#include<stack>
#include<queue>

using namespace std;

vector<string> reverse_k_elements(queue<string> q, const int k)
{
    stack<string> s;
    vector<string> v;
    for(int i = 0; i < k; i++)  
    {
        s.push(q.front());
        q.pop();
    }
    
    for(int i = 0; i < k; i++)
    {
        v.insert(v.begin()+i,s.top());
        s.pop();
    }  
    
    return v;
} 

int main()
{
    queue<string> q1; // object created using constructor

    // Add elements to the queue
    q1.push("Jane");
    q1.push("Ana");
    q1.push("Bob");
    q1.push("Alan");
    q1.push("Tom");
    q1.push("Sarah");
    q1.push("Chris");
    q1.push("Jenn");

    vector<string> v = reverse_k_elements(q1, 3);

    for(int i = 0; i < v.size(); i++) cout<<v[i]<<" ";
    cout<<endl;

    return 0;
}