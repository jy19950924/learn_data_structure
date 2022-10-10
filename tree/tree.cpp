#include "tree.h"

Tree::Tree(T *arr, size_t n)
{
    using namespace std;

    TreeNode *nodes = new TreeNode[n];
    for (int i = 1; i < n; i++)
    {
        nodes[i].val = arr[i];
        nodes[i].left = (nodes + 2 * i);
        nodes[i].right = (nodes + 2 * i + 1);
    }
    this->root = &nodes[1];
    delete nodes;
}