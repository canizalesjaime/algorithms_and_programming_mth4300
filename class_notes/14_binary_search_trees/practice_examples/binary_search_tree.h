struct Node 
{
    int data;             // Data stored in the node
    Node* left;           // Pointer to the left child
    Node* right;          // Pointer to the right child

    // Constructor to initialize a new node
    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BinarySearchTree
{
    private:
        Node* root;


    public:
        BinarySearchTree();
        ~BinarySearchTree();
        BinarySearchTree(const BinarySearchTree& other);
        void copyTree(const Node* from_copy, Node*& to_copy);
        BinarySearchTree(BinarySearchTree&& other);
        BinarySearchTree& operator=(const BinarySearchTree& rhs);
        BinarySearchTree& operator=(BinarySearchTree&& rhs);

        Node* getRoot();
        Node* insert(Node* start, int val);
        void inOrder(Node* start);
        Node* search(int val);
        Node* deleteNode(Node* start, int val);
        Node* findMin(Node* start);
        Node* lowestCommonAncestor(Node* start, int val1, int val2);

    private:
        void destroy(Node* curr_del);//helper function for destructor
        
        
};