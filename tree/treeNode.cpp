#include "treeNode.h"

template <typename T>
class TreeNode
{
public:
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;
    T val;

    TreeNode() : left(nullptr), right(nullptr), parent(nullptr){};
    TreeNode(T val) : left(nullptr), right(nullptr), val(val), parent(nullptr){};
    TreeNode(T val, TreeNode<T> *left, TreeNode<T> *right) : left(left), right(right), val(val), parent(nullptr){};
    TreeNode(T val, TreeNode<T> *left, TreeNode<T> *right, TreeNode<T> *parent) : left(left), right(right), parent(parent), val(val){};
};