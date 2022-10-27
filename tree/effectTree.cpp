#include "./effectTree.h"

EffectTree::EffectTree(T arr[], size_t n)
{
    TreeNode *nodes = new TreeNode[n];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == emptyFlag)
            continue;
        int leftIndex = 2 * i + 1;
        int rightIndex = 2 * i + 2;
        nodes[i].val = arr[i];
        nodes[i].parent = i == 0 ? (&nodes[0]) : &nodes[(i - 1) / 2];
        nodes[i].left = leftIndex < n && arr[leftIndex] != emptyFlag ? (nodes + leftIndex) : nullptr;
        nodes[i].right = rightIndex < n && arr[rightIndex] != emptyFlag ? (nodes + rightIndex) : nullptr;
    }
    this->root = nodes;
}
