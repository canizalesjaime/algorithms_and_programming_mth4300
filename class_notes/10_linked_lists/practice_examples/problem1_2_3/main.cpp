#include<iostream>
#include "linked_list.h"

int main()
{
    LinkedList list;

    // Insert elements
    ///////////////////////////////////////////////////////////////////////////
    list.insert(100,3);
    std::cout << "Linked List: ";
    list.display();  // Output: nullptr

    list.insert(10,0);
    std::cout << "Linked List: ";
    list.display();  // Output: 10 -> nullptr

    list.insert(20,0);
    std::cout << "Linked List: ";
    list.display();  // Output: 20 -> 10 -> nullptr

    list.insert(30,1);
    std::cout << "Linked List: ";
    list.display();  // Output: 20 -> 30 -> 10 -> nullptr

    list.insert(40,0);
    std::cout << "Linked List: ";
    list.display();  // Output: 40 -> 20 -> 30 -> 10 -> nullptr

    std::cout << "Linked List: ";
    list.display();  // Output: 40 -> 20 -> 30 -> 10 -> nullptr

    list.insert(70,2);
    std::cout << "Linked List: ";
    list.display();  // Output: 40 -> 20 -> 70 -> 30 -> 10 -> nullptr

    list.insert(17,4);
    std::cout << "Linked List: ";
    list.display();  // Output: 40 -> 20 -> 70 -> 30 -> 17 -> 10 -> nullptr

    list.insert(80,6);
    std::cout << "Linked List: ";
    list.display();  // Output: 40 -> 20 -> 70 -> 30 -> 17 -> 10 -> 80 -> nullptr

    list.insert(40,3);
    std::cout << "Linked List: ";
    list.display();  // Output: 40 -> 20 -> 70 -> 40 -> 30 -> 17 -> 10 -> 80 -> nullptr


    // Delete an element
    ///////////////////////////////////////////////////////////////////////////
    list.deleteByPosition(4);
    std::cout << "After deleting position 4: ";
    list.display();  // Output: 40 -> 20 -> 70 -> 40 -> 17 -> 10 -> 80 -> nullptr

    list.deleteByPosition(0);
    std::cout << "After deleting position 0: ";
    list.display();  // Output: 20 -> 70 -> 40 -> 17 -> 10 -> 80 -> nullptr

    list.deleteByPosition(5);
    std::cout << "After deleting position 5: ";
    list.display();  // Output: 20 -> 70 -> 40 -> 17 -> 10 -> nullptr

    // Copy and reverse 
    ///////////////////////////////////////////////////////////////////////////
    LinkedList list2(list);  
    list2.reverse();
    std::cout << "Reverse List2: ";
    list2.display(); // Output: 10 -> 17 -> 40 -> 70 -> 20 -> nullptr
   

    std::cout<<"index 3 of list2: "<<list2.recursiveSearch(list2.search(0),3)->data<<std::endl;
    return 0;
}