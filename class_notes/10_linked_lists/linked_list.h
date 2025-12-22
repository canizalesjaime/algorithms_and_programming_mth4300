struct Node
{
    int data;
    Node* next;

    Node(int val, Node* n=nullptr):data(val), next(n){}
};

// Linked List class
class LinkedList
{
private:
    Node* head;  // Points to the first node (or nullptr if the list is empty)
    void eraseList(); //helper to delete the whole list

public:
    LinkedList();
    LinkedList(const LinkedList& l);
    LinkedList(LinkedList&& l);
    ~LinkedList();
    LinkedList& operator=(const LinkedList& rhs);
    LinkedList& operator=(LinkedList&& rhs);


    Node* search(int pos); //method to find position(0-based)
    void insert(int value, int pos);// Method to insert a node by position
    void display();// Method to display the linked list(traversal)
    void deleteByPosition(int value);// Method to delete a node by position
};