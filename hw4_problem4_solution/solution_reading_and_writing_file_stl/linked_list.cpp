#include <iostream>
#include "linked_list.h"
#include<limits>


LinkedList::LinkedList() : head(nullptr) {}


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


void LinkedList::insert(std::string f_name, std::string l_name, int pos) 
{
    Node* newNode = new Node();  // Create a new node
    newNode->first_name = f_name;
    newNode->last_name = l_name;
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
        std::cout <<"("<< temp->first_name <<", "<< temp->last_name << ") -> ";
        temp = temp->next;
    }
    std::cout << "nullptr" << std::endl;
}


void LinkedList::deleteByValue(std::string f_name, std::string l_name) 
{
    // If list is empty
    if (head == nullptr)
        std::cout << "List is empty, cannot delete" << std::endl;


    // If the head node holds the value to be deleted
    else if (head->first_name == f_name && head->last_name == l_name) 
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
        while (current != nullptr && head->first_name != f_name && head->last_name != l_name)
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


Node* LinkedList::getHead()
{
    return head;
}


// part 1
// runtime: O(n^2)
// spactime: O(1)
void LinkedList::selectionSort()
{
    int size=0;
    Node* ptr=head;

    while(ptr->next)
    {
        size++;
        ptr = ptr->next;
    }

    for (int i = size; i >= 0; i--)
    {
        Node* end_ptr=head;
        for(int j=0; j<i; j++)
            end_ptr=end_ptr->next;

        ptr=head;

        for (int j =0; j < i; j++)
        {
            if ((ptr->first_name+ptr->last_name) > (end_ptr->first_name+end_ptr->last_name)) 
            {
                std::swap(end_ptr->first_name,ptr->first_name);
                std::swap(end_ptr->last_name,ptr->last_name);
            }
            ptr=ptr->next;           
        }
        
    }
}
