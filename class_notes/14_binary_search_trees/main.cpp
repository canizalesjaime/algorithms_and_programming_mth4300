#include<iostream>
#include"binary_search_tree.h"
#include<queue>

void BFS_Levels(BinarySearchTree& t)
{
    std::queue<Node*> q;
    if(t.getRoot()) q.push(t.getRoot());    
    int nodes_per_level = 1;

    while(!q.empty())
    {
        for(int i=0;i<nodes_per_level;i++)
        {
            Node* n = q.front();
            q.pop();
            std::cout<<n->data<<"->";
            if(n->left)     q.push(n->left);
            if(n->right)    q.push(n->right);
        }
        std::cout<<std::endl;
        nodes_per_level=q.size();
    }
}


void BFS(BinarySearchTree& t)
{
    std::queue<Node*> q;
    if(t.getRoot()) q.push(t.getRoot());    
    
    while(!q.empty())
    {
        Node* n = q.front();
        q.pop();
        std::cout<<n->data<<"->";
        if(n->left)     q.push(n->left);
        if(n->right)    q.push(n->right);
    }
    std::cout<<std::endl;
}


int main()
{
    BinarySearchTree bst;
    bst.insert(bst.getRoot(),50);
    bst.insert(bst.getRoot(),30);
    bst.insert(bst.getRoot(),70);
    bst.insert(bst.getRoot(),20);
    bst.insert(bst.getRoot(),40);
    bst.insert(bst.getRoot(),60);
    bst.insert(bst.getRoot(),80);

    bst.inOrder(bst.getRoot());
    std::cout<<std::endl;
    
    bst.deleteNode(bst.getRoot(),70);
    bst.inOrder(bst.getRoot());
    std::cout<<std::endl;

    bst.insert(bst.getRoot(),30);
    bst.inOrder(bst.getRoot());
    std::cout<<std::endl;
    

    bst.~BinarySearchTree();
    bst.inOrder(bst.getRoot());
    std::cout<<std::endl;
    int key=40;
    if (bst.search(key)) 
        std::cout << "Value " << key << " found in the tree." << std::endl;
    
    else std::cout << "Value " << key << " not found in the tree." << std::endl;

    return 0;
}