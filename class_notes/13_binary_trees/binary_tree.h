#pragma once
#include<string>

class TreeNode 
{
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val): data(val), left(nullptr), right(nullptr){}
};


// Binary Tree class
class BinaryTree 
{
private:
    TreeNode* root;

    // Helper functions
    void insertRandom(TreeNode*& node, int val);
    void deleteLeftMost(TreeNode*& node);
    void deleteRightMost(TreeNode*& node);
    void inorder(TreeNode* node);
    void preorder(TreeNode* node);
    void postorder(TreeNode* node);
    void destroyTree(TreeNode* node);
    void printTree(TreeNode* node, int depth = 0, std::string prefix = "");
    void copyTree(const TreeNode* from_copy, TreeNode*& to_copy);

    
public:
    BinaryTree();
    BinaryTree(const BinaryTree& other);
    BinaryTree(BinaryTree&& other);
    BinaryTree& operator=(const BinaryTree& other);
    BinaryTree& operator=(BinaryTree&& other); 
    ~BinaryTree();

    void insert(int val);
    void deleteLeftMost();
    void deleteRightMost();
    void printInorder();
    void printPreorder();
    void printPostorder();
    void printTree();
};