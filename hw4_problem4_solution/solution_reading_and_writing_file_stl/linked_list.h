#include<string>

struct Node
{
    std::string first_name;
    std::string last_name;
    Node* next;
};

// Linked List class
class LinkedList
{
private:
    Node* head;  // Points to the first node (or nullptr if the list is empty)

public:
    // Constructor
    LinkedList();
    // Destructor to clean up memory
    ~LinkedList() ;
    // Method to insert a node by position
    void insert(std::string f_name, std::string l_name, int pos);
    // Method to display the linked list
    void display();
    // Method to delete a node by value
    void deleteByValue(std::string f_name, std::string l_name);
    // Method to delete a node by position
    void deleteByPosition(int pos);
    // get head
    Node* getHead();
    // selection sort
    void selectionSort();
};