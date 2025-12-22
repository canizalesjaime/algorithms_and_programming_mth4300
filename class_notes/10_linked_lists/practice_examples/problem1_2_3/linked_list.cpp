#include <iostream>
#include "linked_list.h"

using namespace std;

LinkedList::LinkedList() : head(nullptr) {}


LinkedList::LinkedList(const LinkedList& other) : head(nullptr) 
{
    Node* current = other.head;
    int i=0;
    while (current != nullptr)
    {
        insert(current->data,i);
        current=current->next;
        i++;
    }
}


LinkedList::LinkedList(LinkedList&& other)
{
    head=other.head;
    other.head=nullptr;
}


LinkedList::~LinkedList() 
{
    eraseList();
}


void LinkedList::eraseList() 
{
    Node* current = head;
    while (current != nullptr)
    {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
    head = nullptr;
}


LinkedList& LinkedList::operator=(const LinkedList& rhs)
{
    if(this!=&rhs)
    {
        eraseList();
        Node* current = rhs.head;
        int i=0;
        while (current != nullptr)
        {
            insert(current->data,i);
            current=current->next;
            i++;
        }
    }

    return *this;
}


LinkedList& LinkedList::operator=(LinkedList&& rhs)
{
    if(this!=&rhs)
    {
        head=rhs.head;
        rhs.head=nullptr;
    }
    

    return *this;
}


Node* LinkedList::search(int pos)
{
    Node* curr = head;
    
    while(curr && pos>0)
    {
        curr=curr->next;
        pos--;
    }
    return pos==0?curr:nullptr;
}


void LinkedList::insert(int value, int pos) 
{
    // empty list case
    if(head==nullptr && pos==0) head= new Node(value);   

    //insert at front of list
    else if(pos==0)
    {
        Node* newNode = new Node(value); 
        newNode->next=head;
        head=newNode;
    }

    // Search for the position to insert
    else
    {
        Node* temp = search(pos-1);
        
        if (temp)     
        {
            Node* newNode = new Node(value, temp->next);
            temp->next = newNode;
        }

        else    cout<<"unable to add node, pos invalid"<<endl;

    }  
}


void LinkedList::display() 
{
    Node* temp = head;
    while (temp != nullptr) 
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "nullptr" << endl;
}


void LinkedList::deleteByValue(int value) 
{
    // If list is empty
    if (head == nullptr)
        cout<< "List is empty, cannot delete" <<endl;


    // If the head node holds the value to be deleted
    else if (head->data == value) 
    {
        Node* temp = head;
        head = head->next;  // Move head to the next node
        delete temp;        // Free memory of old head
    }

    // Search for the node to delete
    else
    {
        Node* current = head;
        Node* previous = nullptr;
        while (current != nullptr && current->data != value)
        {
            previous = current;
            current = current->next;
        }

        // If the value is found, delete the node
        if (current != nullptr)
        {
            previous->next = current->next;
            delete current;
        }

        else cout << "Value not found in the list" << endl;
    }
    
}


void LinkedList::deleteByPosition(int pos) 
{
    // If list is empty
    if (!head)    cout << "List is empty, cannot delete" << endl;

    // If the head node holds the value to be deleted
    else if(head && pos == 0)
    {
        Node* temp=head;
        head=head->next;
        delete temp;
    }

    // Search for the position to delete
    else
    {
        Node* prev = search(pos-1);
        Node* curr = prev->next;    
        if(prev && curr)
        {
            prev->next=curr->next;
            delete curr;
        }
        else    cout<<"unable to delete, pos invalid"<<endl;
    }  
} 


void LinkedList::reverse()
{
    Node* prev=nullptr;
    Node* curr=head;
    while(curr!=nullptr)
    {
        Node* temp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
    }
    head = prev;
}


Node* LinkedList::recursiveSearch(Node* start, int pos)
{
    if (!start) return nullptr;
    if(pos==0) return start;

    return recursiveSearch(start->next,pos-1);

}

