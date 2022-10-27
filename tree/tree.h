#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <queue>
#include <stack>
#include "./drawTree.h"
typedef int T;

class TreeNode
{
public:
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;
    T val;

    TreeNode() : left(nullptr), right(nullptr), parent(nullptr){};
    TreeNode(T val) : left(nullptr), right(nullptr), val(val), parent(nullptr){};
    TreeNode(T val, TreeNode *left, TreeNode *right) : left(left), right(right), val(val), parent(nullptr){};
    TreeNode(T val, TreeNode *left, TreeNode *right, TreeNode *parent) : left(left), right(right), parent(parent), val(val){};
};

class Tree
{
protected:
    TreeNode *root;

public:
    Tree() : root(nullptr){};
    Tree(T arr[], size_t n);

    TreeNode *getRootNode()
    {
        return this->root;
    }
    void drawTree();
    void preorderTraversal();
    void inorderTraversal();
    void postorderTraversal();

    void inorderSuccessor();

    ~Tree();
};

#endif
