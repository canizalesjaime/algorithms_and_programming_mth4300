#include <iostream>
#include<vector>

#include"binary_tree.h"

using namespace std;

BinaryTree::BinaryTree():root(nullptr)
{
}


BinaryTree::BinaryTree(const BinaryTree& other): root(nullptr)
{
    if(!other.root) return;
    
    root = new TreeNode(other.root->data);
    copyTree(other.root->left,root->left);
    copyTree(other.root->right,root->right);
}


void BinaryTree::copyTree(const TreeNode* from_copy, TreeNode*& to_copy)
{
    //preorder
    if(!from_copy) return;
    to_copy=new TreeNode(from_copy->data);
    copyTree(from_copy->left, to_copy->left);
    copyTree(from_copy->right, to_copy->right);
}


BinaryTree::BinaryTree(BinaryTree&& other) 
{
    root=other.root;
    other.root=nullptr;
}


BinaryTree& BinaryTree::operator=(const BinaryTree& rhs)
{
    if(&rhs != this)
    {
        destroyTree(root);
        if(!rhs.root)
        {
            root = nullptr;
            return *this;
        }
        
        root = new TreeNode(rhs.root->data);
        copyTree(rhs.root->left,root->left);
        copyTree(rhs.root->right,root->right);
    }

    return *this;
}


BinaryTree& BinaryTree::operator=(BinaryTree&& rhs)
{
    if(&rhs != this)
    {
        destroyTree(root);
        root=rhs.root;
        rhs.root=nullptr;
    }

    return *this;
}


BinaryTree::~BinaryTree() 
{
    destroyTree(root);
    root=nullptr;
}


void BinaryTree::destroyTree(TreeNode* node) 
{
    //post order
    if (node == nullptr) return;
    destroyTree(node->left);
    destroyTree(node->right);
    delete node;
}

void BinaryTree::insertRandom(TreeNode*& node, int val)
{
    if (node == nullptr)
        node = new TreeNode(val);

    else if (rand() % 2 == 0)
        insertRandom(node->left, val);
    
    else insertRandom(node->right, val);
}


void BinaryTree::deleteLeftMost(TreeNode*& node)
{
    if(!node) return;
    
    else if(node->left)    deleteLeftMost(node->left);

    else if (node->right)  deleteLeftMost(node->right);

    else
    {
        delete node;
        node = nullptr;
    }
}


void BinaryTree::deleteRightMost(TreeNode*& node)
{
    if(!node) return;
    
    else if(node->right)    deleteRightMost(node->right);

    else if (node->left)  deleteRightMost(node->left);

    else
    {
        delete node;
        node = nullptr;
    }
}


void BinaryTree::inorder(TreeNode* node) 
{
    if (node == nullptr) return;
    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}


void BinaryTree::preorder(TreeNode* node) 
{
    if (node == nullptr) return;
    cout << node->data << " ";
    preorder(node->left);
    preorder(node->right);
}


void BinaryTree::postorder(TreeNode* node) 
{
    if (node == nullptr) return;
    postorder(node->left);
    postorder(node->right);
    cout << node->data << " ";
}


void BinaryTree::printTree(TreeNode* node, int depth, string prefix) 
{
    if (!node) return;

    if (node->right)
        printTree(node->right, depth + 1, prefix + "        ");

    cout << prefix;

    if (depth > 0) {
        cout << (prefix.back() == '/' ? "/" : "\\") << "──── ";
    }

    cout << node->data << endl;

    if (node->left)
        printTree(node->left, depth + 1, prefix + "        ");
}


int BinaryTree::getHeight(TreeNode* node)
{
    if(node==nullptr) return -1;

    else return max(getHeight(node->left),getHeight(node->right))+1;
}


TreeNode* BinaryTree::findLeftmost(TreeNode* node)
{
    if(node == nullptr || node->left == nullptr) return node;

    return findLeftmost(node->left);   
}


int BinaryTree::getSize(TreeNode* node)
{
    if(node==nullptr) return 0;

    return getSize(node->left)+getSize(node->right)+1;
}


// wrappers
///////////////////////////////////////////////////////////////////////////////
void BinaryTree::insert(int val) 
{
    insertRandom(root, val);
}


void BinaryTree::deleteLeftMost()
{
    deleteLeftMost(root);
}


void BinaryTree::deleteRightMost()
{
    deleteRightMost(root);
}


void BinaryTree::printInorder() 
{
    inorder(root);
    cout << endl;
}


void BinaryTree::printPreorder() 
{
    preorder(root);
    cout << endl;
}


void BinaryTree::printPostorder() 
{
    postorder(root);
    cout << endl;
}


void BinaryTree::printTree() 
{
    printTree(root);
}


int BinaryTree::getHeight()
{
    return getHeight(root);
}


TreeNode* BinaryTree::findLeftmost()
{
    return findLeftmost(root);
}


int BinaryTree::getSize()
{
    return getSize(root);
}
