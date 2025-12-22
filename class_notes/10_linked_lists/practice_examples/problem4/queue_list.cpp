#include <iostream>
#include <limits>
#include "queue_list.h"

using namespace std;

QueueList::QueueList() : head_(nullptr) {}


QueueList::QueueList(const QueueList& other) : head_(nullptr) 
{
    Node* current = other.head_;
    int i=0;
    while (current != nullptr)
    {
        push(current->data);
        current=current->next;
        i++;
    }
}


QueueList::QueueList(QueueList&& other)
{
    head_=other.head_;
    other.head_=nullptr;
}


QueueList::~QueueList() 
{
    eraseList();
}


void QueueList::eraseList() 
{
    Node* current = head_;
    while (current != nullptr)
    {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
    head_ = nullptr;
}


QueueList& QueueList::operator=(const QueueList& rhs)
{
    if(this!=&rhs)
    {
        eraseList();
        Node* current = rhs.head_;
        int i=0;
        while (current != nullptr)
        {
            push(current->data);
            current=current->next;
            i++;
        }
    }

    return *this;
}


QueueList& QueueList::operator=(QueueList&& rhs)
{
    if(this!=&rhs)
    {
        head_=rhs.head_;
        rhs.head_=nullptr;
    }
    

    return *this;
}


void QueueList::push(int value) 
{
    if(!head_)
    {
        head_=new Node(value);
        return;
    } 
    Node* current = head_;
    while(current->next)    current=current->next;
    current->next =new Node(value);
}


void QueueList::pop() 
{
    if(head_)    
    {
        Node* temp = head_;
        head_=head_->next;
        delete temp;
    }
}   


int QueueList::back() const
{
    if(!head_) return numeric_limits<int>::min();
    Node* current = head_;
    while(current->next)    current=current->next;
    return current->data;
}


int QueueList::front() const
{
    return head_?head_->data:numeric_limits<int>::min();
}

