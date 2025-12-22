#include<iostream>
#include"binary_search_tree.h"


BinarySearchTree::BinarySearchTree():root(nullptr)
{
}


BinarySearchTree::BinarySearchTree(const BinarySearchTree& other): root(nullptr)
{
    if(!other.root) return;
    
    root = new Node(other.root->data);
    copyTree(other.root->left,root->left);
    copyTree(other.root->right,root->right);
}


void BinarySearchTree::copyTree(const Node* from_copy, Node*& to_copy)
{
    //preorder
    if(!from_copy) return;
    to_copy=new Node(from_copy->data);
    copyTree(from_copy->left, to_copy->left);
    copyTree(from_copy->right, to_copy->right);
}


BinarySearchTree::BinarySearchTree(BinarySearchTree&& other) 
{
    root=other.root;
    other.root=nullptr;
}


BinarySearchTree& BinarySearchTree::operator=(const BinarySearchTree& rhs)
{
    if(&rhs != this)
    {
        destroy(root);
        if(!rhs.root)
        {
            root = nullptr;
            return *this;
        }
        
        root = new Node(rhs.root->data);
        copyTree(rhs.root->left,root->left);
        copyTree(rhs.root->right,root->right);
    }

    return *this;
}


BinarySearchTree& BinarySearchTree::operator=(BinarySearchTree&& rhs)
{
    if(&rhs != this)
    {
        destroy(root);
        root=rhs.root;
        rhs.root=nullptr;
    }

    return *this;
}


BinarySearchTree::~BinarySearchTree() 
{
    destroy(root);
    root=nullptr;
}


void BinarySearchTree::destroy(Node* curr_del)
{
    if(!curr_del) return;

    destroy(curr_del->left);
    destroy(curr_del->right);

    delete curr_del;
    curr_del=nullptr;
}


Node* BinarySearchTree::getRoot()
{
    return root;
}


Node* BinarySearchTree::insert(Node* start, int val)
{
     if (!root) 
    {
        root= new Node(val);
        return root;
    }

    if (!start) return new Node(val);  // found position to insert

    else if (val < start->data) start->left = insert(start->left, val);  

    else if (val > start->data) start->right = insert(start->right, val); 
    
    return start;
}


void BinarySearchTree::inOrder(Node* start)
{
    if (!start) return;

    inOrder(start->left);
    std::cout<<start->data<<" -> ";
    inOrder(start->right);
}


Node* BinarySearchTree::search(int val)
{
    Node* curr=root;
    while (curr)
    {
        if(val < curr->data) curr=curr->left;

        else if (val > curr->data) curr=curr->right;

        else return curr; // val==curr->data, so we found node
    }

    return nullptr;
}


Node* BinarySearchTree::deleteNode(Node* start, int val)
{
    if(!start) return nullptr;

    else if(val < start->data) start->left=deleteNode(start->left,val);

    else if(val > start->data) start->right=deleteNode(start->right,val); 
    
    else
    {
        if(start->left && start->right)//two children
        {
            Node* min_node = findMin( start->right );
            start->data = min_node->data;
            start->right = deleteNode( start->right, start->data );
        }


       else //at most one children
       {
            Node* save_spot=start->left?start->left:start->right;
            delete start;
            return save_spot;
       } 

    }

    return start;
}


Node* BinarySearchTree::findMin(Node* start)
{
    if(!start) return nullptr;
    
    while(start->left) start=start->left;

    return start;
}
