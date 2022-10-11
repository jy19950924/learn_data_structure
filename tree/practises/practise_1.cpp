#include <iostream>
#include <queue>
#include "../tree.h"

// 题目要求：二叉树最大宽度。
/**
 *        1
 *      /   \
 *     2     3
 *    / \   /
 *   4   5 6
 *  / \
 * 7   8
 *
 * result 3  第三层有三个元素
 **/

int getTreeMaxWidth(TreeNode *root)
{
    using namespace std;

    queue<TreeNode *> que;
    que.push(root);
    TreeNode *tail = root, *nextTail = nullptr;
    size_t count = 0;
    int max = 0;

    while (!que.empty())
    {
        TreeNode *cur = que.front();
        que.pop();

        count++;
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

        if (tail == cur)
        {
            max = count > max ? count : max;
            count = 0;
            tail = nextTail;
            nextTail = nullptr;
        }
    }
    return max;
}

int main()
{
    using namespace std;

    int data[] = {0, 1, 2, 3, 4, 5, 6, -1, 7, 8};
    int len = sizeof(data) / sizeof(int);

    Tree *ptree = new Tree(data, len);
    cout << "tree Max width: " << getTreeMaxWidth(ptree->root) << endl;

    return 0;
}