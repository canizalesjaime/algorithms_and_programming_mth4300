struct Node
{
    int data;
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
    // Copy Constructor
    LinkedList(const LinkedList& l) ;
    // Destructor to clean up memory
    ~LinkedList() ;
    // Method to insert a node by position
    void insert(int value, int pos);
    // Method to display the linked list
    void display();
    // Method to delete a node by value
    void deleteByValue(int value);
    // Method to delete a node by position
    void deleteByPosition(int pos);
    // reverse linkedlist
    void reverse();


    Node* getHead();
    void setHeadNullPtr();//only use inside of merge function, or memory leak can occur
    bool deleteNthNodeFromEnd(int n);
};