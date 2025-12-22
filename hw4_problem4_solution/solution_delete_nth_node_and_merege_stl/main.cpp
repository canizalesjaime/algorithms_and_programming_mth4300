#include<iostream>
#include "linked_list.h"
#include<limits>
#include<list>

//homework question 1
void test_merge();
LinkedList merge(LinkedList& list1, LinkedList& list2);

//homework question 2
void test_remove_nth_from_end();

// homework question 4
void test_merge_stl();
void test_remove_nth_from_end_stl();


int main()
{
    //test_merge();
    //test_remove_nth_from_end();
    //test_merge_stl();
    test_remove_nth_from_end_stl();
    return 0;
}


void test_merge()
{
    LinkedList list1;
    list1.insert(1,0);
    list1.insert(2,1);
    list1.insert(4,2);
    std::cout << "Linked List 1: ";
    list1.display();

    LinkedList list2;
    list2.insert(0,0);
    list2.insert(2,1);
    list2.insert(3,2);
    list2.insert(5,3);
    std::cout << "Linked List 2: ";
    list2.display();  
    
    LinkedList list3 = merge(list1,list2);
    std::cout << "Linked List 3(merged): ";
    list3.display();
    std::cout << "Linked List 1: ";
    list1.display();
    std::cout << "Linked List 2: ";
    list2.display();
}


LinkedList merge(LinkedList& list1, LinkedList& list2)
{
    LinkedList list3;
    list3.insert(std::numeric_limits<int>::min(),0);//dummy node

    Node* ptr1=list1.getHead(); 
    Node* ptr2=list2.getHead();
    Node* ptr3=list3.getHead();

    while(ptr1 && ptr2) 
    {
        if(ptr1->data < ptr2->data)
        {
            ptr3->next=ptr1;
            ptr1=ptr1->next;
        }

        else
        {
            ptr3->next=ptr2;
            ptr2=ptr2->next;
        }
        ptr3=ptr3->next;
    }
    ptr3->next= ptr1?ptr1:ptr2;

    // clean up 
    list1.setHeadNullPtr(); 
    list2.setHeadNullPtr();
    list3.deleteByPosition(0);//delete dummy node

    return list3;
}


void test_remove_nth_from_end()
{
    LinkedList list1;
    list1.insert(1,0);
    list1.insert(2,1);
    list1.insert(3,2);
    list1.insert(4,3);
    list1.insert(5,4);
    list1.insert(6,5);
    list1.insert(7,6);
    list1.insert(8,7);
    std::cout << "Linked List 1: ";
    list1.display();

    std::cout<<"enter n(1-8): "<<std::endl;
    int n;
    std::cin>>n;
    list1.deleteNthNodeFromEnd(n);
    std::cout << "Linked List 1: ";
    list1.display();
    list1.deleteNthNodeFromEnd(n);
    std::cout << "Linked List 1: ";
    list1.display();
}


void test_merge_stl()
{
    std::list<int> l1={1,2,4};
    std::list<int> l2={0,2,3,5};

    l1.merge(l2);
    for (auto& l:l1)
        std::cout<<l<<" ";

    std::cout<<std::endl;
    for (auto& l:l2)
        std::cout<<l<<" ";
    std::cout<<std::endl;
}


void test_remove_nth_from_end_stl()
{
    std::list<int> l={1,2,3,4,5,6,7,8};
    for (auto& l:l)
        std::cout<<l<<" ";
    std::cout<<std::endl;

    std::cout<<"enter n(1-8): "<<std::endl;
    int n;
    std::cin>>n;
    auto it =l.begin();
    std::advance(it,(l.size()-n));
    l.erase(it);
    for (auto& l:l)
        std::cout<<l<<" ";
    std::cout<<std::endl;


    it=l.begin();
    std::advance(it,(l.size()-n));
    l.erase(it);
    for (auto& l:l)
        std::cout<<l<<" ";
    std::cout<<std::endl;
}