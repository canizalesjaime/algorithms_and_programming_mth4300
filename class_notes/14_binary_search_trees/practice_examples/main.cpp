#include<iostream>
#include"binary_search_tree.h"


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
    bst.insert(bst.getRoot(),15);
    bst.insert(bst.getRoot(),10);
    bst.insert(bst.getRoot(),35);

    std::cout<<"LCA: "<<bst.lowestCommonAncestor(bst.getRoot(),35,80)->data;
    return 0;
}