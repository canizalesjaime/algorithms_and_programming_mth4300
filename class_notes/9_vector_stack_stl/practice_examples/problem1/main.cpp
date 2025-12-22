#include<iostream>
#include "queue.h"
#include "stack.h"
#include "vector.h"

using namespace std;

Vector reverse_k_elements(Queue q, const int k)
{
    Stack s;
    Vector v;
    for(int i = 0; i < k; i++)  s.push(q.pop());

    for(int i = 0; i < k; i++)  v.insert(i,s.pop());
    
    return v;
} 

int main()
{
    Queue q1; // object created using constructor

    // Add elements to the queue
    q1.push("Jane");
    q1.push("Ana");
    q1.push("Bob");
    q1.push("Alan");
    q1.push("Tom");
    q1.push("Sarah");
    q1.push("Chris");
    q1.push("Jenn");

    Vector v = reverse_k_elements(q1, 3);

    cout<<v;

    return 0;
}
