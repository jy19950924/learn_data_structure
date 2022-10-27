#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <queue>
#include <stack>
#include "./drawTree.h"

template <typename T>
class TreeNode
{
public:
    TreeNode<T> *left;
    TreeNode<T> *right;
    TreeNode<T> *parent;
    T val;

    TreeNode() : left(nullptr), right(nullptr), parent(nullptr){};
    TreeNode(T val) : left(nullptr), right(nullptr), val(val), parent(nullptr){};
    TreeNode(T val, TreeNode<T> *left, TreeNode<T> *right) : left(left), right(right), val(val), parent(nullptr){};
    TreeNode(T val, TreeNode<T> *left, TreeNode<T> *right, TreeNode<T> *parent) : left(left), right(right), parent(parent), val(val){};
};

template <typename T>
class Tree
{
    TreeNode<T> *root;

public:
    Tree() : root(nullptr){};
    Tree(T arr[], size_t n);

    TreeNode<T> *getRootNode()
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
