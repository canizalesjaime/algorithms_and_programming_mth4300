#include<iostream>
#include"linked_list.h"

using namespace std;

int main() 
{
    LinkedList list;

    // Insert elements
    list.insert(10,0);
    list.insert(20,1);
    list.insert(30,2);
    list.insert(40,3);

    LinkedList list_copy(list);

    // Display the linked list
    cout << "Linked List: ";
    list.display();  // Output: 10 -> 20 -> 30 -> 40 -> nullptr

    // Delete an element
    list.deleteByPosition(2);
    cout << "After deleting 30: ";
    list.display();  // Output: 10 -> 20 -> 40 -> nullptr

    cout << "list copy: ";
    list_copy.display();


    list_copy=move(list);
    cout << "list assignment: ";
    list_copy.display();

    cout << "other: ";
    list.display();
    return 0;
}