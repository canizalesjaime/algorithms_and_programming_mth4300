#include<iostream>
#include <cstdlib>   // For rand(), srand()
#include <ctime>     // For time()
#include"binary_tree.h"

using namespace std;


int main() 
{
    srand(time(0));
    BinaryTree tree;

    for (int i = 1; i <= 20; ++i)
        tree.insert(i);

    cout << "Inorder traversal: ";
    tree.printInorder();

    cout << "Preorder traversal: ";
    tree.printPreorder();

    cout << "Postorder traversal: ";
    tree.printPostorder();

    cout<<"(height, leftmost, # of nodes): "<<"("<<tree.getHeight()<<", "
    <<tree.findLeftmost()->data<<", "<<tree.getSize()<<")"<<endl;

    tree.printTree();

    return 0;
}