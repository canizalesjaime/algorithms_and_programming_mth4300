# Lecture notes

## table of contents
1. Binary Trees


## Binary Trees
A ```binary tree``` in C++ is a hierarchical data structure in which each node has at most two children, often referred to as the left child and right child. Here's a breakdown of the essential concepts of binary trees and how to implement them in C++.

### Basic Concepts of a Binary Tree:
* Node: A basic unit of a binary tree. Each node contains:
  * Data: The value stored in the node.
  * Left child: A pointer/reference to the left child node.
  * Right child: A pointer/reference to the right child node.

* Root: The topmost node in a binary tree. All other nodes can be accessed by starting from the root.

* Leaf: A node that has no children (both left and right children are nullptr).

* Height: The number of edges on the longest path from the root to a leaf.

* Depth: The number of edges from the root to the node.

### Types of Binary Trees:
* Full Binary Tree: Every node has either 0 or 2 children.
* Complete Binary Tree: All levels are fully filled except possibly the last, which is filled from the left.
* Perfect Binary Tree: All internal nodes have two children, and all leaves are at the same level.
* Balanced Binary Tree: The difference between the height of the left and right subtrees is not more than one for every node.

### Structure of a Node in C++:
The fundamental building block of a binary tree is a node, which can be defined using a ```struct``` in C++.

```cpp
#include <iostream>
using namespace std;

// Define a structure for a node in a binary tree
struct Node {
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
```


### Traversal:
Traversal is the process of visiting all nodes in the tree. There are three primary methods:

1. In-order Traversal (Left, Root, Right):
For BSTs, this traversal returns elements in sorted order.
```cpp
// In-order traversal of the binary tree
void inOrder(Node* root) {
    if (root != nullptr) {
        inOrder(root->left);        // Visit left subtree
        cout << root->data << " ";  // Visit root
        inOrder(root->right);       // Visit right subtree
    }
}
```

2. Pre-order Traversal (Root, Left, Right):
Used for copying a tree or for prefix expression evaluation.
```cpp
// Pre-order traversal of the binary tree
void preOrder(Node* root) {
    if (root != nullptr) {
        cout << root->data << " ";  // Visit root
        preOrder(root->left);       // Visit left subtree
        preOrder(root->right);      // Visit right subtree
    }
}
```

3. Post-order Traversal (Left, Right, Root):
Useful for deleting a tree or postfix expression evaluation.
```cpp
// Post-order traversal of the binary tree
void postOrder(Node* root) {
    if (root != nullptr) {
        postOrder(root->left);      // Visit left subtree
        postOrder(root->right);     // Visit right subtree
        cout << root->data << " ";  // Visit root
    }
}
```


## Wrappers
In C++, wrappers for binary trees are often used to organize code and make tree manipulation cleaner — especially when working with recursive functions or when hiding implementation details from users.

### What’s a Wrapper?
A wrapper is usually a class or function that wraps around raw pointers and utility methods for better usability, abstraction, and maintainability.

### Example 1: Basic binary tree node struct + wrapper class
```cpp
// Node definition (usually private or internal)
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

// Wrapper class for the binary tree
class BinaryTree {
private:
    TreeNode* root;
    void insert(TreeNode*& node, int value) {
    if (node == nullptr)
        node = new TreeNode(val);

    else if (rand() % 2 == 0)
        insertRandom(node->left, val);
    
    else insertRandom(node->right, val);
    }

public:
    BinaryTree() : root(nullptr) {}

    //wrapper method for insert
    void insert(int value) {
        insert(root, value);
    }
    // You can add more wrapper methods like search(), print(), etc.
};
```

### Why use a wrapper class?
* Encapsulation – hides raw pointer management.
* Cleaner API – like tree.insert(10) instead of dealing with node pointers.
* Reusability – once built, you can reuse the tree easily.
* Safer memory handling – you can add destructors for cleanup, smart pointers, etc.


## In class assignments
1. write a method to get the height of the binary tree
2. write a method to find the leftmost node of the tree
3. write a method to count the number of nodes in the tree(size)
