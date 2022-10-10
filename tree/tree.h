#include <iostream>
#include <queue>

typedef int T;

class TreeNode
{
public:
    TreeNode *left;
    TreeNode *right;
    T val;

    TreeNode() : left(nullptr), right(nullptr){};

    TreeNode(T val) : left(nullptr), right(nullptr), val(val){};
    TreeNode(T val, TreeNode *left, TreeNode *right) : left(left), right(right), val(val){};
};

class Sentinel
{
public:
    TreeNode *next;
    Sentinel() : next(nullptr){};
};

class Tree
{
public:
    TreeNode *root;
    Tree() : root(nullptr){};
    Tree(T *arr, size_t n);

    ~Tree();
};