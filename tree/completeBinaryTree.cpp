/**
 * 完全二叉树
 * 判断一棵树是否是完全二叉树（递归和非递归）
 **/

#include <iostream>
#include "tree.h"
#include <queue>
bool isCompleteBinaryTree_non_recursion(TreeNode *root)
{
    using namespace std;
    bool leaf = false;

    queue<TreeNode *> que;
    que.push(root);
    TreeNode *cur = nullptr;
    while (!que.empty())
    {
        cur = que.front();
        que.pop();

        if (!leaf && (cur->left == nullptr || cur->right == nullptr))
        {
            return false;
        }
    }
}
