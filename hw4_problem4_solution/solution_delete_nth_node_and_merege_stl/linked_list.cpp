#include <iostream>
#include "linked_list.h"
#include<limits>

LinkedList::LinkedList() : head(nullptr) {}


LinkedList::LinkedList(const LinkedList& l) : head(nullptr) 
{
    Node* current = l.head;
    int i=0;
    while (current != nullptr)
    {
        insert(current->data,i);
        current=current->next;
        i++;
    }
}


LinkedList::~LinkedList() 
{
    Node* current = head;
    while (current != nullptr)
    {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
}


void LinkedList::insert(int value, int pos) 
{
    Node* newNode = new Node();  // Create a new node
    newNode->data = value;
    newNode->next = nullptr;

    // empty list case
    if(head==nullptr && pos==0)
        head=newNode;   

    //insert at front of list
    else if(pos==0)
    {
        newNode->next=head;
        head=newNode;
    }

    // Search for the position to insert
    else
    {
        Node* temp = head;
        while(temp!=nullptr && (pos-1)>0)
        {
            temp=temp->next;
            pos--;
        }

        if (temp!=nullptr && pos == 1) 
        {
            newNode->next=temp->next;
            temp->next = newNode;
        }

        else
        {
            std::cout<<"unable to add node, pos invalid"<<std::endl;
            delete newNode;
        }
    }
   
}


void LinkedList::display() 
{
    Node* temp = head;
    while (temp != nullptr) 
    {
        std::cout << temp->data << " -> ";
        temp = temp->next;
    }
    std::cout << "nullptr" << std::endl;
}


void LinkedList::deleteByValue(int value) 
{
    // If list is empty
    if (head == nullptr)
        std::cout << "List is empty, cannot delete" << std::endl;


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

        else std::cout << "Value not found in the list" << std::endl;
    }
    
}


void LinkedList::deleteByPosition(int pos) 
{
    // If list is empty
    if (head == nullptr)
        std::cout << "List is empty, cannot delete" << std::endl;

    // If the head node holds the value to be deleted
    else if(head!=nullptr && pos == 0)
    {
        Node* temp=head;
        head=head->next;
        delete temp;
    }

    // Search for the position to delete
    else
    {
        Node* prev = nullptr;
        Node* curr = head;
        while(curr!=nullptr && pos>0)
        {
            prev=curr;
            curr=curr->next;
            pos--;
        }

        if(curr!=nullptr && pos==0)
        {
            prev->next=curr->next;
            delete curr;
        }
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


Node* LinkedList::getHead()
{
    return head;
}


void LinkedList::setHeadNullPtr()
{
    head=nullptr;
}


//homework question 2
bool LinkedList::deleteNthNodeFromEnd(int n)
{
    insert(std::numeric_limits<int>::min(),0); 
    Node* ptr1=head;
    while(ptr1 && n>0)
    {
        ptr1=ptr1->next;
        n--;
    }

    Node* ptr2=head;
    while (ptr1->next)
    {
        ptr2=ptr2->next;
        ptr1=ptr1->next;
    }
 
    if(ptr2 && n==0)
    {
        Node* curr=ptr2->next;
        ptr2->next=curr->next;
        delete curr;
    }

    else return false;

    deleteByPosition(0);//delete dummy node
    return true;
}