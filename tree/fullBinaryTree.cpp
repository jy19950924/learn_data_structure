/**
 * 满二叉树
 * 判断二叉树是否是满二叉树
 * 思路： 记录每层节点个数，从而记录每层是否满足要求，如果不满足，则直接退出
 **/

#include <iostream>
#include "tree.h"
#include <queue>
#include <cmath>

bool isFullBinaryTree_non_recursion(TreeNode *root)
{
    using namespace std;

    queue<TreeNode *> que;
    que.push(root);
    TreeNode *tail = root, *nextTail;
    int height = 1;
    int count = 0;

    while (!que.empty())
    {
        count++;
        TreeNode *cur = que.front();
        que.pop();
        if (cur->left != nullptr)
        {
            que.push(cur->left);
            nextTail = cur->left;
        }

        if (cur->right != nullptr)
        {
            que.push(cur->right);
            nextTail = cur->right;
        }

        if (cur == tail)
        {
            if (count != pow(2, height - 1))
                return false;
            count = 0;
            height++;
            tail = nextTail;
        }
    }
    return true;
}

int main(int argc, char const *argv[])
{
    using namespace std;

    int data[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
    int len = sizeof(data) / sizeof(int);

    Tree *ptree = new Tree(data, len);
    cout << isFullBinaryTree_non_recursion(ptree->getRootNode()) << endl;
    return 0;
}
