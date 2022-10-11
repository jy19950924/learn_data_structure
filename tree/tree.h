#include <iostream>
#include <queue>
#include <stack>

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

class Tree
{
public:
    TreeNode *_mhead;
    TreeNode *root;
    Tree() : _mhead(nullptr), root(nullptr){};
    Tree(T *arr, size_t n);

    void drawTree();

    void preorderTraversal();
    void inorderTraversal();
    void postorderTraversal();

    ~Tree();
};
